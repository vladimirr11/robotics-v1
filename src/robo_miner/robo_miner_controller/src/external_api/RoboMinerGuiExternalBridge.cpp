// Corresponding header
#include "robo_miner_controller/external_api/RoboMinerGuiExternalBridge.h"

// C++ System headers
#include <algorithm>
#include <thread>

// Other libraries headers
#include "robo_miner_common/defines/RoboMinerTopics.h"
#include "utils/Log.h"

static constexpr const char* NODE_NAME = "RoboMinerGuiExternalBridge";
static constexpr int32_t LEFT_RIGHT_ROT_DISTANCE = 2;
static constexpr int32_t INIT_MAP_DIMENSION = 1;

RoboMinerGuiExternalBridge::RoboMinerGuiExternalBridge() : Node(NODE_NAME) {}

ErrorCode RoboMinerGuiExternalBridge::init(const RoboMinerControllerRos2Params& initParams) {
    using namespace std::placeholders;
    constexpr auto queue_size = 10;
    const rclcpp::QoS qos(queue_size);

    _userAuthenticatePublisher = create_publisher<UserAuthenticate>(USER_AUTHENTICATE_TOPIC, qos);

    InitiateUserAuthenticateCb user_auth_init_cb =
        std::bind(&RoboMinerGuiExternalBridge::_publishUserAuthenticate, this, _1);

    user_auth_init_cb(initParams.userData);

    rclcpp::SubscriptionOptions subsription_options;
    subsription_options.callback_group = _subscriberCallbackGroup;

    rclcpp::PublisherOptions publisher_options;
    publisher_options.callback_group = _publishersCallbackGroup;

    _initialRobotPosClient = create_client<QueryInitialRobotPosition>(
        QUERY_INITIAL_ROBOT_POSITION_SERVICE, rmw_qos_profile_services_default,
        _publishersCallbackGroup);

    _robotMoveClient = create_client<RobotMove>(
        ROBOT_MOVE_SERVICE, rmw_qos_profile_services_default, _publishersCallbackGroup);

    _fieldMapValidateClient = create_client<FieldMapValidate>(
        FIELD_MAP_VALIDATE_SERVICE, rmw_qos_profile_services_default, _publishersCallbackGroup);

    return ErrorCode::SUCCESS;
}

ErrorCode RoboMinerGuiExternalBridge::run() {
    auto init_crystal_type = _queryInitRobotPos();

    std::shared_ptr<RobotMove::Request> robot_rotate_req = std::make_shared<RobotMove::Request>();
    auto robotate_rotate_req = _rotateRobot(ROTATE_LEFT);

    _revealMap(init_crystal_type, robotate_rotate_req);

    return ErrorCode::SUCCESS;
}

void RoboMinerGuiExternalBridge::_publishUserAuthenticate(const UserData& data) {
    UserAuthenticate msg;
    msg.user = data.user;
    msg.commit_sha = data.commitSha;
    msg.repository = data.repository;
    _userAuthenticatePublisher->publish(msg);
}

uint8_t RoboMinerGuiExternalBridge::_queryInitRobotPos() const {
    using namespace std::chrono_literals;
    std::shared_ptr<QueryInitialRobotPosition::Request> robot_init_pos_req =
        std::make_shared<QueryInitialRobotPosition::Request>();

    while (!_initialRobotPosClient->wait_for_service(1s)) {
        LOGY("service not available, waiting again ...");
    }

    auto robot_init_pos_result = _initialRobotPosClient->async_send_request(robot_init_pos_req);
    const std::shared_ptr<QueryInitialRobotPosition::Response> robot_init_pos_response =
        robot_init_pos_result.get();

    if (!robot_init_pos_response->robot_position_response.success) {
        LOGERR("Error, robot initial position response failed");
        return EXIT_FAILURE;
    }

    return robot_init_pos_response->robot_initial_tile;
}

bool RoboMinerGuiExternalBridge::_validateMap(const uint32_t rows, const uint32_t cols,
                                              const std::vector<uint8_t>& data) const {
    UInt8MultiArray field_map;
    field_map.rows = rows;
    field_map.cols = cols;
    field_map.data = data;

    std::shared_ptr<FieldMapValidate::Request> map_validate_req =
        std::make_shared<FieldMapValidate::Request>();

    map_validate_req->set__field_map(field_map);

    auto map_validate_result = _fieldMapValidateClient->async_send_request(map_validate_req);
    const std::shared_ptr<FieldMapValidate::Response> map_validate_response =
        map_validate_result.get();

    return map_validate_response->success;
}

