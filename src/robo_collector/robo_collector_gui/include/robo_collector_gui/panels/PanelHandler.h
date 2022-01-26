#ifndef ROBO_COLLECTOR_GUI_PANELS_PANELHANDLER_H_
#define ROBO_COLLECTOR_GUI_PANELS_PANELHANDLER_H_

//C system headers

//C++ system headers

//Other libraries headers
#include "manager_utils/drawing/Image.h"
#include "manager_utils/drawing/NumberCounter.h"

//Own components headers
#include "robo_collector_gui/panels/config/PanelHandlerConfig.h"
#include "robo_collector_gui/panels/TimePanel.h"

//Forward declarations

class PanelHandler {
public:
  int32_t init(const PanelHandlerConfig& cfg);
  void draw() const;

  /* 1 damage == 1px */
  void decreaseHealthIndicator(int32_t damage);

  void increaseCollectedCoins(int32_t coins);

private:
  TimePanel _timePanel;

  NumberCounter _coinPanel;
  Text _totalCoinsText;

  Image _healthPanel;
  Image _healthIndicator;
  Image _horDelimiter;
  Image _vertDelimiter;
};

#endif /* ROBO_COLLECTOR_GUI_PANELS_PANELHANDLER_H_ */