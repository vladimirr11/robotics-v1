// Corresponding header
#include "include/robo_miner_controller/external_api/LongestCrystalPathValidator.h"

static constexpr const char* N_NAME = "LongestCrystalSequenceValidator";

LongestCrystalPathValidator::LongestCrystalPathValidator() : Node(N_NAME) {}

ErrorCode LongestCrystalPathValidator::init() {
    constexpr auto queue_size = 10;
    const rclcpp::QoS qos(queue_size);

    rclcpp::PublisherOptions publisher_options;
    publisher_options.callback_group = _publishersCallbackGroup;

    _longestSequenceValidateClient = create_client<LongestSequenceValidate>(
        LONGEST_SEQUENCE_VALIDATE_SERVICE, rmw_qos_profile_services_default,
        _publishersCallbackGroup);

    return ErrorCode::SUCCESS;
}

void LongestCrystalPathValidator::collect_crystals(
    const std::vector<std::pair<uint8_t, FieldPos>>& crystalsPosVec) {
    for (const auto [crystal_type, position] : crystalsPosVec) {
        _crystalsMap[crystal_type].push_back(position);
    }
}

void LongestCrystalPathValidator::validate() const {
    const auto longest_crystal_path = _get_longest_crystal_path();
    const auto field_point_msg_vec = _prepare_msg(longest_crystal_path);

    std::shared_ptr<LongestSequenceValidate::Request> longest_path_req =
        std::make_shared<LongestSequenceValidate::Request>();
    longest_path_req->set__sequence_points(field_point_msg_vec);

    using ServiceResponseFuture = rclcpp::Client<LongestSequenceValidate>::SharedFuture;
    auto response_received_callback = [this]([[maybe_unused]] ServiceResponseFuture future) {
        LOGY("ServiceResponseFuture called");
        // LOGY("SUCCESS = [%d]", future.get()->success);
    };

    auto longest_path_result = _longestSequenceValidateClient->async_send_request(
        longest_path_req, response_received_callback);

    response_received_callback(longest_path_result);
}

FieldPos LongestCrystalPathValidator::get_start_pos() const {
    auto longest_crystal_path = _get_longest_crystal_path();
    std::sort(longest_crystal_path.begin(), longest_crystal_path.end(),
              [](const FieldPos& p1, const FieldPos& p2) {
                  if (p1.col == p2.col) {
                      return p1.row < p2.row;
                  }
                  return p1.col < p2.col;
              });

    return *longest_crystal_path.begin();
}

uint8_t LongestCrystalPathValidator::get_target_crystal_type() const {
    using pair_type = std::pair<uint8_t, std::vector<FieldPos>>;
    const auto longets_path = *std::max_element(_crystalsMap.begin(), _crystalsMap.end(),
                                                [](const pair_type& p1, const pair_type& p2) {
                                                    return p1.second.size() < p2.second.size();
                                                });
    return longets_path.first;
}

std::vector<FieldPos> LongestCrystalPathValidator::_get_longest_crystal_path() const {
    using pair_type = std::pair<uint8_t, std::vector<FieldPos>>;
    const auto longets_path = *std::max_element(_crystalsMap.begin(), _crystalsMap.end(),
                                                [](const pair_type& p1, const pair_type& p2) {
                                                    return p1.second.size() < p2.second.size();
                                                });
    return longets_path.second;
}

std::vector<typename LongestCrystalPathValidator::FieldPoint>
LongestCrystalPathValidator::_prepare_msg(const std::vector<FieldPos>& longestCrystalPath) const {
    std::vector<FieldPoint> msg_vec(longestCrystalPath.size());
    for (int32_t i = 0; const FieldPos& f_pos : longestCrystalPath) {
        FieldPoint f_point;
        f_point.row = f_pos.row;
        f_point.col = f_pos.col;
        msg_vec[i] = f_point;
        i++;
    }

    return msg_vec;
}
