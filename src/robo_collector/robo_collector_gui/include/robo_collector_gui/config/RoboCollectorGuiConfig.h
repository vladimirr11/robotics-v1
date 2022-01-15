#ifndef ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUICONFIG_H_
#define ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUICONFIG_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "robo_collector_gui/defines/RoboCollectorGuiDefines.h"
#include "robo_collector_gui/field/config/FieldConfig.h"

//Forward declarations

struct RoboCollectorGuiConfig {
  GameMode gameMode = GameMode::UNKNOWN;
  FieldConfig fieldCfg;
};

#endif /* ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUICONFIG_H_ */
