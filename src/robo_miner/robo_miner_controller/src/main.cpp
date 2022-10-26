// C++ System headers
#include <cstdint>
#include <cstdlib>
#include <rclcpp/rclcpp.hpp>
#include <thread>

// Own components headers
#include "robo_miner_controller/external_api/RoboMinerControllerRos2ParamProvider.h"
#include "robo_miner_controller/external_api/RoboMinerGuiExternalBridge.h"
// #include "robo_miner_controller/external_api/LongestCrystalPathValidator.h"

// Other libraries headers
#include "utils/ErrorCode.h"
#include "utils/Log.h"

int32_t main(int32_t argc, char** argv) {
    rclcpp::init(argc, argv);

    auto param_provider_node = std::make_shared<RoboMinerControllerRos2ParamProvider>();
    const auto robo_miner_params = param_provider_node->getParams();
    robo_miner_params.print();

    auto node = std::make_shared<RoboMinerGuiExternalBridge>();
    if (ErrorCode::SUCCESS != node->init(robo_miner_params)) {
        LOGERR("RoboMinerGuiExternalBridge::init() failed");
        return EXIT_FAILURE;
    }

    std::thread spin_thread([&node]() { rclcpp::spin(node); });

    if (ErrorCode::SUCCESS != node->run()) {
        LOGERR("RoboMinerGuiExternalBridge::run() failed");
        return EXIT_FAILURE;
    }

    rclcpp::shutdown();
    spin_thread.join();

    return EXIT_SUCCESS;
}
