#ifndef LONGESTCRYSTALSEQUENCEVALIDATOR_H
#define LONGESTCRYSTALSEQUENCEVALIDATOR_H

// C++ System headers
#include <algorithm>
#include <map>
#include <vector>

// Other libraries headers
#include <rclcpp/client.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>

// Own components headers
#include "include/robo_miner_controller/defines/CommonDefines.h"
#include "robo_common/layout/field/FieldPos.h"
#include "robo_miner_common/defines/RoboMinerTopics.h"
#include "robo_miner_interfaces/msg/robot_position_response.hpp"
#include "robo_miner_interfaces/srv/longest_sequence_validate.hpp"
#include "robo_miner_interfaces/srv/robot_move.hpp"
#include "utils/ErrorCode.h"
#include "utils/Log.h"

class LongestCrystalPathValidator : public rclcpp::Node {
public:
    LongestCrystalPathValidator();

    ErrorCode init();

    void collect_crystals(const std::vector<std::pair<uint8_t, FieldPos>>& crystalsPosVec);

    void validate() const;

    FieldPos get_start_pos() const;

    uint8_t get_target_crystal_type() const;

private:
    using FieldPoint = robo_miner_interfaces::msg::FieldPoint;

    std::vector<FieldPos> _get_longest_crystal_path() const;

    std::vector<FieldPoint> _prepare_msg(const std::vector<FieldPos>& longestCrystalPath) const;

private:
    using RobotMove = robo_miner_interfaces::srv::RobotMove;
    using LongestSequenceValidate = robo_miner_interfaces::srv::LongestSequenceValidate;
    using CrystalType = uint8_t;

private:
    rclcpp::Client<RobotMove>::SharedPtr _robotMoveClient;
    rclcpp::Client<LongestSequenceValidate>::SharedPtr _longestSequenceValidateClient;

    const rclcpp::CallbackGroup::SharedPtr _publishersCallbackGroup =
        create_callback_group(rclcpp::CallbackGroupType::Reentrant);

    std::map<CrystalType, std::vector<FieldPos>> _crystalsMap;
};

#endif  // ! LONGESTCRYSTALSEQUENCEVALIDATOR_H
