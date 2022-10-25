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
    
    // auto node2 = std::make_shared<LongestCrystalPathValidator>();

    // rclcpp::executors::SingleThreadedExecutor exec;
    // rclcpp::NodeOptions options;
    // exec.add_node(node);
    // exec.add_node(node2);

    if (ErrorCode::SUCCESS != node->run()) {
        LOGERR("RoboMinerGuiExternalBridge::run() failed");
        return EXIT_FAILURE;
    }

    // // Add some nodes to the executor which provide work for the executor during its "spin"
    // // function. An example of available work is executing a subscription callback, or a timer
    // // callback.
    // exec.add_node(node);
    // exec.add_node(node2);

    // // spin will block until work comes in, execute work as it becomes available, and keep blocking.
    // // It will only be interrupted by Ctrl-C.
    // exec.spin();

    rclcpp::shutdown();
    spin_thread.join();

    return EXIT_SUCCESS;
}
