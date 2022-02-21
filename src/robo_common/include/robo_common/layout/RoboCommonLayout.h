#ifndef ROBO_COMMON_ROBOCOMMONLAYOUT_H_
#define ROBO_COMMON_ROBOCOMMONLAYOUT_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "robo_common/layout/helpers/RoboCommonLayoutInterfaces.h"
#include "robo_common/layout/field/Field.h"
#include "robo_common/layout/entities/robot/Robot.h"
#include "robo_common/layout/animators/GameEndAnimator.h"

//Forward declarations
class RoboCommonLayoutInitHelper;
struct RoboCommonLayoutConfig;

class RoboCommonLayout {
  friend class RoboCommonLayoutInitHelper;

public:
  int32_t init(const RoboCommonLayoutConfig& cfg,
               const RoboCommonLayoutOutInterface &outInterface,
               RoboCommonLayoutInterface &interface);
  void deinit();
  void draw() const;

  //TODO create a separate help page class
  void activateHelpPage();

private:
  RoboCommonLayoutInterface produceInterface();

  Image _map;
  Field _field;
  Robot _playerRobot;
  GameEndAnimator _gameEndAnimator;
};

#endif /* ROBO_COMMON_ROBOCOMMONLAYOUT_H_ */