MapDimension RoboMinerGuiExternalBridge::_calcMapDimensions(
    const std::set<FieldPos>& fieldPosSet) const {
    FieldPos top_row_dist = *fieldPosSet.begin();
    FieldPos bottom_row_dist = *std::prev(fieldPosSet.end());

    uint32_t rows_dim = std::abs(top_row_dist.row) + std::abs(bottom_row_dist.row);
    auto [left_col, right_col] = _findColumnsDistance(fieldPosSet);
    uint32_t cols_dim = left_col + right_col;

    MapDimension map_dim{rows_dim + INIT_MAP_DIMENSION,
                         cols_dim + INIT_MAP_DIMENSION,
                         static_cast<uint32_t>(std::abs(top_row_dist.row)),
                         static_cast<uint32_t>(bottom_row_dist.row),
                         left_col,
                         right_col};

    return map_dim;
}

std::pair<uint32_t, uint32_t> RoboMinerGuiExternalBridge::_findColumnsDistance(
    const std::set<FieldPos>& fieldPosSet) const {
    int32_t left_col{};
    int32_t right_col{};
    for (auto it = fieldPosSet.cbegin(); it != fieldPosSet.cend(); it++) {
        if ((*it).col < left_col)
            left_col = (*it).col;
        if ((*it).col > right_col)
            right_col = (*it).col;
    }

    return std::make_pair(static_cast<uint32_t>(std::abs(left_col)),
                          static_cast<uint32_t>(right_col));
}

void RoboMinerGuiExternalBridge::_revealMap(const uint8_t initPosCrystalType, RobotMoveResponse moveDirPtr) {
    std::stack<RobotMoveResponse> robot_move_ptr_stack;
    robot_move_ptr_stack.push(moveDirPtr);

    FieldPos start_pos{0, 0};
    std::stack<FieldPos> field_pos_stack;
    field_pos_stack.push(start_pos);

    std::set<FieldPos> field_pos_set;
    field_pos_set.insert(start_pos);

    MapReconstructor map_reconstructor;
    MapDimension init_map_dim;
    map_reconstructor.update_map(start_pos, initPosCrystalType, init_map_dim);
    while (!robot_move_ptr_stack.empty()) {
        auto curr_move_dir_response = robot_move_ptr_stack.top();
        robot_move_ptr_stack.pop();

        auto curr_pos = field_pos_stack.top();
        field_pos_stack.pop();

        MapDimension map_dim;
        if (_isValidPosition(curr_move_dir_response, FORWARD_TILE)) {
            auto next_crystal_type =
                curr_move_dir_response->robot_position_response.surrounding_tiles[FORWARD_TILE];
            auto robot_move_forw_req = std::make_shared<RobotMove::Request>();
            curr_move_dir_response = _moveRobotForward(robot_move_forw_req);
            _setVisitedTile(curr_pos, curr_move_dir_response);
            if (field_pos_set.find(curr_pos) == field_pos_set.end()) {
                field_pos_set.insert(curr_pos);
                map_dim = _calcMapDimensions(field_pos_set);
                map_reconstructor.update_map(curr_pos, next_crystal_type, map_dim);
                map_reconstructor.reconstruct();
            }
        }

        if (_validateMap(map_dim.rows, map_dim.cols, map_reconstructor.get_data())) {
            return;
        }

        _feedRobotWithCristals(curr_move_dir_response, curr_pos, robot_move_ptr_stack,
                               field_pos_stack, field_pos_set);
    }
}

