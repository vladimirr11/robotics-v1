#ifndef ROBOMINERCONTROLLERROS2PARAMPROVIDER_H
#define ROBOMINERCONTROLLERROS2PARAMPROVIDER_H

// Other libraries headers
#include <rclcpp/node.hpp>
#include "robo_common/defines/RoboCommonDefines.h"
#include "robo_common/layout/field/config/FogOfWarConfig.h"
#include "ros2_game_engine/communicator/config/Ros2CommunicatorConfig.h"
#include "utils/drawing/Rectangle.h"

struct RoboMinerControllerRos2Params {
    Ros2CommunicatorConfig ros2CommunicatorConfig;
    FogOfWarStatus fogOfWarStatus = FogOfWarStatus::ENABLED;
    UserData userData;

    void print() const;
    void validate();
};

class RoboMinerControllerRos2ParamProvider : public rclcpp::Node {
public:
    RoboMinerControllerRos2ParamProvider();

    RoboMinerControllerRos2Params getParams();

private:
    RoboMinerControllerRos2Params _params;
};

#endif  // !ROBOMINERCONTROLLERROS2PARAMPROVIDER_H
