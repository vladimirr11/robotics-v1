#ifndef ROBO_COLLECTOR_CONTROLLER_COLLECTORGUIEXTERNALBRIDGE_H_
#define ROBO_COLLECTOR_CONTROLLER_COLLECTORGUIEXTERNALBRIDGE_H_

// System headers

// Other libraries headers
#include <rclcpp/node.hpp>
#include "game_engine/defines/ActionEventDefines.h"
#include "robo_collector_common/defines/RoboCollectorFunctionalDefines.h"
#include "robo_collector_interfaces/msg/user_authenticate.hpp"
#include "robo_collector_interfaces/msg/robot_move_type.hpp"
#include <std_msgs/msg/string.hpp>
#include "std_msgs/msg/empty.hpp"
#include "utils/ErrorCode.h"

// Own components headers

// Forward declarations

struct CollectorGuiExternalBridgeOutInterface {
    InvokeActionEventCb invokeActionEventCb;
    EnablePlayerInputCb enablePlayerInputCb;
    SystemShutdownCb systemShutdownCb;
};

class CollectorGuiExternalBridge : public rclcpp::Node {
public:
    CollectorGuiExternalBridge();

    ErrorCode init(const CollectorGuiExternalBridgeOutInterface& interface);

    void publishToggleDebugInfo() const;
    void publishToggleHelpPage() const;
    void publishRobotAct(MoveType moveType) const;
    void publishDebugMsg(const std_msgs::msg::String::SharedPtr msg) const;
    void publishUserAuthenticate(const UserData& data);

private:
    using UserAuthenticate = robo_collector_interfaces::msg::UserAuthenticate;
    using Empty = std_msgs::msg::Empty;
    using RobotMoveType  = robo_collector_interfaces::msg::RobotMoveType;
    using String = std_msgs::msg::String;

private:
    ErrorCode initOutInterface(const CollectorGuiExternalBridgeOutInterface& outInterface);
    ErrorCode initCommunication();

    void onEnableRobotTurnMsg(const Empty::SharedPtr msg);
    void onControllerShutdownMsg(const Empty::SharedPtr msg);

private:
    CollectorGuiExternalBridgeOutInterface _outInterface;

    rclcpp::Publisher<UserAuthenticate>::SharedPtr _userAuthenticatePublisher;
    rclcpp::Publisher<Empty>::SharedPtr _toggleHelpPagePublisher;
    rclcpp::Publisher<Empty>::SharedPtr _toggleDebugInfoPublisher;
    rclcpp::Publisher<RobotMoveType>::SharedPtr _playerActPublisher;
    // rclcpp::Publisher<String>::SharedPtr _debugMsgPublisher;

    rclcpp::Subscription<Empty>::SharedPtr _enableRobotTurnSubscription;
    rclcpp::Subscription<Empty>::SharedPtr _shutdownControllerSubscription;

    // Create different callbacks groups for publishers and subscribers
    // so they can be executed in parallel
    const rclcpp::CallbackGroup::SharedPtr _subscriberCallbackGroup =
        create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    const rclcpp::CallbackGroup::SharedPtr _publishersCallbackGroup =
        create_callback_group(rclcpp::CallbackGroupType::Reentrant);
};

#endif /* ROBO_COLLECTOR_CONTROLLER_COLLECTORGUIEXTERNALBRIDGE_H_ */