void RoboMinerGuiExternalBridge::_feedRobotWithCristals(
    RobotMoveResponse& moveDirPtr, FieldPos& currPos,
    std::stack<RobotMoveResponse>& fieldRobotMoveStack, std::stack<FieldPos>& fieldPosStack,
    std::set<FieldPos>& fieldPosSet) {
    bool hasRobotRotLeft = false;
    bool hasRobotRotLeftCenter = false;
    bool hasRobotRotRight = false;

    FieldPos left_tile_pos =
        _findFuturePos(currPos, LEFT_TILE, moveDirPtr->robot_position_response.robot_dir);
    FieldPos right_tile_pos =
        _findFuturePos(currPos, RIGHT_TILE, moveDirPtr->robot_position_response.robot_dir);

    if (_isValidPosition(moveDirPtr, LEFT_TILE) &&
        fieldPosSet.find(left_tile_pos) == fieldPosSet.end()) {
        moveDirPtr = _rotateRobot(ROTATE_LEFT);
        fieldRobotMoveStack.push(moveDirPtr);
        fieldPosStack.push(currPos);
        hasRobotRotLeft = true;
    }

    else if (_isValidPosition(moveDirPtr, FORWARD_TILE)) {
        if (hasRobotRotLeft) {
            moveDirPtr = _rotateRobot(ROTATE_RIGHT);
            fieldRobotMoveStack.push(moveDirPtr);
            fieldPosStack.push(currPos);
            hasRobotRotLeftCenter = true;
        } else {
            fieldRobotMoveStack.push(moveDirPtr);
            fieldPosStack.push(currPos);
            hasRobotRotLeftCenter = true;
        }
    }

    else if (_isValidPosition(moveDirPtr, RIGHT_TILE) &&
             fieldPosSet.find(right_tile_pos) == fieldPosSet.end()) {
        if (hasRobotRotLeft && hasRobotRotLeftCenter) {
            moveDirPtr = _rotateRobot(ROTATE_RIGHT);
            fieldRobotMoveStack.push(moveDirPtr);
            fieldPosStack.push(currPos);
            hasRobotRotRight = true;
        } else if (hasRobotRotLeft) {
            for (uint8_t j = 0; j < LEFT_RIGHT_ROT_DISTANCE; ++j)
                moveDirPtr = _rotateRobot(ROTATE_RIGHT);
            fieldRobotMoveStack.push(moveDirPtr);
            fieldPosStack.push(currPos);
            hasRobotRotRight = true;
        } else {
            moveDirPtr = _rotateRobot(ROTATE_RIGHT);
            fieldRobotMoveStack.push(moveDirPtr);
            fieldPosStack.push(currPos);
            hasRobotRotRight = true;
        }
    }

    if (!hasRobotRotLeft && !hasRobotRotLeftCenter && !hasRobotRotRight) {
        _backtrackRobot(moveDirPtr, currPos, fieldRobotMoveStack, fieldPosStack, fieldPosSet);
    }
}

void RoboMinerGuiExternalBridge::_backtrackRobot(RobotMoveResponse& moveDirPtr, FieldPos& currPos,
                                                 std::stack<RobotMoveResponse>& fieldRobotMoveStack,
                                                 std::stack<FieldPos>& fieldPosStack,
                                                 const std::set<FieldPos>& fieldPosSet) const {
    if (!_isValidPosition(moveDirPtr, FORWARD_TILE) && !_isValidPosition(moveDirPtr, RIGHT_TILE)) {
        moveDirPtr = _rotateRobot(ROTATE_LEFT);
        fieldRobotMoveStack.push(moveDirPtr);
        fieldPosStack.push(currPos);
        return;
    }

    for (int32_t i = 0; i < LEFT_RIGHT_ROT_DISTANCE; ++i) moveDirPtr = _rotateRobot(ROTATE_RIGHT);

    FieldPos left_tile_pos =
        _findFuturePos(currPos, LEFT_TILE, moveDirPtr->robot_position_response.robot_dir);
    FieldPos forw_tile_pos =
        _findFuturePos(currPos, FORWARD_TILE, moveDirPtr->robot_position_response.robot_dir);
    FieldPos right_tile_pos =
        _findFuturePos(currPos, RIGHT_TILE, moveDirPtr->robot_position_response.robot_dir);

    do {
        if (fieldPosSet.find(left_tile_pos) == fieldPosSet.end() &&
            _isValidPosition(moveDirPtr, LEFT_TILE)) {
            moveDirPtr = _rotateRobot(ROTATE_LEFT);
            break;
        } else if (fieldPosSet.find(right_tile_pos) == fieldPosSet.end() &&
                   _isValidPosition(moveDirPtr, RIGHT_TILE)) {
            moveDirPtr = _rotateRobot(ROTATE_RIGHT);
            break;
        } else if (fieldPosSet.find(forw_tile_pos) == fieldPosSet.end() &&
                   _isValidPosition(moveDirPtr, FORWARD_TILE)) {
            break;
        } else if (fieldPosSet.find(forw_tile_pos) == fieldPosSet.end() &&
                   !_isValidPosition(moveDirPtr, FORWARD_TILE)) {
            moveDirPtr = _rotateRobot(ROTATE_LEFT);
            break;
        } else {
            auto robot_move_forw_req = std::make_shared<RobotMove::Request>();
            moveDirPtr = _moveRobotForward(robot_move_forw_req);
            _setVisitedTile(currPos, moveDirPtr);

            left_tile_pos =
                _findFuturePos(currPos, LEFT_TILE, moveDirPtr->robot_position_response.robot_dir);
            forw_tile_pos = _findFuturePos(currPos, FORWARD_TILE,
                                           moveDirPtr->robot_position_response.robot_dir);
            right_tile_pos =
                _findFuturePos(currPos, RIGHT_TILE, moveDirPtr->robot_position_response.robot_dir);
        }
    } while (true);

    fieldRobotMoveStack.push(moveDirPtr);
    fieldPosStack.push(currPos);
}

