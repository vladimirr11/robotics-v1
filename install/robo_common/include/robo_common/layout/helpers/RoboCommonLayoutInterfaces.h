#ifndef ROBO_COMMON_ROBOCOMMONLAYOUTINTERFACES_H_
#define ROBO_COMMON_ROBOCOMMONLAYOUTINTERFACES_H_

//System headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "robo_common/defines/RoboCommonFunctionalDefines.h"
#include "robo_common/layout/entities/robot/helpers/RobotActInterface.h"
#include "sdl_utils/drawing/defines/DrawUtilityDefines.h"

//Forward declarations
class CollisionWatcher;

struct RoboCommonLayoutInterface {
  SetFieldDataMarkerCb setFieldDataMarkerCb;
  ResetFieldDataMarkerCb resetFieldDataMarkerCb;
  GetFieldDescriptionCb getFieldDescriptionCb;
  GetPlayerSurroundingTilesCb getPlayerSurroundingTilesCb;
  RobotActInterface playerRobotActInterface;
  ToggleHelpPageCb toggleHelpPageCb;
  ToggleDebugInfoCb toggleDebugInfoCb;
  SetDebugMsgCb setDebugMsgCb;
  StartGameLostAnimCb startGameLostAnimCb;
  StartGameWonAnimCb startGameWonAnimCb;
  StartAchievementWonAnimCb startAchievementWonAnimCb;
  RevealFogOfWarTilesCb revealFogOfWarTilesCb;
  SetUserDataCb setUserDataCb;
};

struct RoboCommonLayoutOutInterface {
  ShutdownGameCb shutdownGameCb;
  TakeScreenshotCb takeScreenshotCb;
  FinishRobotActCb finishRobotActCb;
  PlayerRobotDamageCollisionCb playerRobotDamageCollisionCb;
  PlayerDamageCb playerDamageCb;
  ObjechApproachOverlayTriggeredCb objectApproachOverlayTriggeredCb;
  CollisionWatcher *collisionWatcher = nullptr;
};

#endif /* ROBO_COMMON_ROBOCOMMONLAYOUTINTERFACES_H_ */
