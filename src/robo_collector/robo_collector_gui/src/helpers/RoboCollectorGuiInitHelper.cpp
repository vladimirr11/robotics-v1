//Corresponding header
#include "robo_collector_gui/helpers/RoboCollectorGuiInitHelper.h"

//C system headers

//C++ system headers

//Other libraries headers
#include "utils/ErrorCode.h"
#include "utils/Log.h"

//Own components headers
#include "robo_collector_gui/RoboCollectorGui.h"
#include "robo_collector_gui/config/RoboCollectorGuiConfig.h"
#include "robo_collector_gui/layout/helpers/RoboCollectorLayoutInterfaces.h"

int32_t RoboCollectorGuiInitHelper::init(const std::any &cfg,
                                         RoboCollectorGui &gui) {
  int32_t err = SUCCESS;
  const auto parsedCfg = [&cfg, &err]() {
    RoboCollectorGuiConfig localCfg;
    try {
      localCfg = std::any_cast<const RoboCollectorGuiConfig&>(cfg);
    } catch (const std::bad_any_cast &e) {
      LOGERR("std::any_cast<RoboCollectorGuiConfig&> failed, %s", e.what());
      err = FAILURE;
    }
    return localCfg;
  }();
  if (SUCCESS != err) {
    LOGERR("Error, parsing RoboCollectorGuiConfig failed");
    return FAILURE;
  }

  RoboCollectorLayoutInterface layoutInterface;
  if (SUCCESS != initLayout(parsedCfg.layoutCfg, layoutInterface, gui)) {
    LOGERR("Error, initLayout() failed");
    return FAILURE;
  }

  if (SUCCESS != initTurnHelper(layoutInterface,
          parsedCfg.layoutCfg.commonLayoutCfg.enemyFieldMarker, gui)) {
    LOGERR("initTurnHelper() failed");
    return FAILURE;
  }

  if (SUCCESS != initControllerExternalBridge(layoutInterface, gui)) {
    LOGERR("initControllerExternalBridge() failed");
    return FAILURE;
  }

  return SUCCESS;
}

int32_t RoboCollectorGuiInitHelper::initLayout(
    const RoboCollectorLayoutConfig &cfg,
    RoboCollectorLayoutInterface &interface, RoboCollectorGui &gui) {
  using namespace std::placeholders;

  RoboCollectorLayoutOutInterface outInterface;
  outInterface.collisionWatcher = &gui._collisionWatcher;
  outInterface.isPlayerTurnActiveCb =
      std::bind(&TurnHelper::isPlayerTurnActive, &gui._turnHelper);
  outInterface.finishRobotActCb =
      std::bind(&TurnHelper::onRobotFinishAct, &gui._turnHelper, _1);

  if (SUCCESS != gui._layout.init(cfg, outInterface, interface)) {
    LOGERR("Error in _layout.init()");
    return FAILURE;
  }

  return SUCCESS;
}

int32_t RoboCollectorGuiInitHelper::initTurnHelper(
    const RoboCollectorLayoutInterface &interface, char fieldEnemyMarker,
    RoboCollectorGui &gui) {
  TurnHelperConfig cfg;
  cfg.enablePlayerInputCb = interface.enablePlayerInputCb;
  cfg.getFieldDataCb = interface.commonLayoutInterface.getFieldDataCb;
  cfg.fieldEnemyMarker = fieldEnemyMarker;
  cfg.maxRobots = Defines::ROBOTS_CTN;
  cfg.robotActInterfaces.reserve(Defines::ROBOTS_CTN);
  cfg.robotActInterfaces.push_back(
      interface.commonLayoutInterface.playerRobotActInterface);
  cfg.robotActInterfaces.insert(cfg.robotActInterfaces.end(),
      interface.enemyRobotActInterfaces.begin(),
      interface.enemyRobotActInterfaces.end());

  if (SUCCESS != gui._turnHelper.init(cfg)) {
    LOGERR("Error in _turnHelper.init()");
    return FAILURE;
  }

  return SUCCESS;
}

int32_t RoboCollectorGuiInitHelper::initControllerExternalBridge(
    const RoboCollectorLayoutInterface &interface, RoboCollectorGui &gui) {
  CollectorControllerExternalBridgeOutInterface outInterface;
  outInterface.invokeActionEventCb = gui._invokeActionEventCb;
  outInterface.moveButtonClickCb = interface.moveButtonClickCb;

  gui._controllerExternalBridge =
      std::make_shared<CollectorControllerExternalBridge>();
  if (SUCCESS != gui._controllerExternalBridge->init(outInterface)) {
    LOGERR("Error in _controllerExternalBridge.init()");
    return FAILURE;
  }

  return SUCCESS;
}