bool RoboMinerGuiExternalBridge::_isValidPosition(const RobotMoveResponse& moveDirPtr,
                                                  const SurroundingTile tileType) const {
    if (moveDirPtr->robot_position_response.surrounding_tiles[tileType] != OBSTACLE &&
        moveDirPtr->robot_position_response.surrounding_tiles[tileType] != FIELD_BORDER)
        return true;
    return false;
}

typename RoboMinerGuiExternalBridge::RobotMoveResponse RoboMinerGuiExternalBridge::_rotateRobot(
    const RobotRotateDir rotateDir) const {
    std::shared_ptr<RobotMove::Request> robot_rotate_req = std::make_shared<RobotMove::Request>();
    robot_rotate_req->robot_move_type.set__move_type(rotateDir);
    const auto robot_rotate_result = _robotMoveClient->async_send_request(robot_rotate_req);
    std::shared_ptr<RobotMove::Response> robot_rotate_response = robot_rotate_result.get();
    return robot_rotate_response;
}

typename RoboMinerGuiExternalBridge::RobotMoveResponse
RoboMinerGuiExternalBridge::_moveRobotForward(const RobotMoveRequest& moveReq) const {
    auto robot_rotate_result = _robotMoveClient->async_send_request(moveReq);
    std::shared_ptr<RobotMove::Response> robot_rotate_response = robot_rotate_result.get();
    return robot_rotate_response;
}

void RoboMinerGuiExternalBridge::_setVisitedTile(FieldPos& visitedPos,
                                                 const RobotMoveResponse& moveDirPtr) const {
    if (moveDirPtr->robot_position_response.robot_dir == DIRECTION_UP) {
        visitedPos.row--;
    } else if (moveDirPtr->robot_position_response.robot_dir == DIRECTION_RIGHT) {
        visitedPos.col++;
    } else if (moveDirPtr->robot_position_response.robot_dir == DIRECTION_DOWN) {
        visitedPos.row++;
    } else {
        visitedPos.col--;
    }
}

FieldPos RoboMinerGuiExternalBridge::_findFuturePos(FieldPos currPos, const int32_t tileIdx,
                                                    const int32_t direction) const {
    switch (direction) {
        case DIRECTION_UP: {
            if (tileIdx == LEFT_TILE)
                currPos.col--;
            else if (tileIdx == FORWARD_TILE)
                currPos.row--;
            else if (tileIdx == RIGHT_TILE)
                currPos.col++;
        } break;
        case DIRECTION_RIGHT: {
            if (tileIdx == LEFT_TILE)
                currPos.row--;
            else if (tileIdx == FORWARD_TILE)
                currPos.col++;
            else if (tileIdx == RIGHT_TILE)
                currPos.row++;
        } break;
        case DIRECTION_DOWN: {
            if (tileIdx == LEFT_TILE)
                currPos.col++;
            else if (tileIdx == FORWARD_TILE)
                currPos.row++;
            else if (tileIdx == RIGHT_TILE)
                currPos.col--;
        } break;
        case DIRECTION_LEFT: {
            if (tileIdx == LEFT_TILE)
                currPos.row++;
            else if (tileIdx == FORWARD_TILE)
                currPos.col--;
            else if (tileIdx == RIGHT_TILE)
                currPos.row--;
        } break;
        default:
            LOGY("Received unsupported direction");
            break;
    }

    return currPos;
}