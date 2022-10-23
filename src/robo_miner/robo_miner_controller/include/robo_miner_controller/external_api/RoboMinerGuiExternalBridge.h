#ifndef ROBOMINERGUIEXTERNALBRIDGE_H
#define ROBOMINERGUIEXTERNALBRIDGE_H

// C++ System headers
#include <set>
#include <stack>
#include <vector>

// Other libraries headers
#include <rclcpp/client.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>
#include <std_msgs/msg/empty.hpp>
#include <std_msgs/msg/string.hpp>
#include "game_engine/defines/ActionEventDefines.h"

// Own components headers
#include "include/robo_miner_controller/defines/CommonDefines.h"
#include "include/robo_miner_controller/helpers/MapReconstructor.h"
#include "robo_common/defines/RoboCommonDefines.h"
#include "robo_miner_controller/external_api/RoboMinerControllerRos2ParamProvider.h"
#include "robo_miner_controller/helpers/RoboMinerHelperDefines.h"
#include "robo_miner_interfaces/msg/robot_position_response.hpp"
#include "robo_miner_interfaces/msg/user_authenticate.hpp"
#include "robo_miner_interfaces/srv/activate_mining_validate.hpp"
#include "robo_miner_interfaces/srv/field_map_validate.hpp"
#include "robo_miner_interfaces/srv/longest_sequence_validate.hpp"
#include "robo_miner_interfaces/srv/query_initial_robot_position.hpp"
#include "robo_miner_interfaces/srv/robot_move.hpp"
#include "utils/ErrorCode.h"

class RoboMinerGuiExternalBridge : public rclcpp::Node {
public:
    RoboMinerGuiExternalBridge();

    ErrorCode init(const RoboMinerControllerRos2Params& initParams);

    ErrorCode run();

private:
    using InitialRobotPosPtr =
        std::shared_ptr<robo_miner_interfaces::srv::QueryInitialRobotPosition::Response>;

    using RobotMoveResponse = std::shared_ptr<robo_miner_interfaces::srv::RobotMove::Response>;
    using RobotMoveRequest = std::shared_ptr<robo_miner_interfaces::srv::RobotMove::Request>;

    void _publishUserAuthenticate(const UserData& data);

    void _revealMap(const uint8_t initPosCrystalType, RobotMoveResponse moveDirPtr);

    uint8_t _queryInitRobotPos() const;

    bool _validateMap(const uint32_t rows, const uint32_t cols,
                      const std::vector<uint8_t>& data) const;

    MapDimension _calcMapDimensions(const std::set<FieldPos>& fieldPosSet) const;

    std::pair<uint32_t, uint32_t> _findColumnsDistance(const std::set<FieldPos>& fieldPosSet) const;

    RobotMoveResponse _rotateRobot(const RobotRotateDir rotateDir) const;

    bool _isValidPosition(const RobotMoveResponse& moveDirPtr,
                          const SurroundingTile tileType) const;

    RobotMoveResponse _moveRobotForward(const RobotMoveRequest& moveReq) const;

    void _setVisitedTile(FieldPos& visitedPos, const RobotMoveResponse& moveDirPtr) const;

    FieldPos _findFuturePos(FieldPos currPos, const int32_t tileIdx, const int32_t dir) const;

    void _feedRobotWithCristals(RobotMoveResponse& moveDirPtr, FieldPos& currPos,
                                std::stack<RobotMoveResponse>& fieldRobotMoveResStack,
                                std::stack<FieldPos>& fieldPosStack,
                                std::set<FieldPos>& fieldPosSet);

    void _backtrackRobot(RobotMoveResponse& moveDirPtr, FieldPos& currPos,
                        std::stack<RobotMoveResponse>& fieldRobotMoveResStack,
                        std::stack<FieldPos>& fieldPosStack,
                        const std::set<FieldPos>& fieldPosSet) const;

    bool _shouldRotate(const RobotMoveResponse& moveDirPtr, const FieldPos& visitedPos,
                       const std::set<FieldPos>& fieldPosSet) const;

private:
    using Empty = std_msgs::msg::Empty;
    using String = std_msgs::msg::String;
    using UserAuthenticate = robo_miner_interfaces::msg::UserAuthenticate;
    using FieldPoint = robo_miner_interfaces::msg::FieldPoint;
    using UInt8MultiArray = robo_miner_interfaces::msg::UInt8MultiArray;
    using RobotMove = robo_miner_interfaces::srv::RobotMove;
    using QueryInitialRobotPosition = robo_miner_interfaces::srv::QueryInitialRobotPosition;
    using FieldMapValidate = robo_miner_interfaces::srv::FieldMapValidate;
    using LongestSequenceValidate = robo_miner_interfaces::srv::LongestSequenceValidate;
    using ActivateMiningValidate = robo_miner_interfaces::srv::ActivateMiningValidate;

private:
    rclcpp::Client<QueryInitialRobotPosition>::SharedPtr _initialRobotPosClient;
    rclcpp::Client<RobotMove>::SharedPtr _robotMoveClient;
    rclcpp::Client<FieldMapValidate>::SharedPtr _fieldMapValidateClient;
    rclcpp::Client<LongestSequenceValidate>::SharedPtr _longestSequenceValidateClient;
    rclcpp::Client<ActivateMiningValidate>::SharedPtr _activateMiningValidateClient;

    rclcpp::Publisher<UserAuthenticate>::SharedPtr _userAuthenticatePublisher;
    rclcpp::Publisher<Empty>::SharedPtr _toggleHelpPagePublisher;
    rclcpp::Publisher<Empty>::SharedPtr _toggleDebugInfoPublisher;

    rclcpp::Subscription<Empty>::SharedPtr _shutdownControllerSubscriber;
    rclcpp::Subscription<Empty>::SharedPtr _fieldMapRevealedSubscriber;

    // Create different callbacks groups for publishers and subscribers
    // so they can be executed in parallel
    const rclcpp::CallbackGroup::SharedPtr _subscriberCallbackGroup =
        create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    const rclcpp::CallbackGroup::SharedPtr _publishersCallbackGroup =
        create_callback_group(rclcpp::CallbackGroupType::Reentrant);
};

#endif  // !ROBOMINERGUIEXTERNALBRIDGE_H
