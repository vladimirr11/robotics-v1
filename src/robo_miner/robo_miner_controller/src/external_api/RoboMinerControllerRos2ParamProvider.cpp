// Corresponding header
#include "robo_miner_controller/external_api/RoboMinerControllerRos2ParamProvider.h"

// C++ System headers
#include <sstream>
#include <thread>

// Other libraries headers
#include "utils/Log.h"
#include "utils/data_type/EnumClassUtils.h"

static constexpr auto NODE_NAME = "RoboMinerControllerRos2ParamProvider";

static constexpr auto ROS2_EXECUTOR_TYPE_PARAM_NAME = "ros2_executor_type";
static constexpr auto ROS2_EXECUTOR_THREADS_NUM_PARAM_NAME = "ros2_executor_threads_num";
static constexpr auto USE_FOG_OF_WAR_PARAM_NAME = "use_fog_of_war_status";

static constexpr auto USER_PARAM_NAME = "user";
static constexpr auto REPOSITORY_PARAM_NAME = "repository";
static constexpr auto COMMIT_SHA_PARAM_NAME = "commit_sha";

// ROS2 executor
static constexpr auto DEFAULT_EXECUTOR_TYPE = 0;
static constexpr auto DEFAULT_EXECUTOR_THREADS_NUM = 2;

// misc
static constexpr auto DEFAULT_USE_FOG_OF_WAR_STATUS = true;

// user data
static constexpr auto DEFAULT_USER = "not_set";
static constexpr auto DEFAULT_REPOSITORY = "not_set";
static constexpr auto DEFAULT_COMMIT_SHA = "not_set";

void RoboMinerControllerRos2Params::print() const {
    std::ostringstream ostr;
    ostr << "==================================================================\n"
         << "Printing node(" << NODE_NAME << ") params:\n"
         << ROS2_EXECUTOR_TYPE_PARAM_NAME << ": "
         << getExecutorName(ros2CommunicatorConfig.executorType) << '\n'
         << ROS2_EXECUTOR_THREADS_NUM_PARAM_NAME << ": " << ros2CommunicatorConfig.numberOfThreads
         << '\n'
         << USE_FOG_OF_WAR_PARAM_NAME << ": "
         << ((FogOfWarStatus::ENABLED == fogOfWarStatus) ? "true" : "false") << '\n'
         << USER_PARAM_NAME << ": " << userData.user << '\n'
         << REPOSITORY_PARAM_NAME << ": " << userData.repository << '\n'
         << COMMIT_SHA_PARAM_NAME << ": " << userData.commitSha << '\n'
         << "==================================================================\n";

    LOG("%s", ostr.str().c_str());
}

void RoboMinerControllerRos2Params::validate() {
    const size_t max_hardware_threads = std::thread::hardware_concurrency();
    if (ros2CommunicatorConfig.numberOfThreads > max_hardware_threads) {
        std::ostringstream ostr;
        ostr << "Param: [" << ROS2_EXECUTOR_THREADS_NUM_PARAM_NAME << "] has invalid value: ["
             << ros2CommunicatorConfig.numberOfThreads << "]. Overriding with default value: ["
             << max_hardware_threads << "]";
        LOGR("%s", ostr.str().c_str());

        ros2CommunicatorConfig.numberOfThreads = max_hardware_threads;
    }
}

RoboMinerControllerRos2ParamProvider::RoboMinerControllerRos2ParamProvider()
    : rclcpp::Node(NODE_NAME) {
    declare_parameter<int32_t>(ROS2_EXECUTOR_TYPE_PARAM_NAME, DEFAULT_EXECUTOR_TYPE);
    declare_parameter<int32_t>(ROS2_EXECUTOR_THREADS_NUM_PARAM_NAME, DEFAULT_EXECUTOR_THREADS_NUM);
    declare_parameter<bool>(USE_FOG_OF_WAR_PARAM_NAME, DEFAULT_USE_FOG_OF_WAR_STATUS);

    declare_parameter<std::string>(USER_PARAM_NAME, DEFAULT_USER);
    declare_parameter<std::string>(REPOSITORY_PARAM_NAME, DEFAULT_REPOSITORY);
    declare_parameter<std::string>(COMMIT_SHA_PARAM_NAME, DEFAULT_COMMIT_SHA);
}

RoboMinerControllerRos2Params RoboMinerControllerRos2ParamProvider::getParams() {
    int32_t executor_type_int{};
    get_parameter(ROS2_EXECUTOR_TYPE_PARAM_NAME, executor_type_int);
    _params.ros2CommunicatorConfig.executorType = toEnum<ExecutorType>(executor_type_int);
    get_parameter(ROS2_EXECUTOR_THREADS_NUM_PARAM_NAME,
                  _params.ros2CommunicatorConfig.numberOfThreads);

    bool use_fog_of_war_param{};
    get_parameter(USE_FOG_OF_WAR_PARAM_NAME, use_fog_of_war_param);
    _params.fogOfWarStatus =
        use_fog_of_war_param ? FogOfWarStatus::ENABLED : FogOfWarStatus::DISABLED;

    get_parameter(USER_PARAM_NAME, _params.userData.user);
    get_parameter(REPOSITORY_PARAM_NAME, _params.userData.repository);
    get_parameter(COMMIT_SHA_PARAM_NAME, _params.userData.commitSha);

    _params.validate();

    return _params;
}
