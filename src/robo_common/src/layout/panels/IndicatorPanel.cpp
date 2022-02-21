//Corresponding header
#include "robo_common/layout/panels/IndicatorPanel.h"

//C system headers

//C++ system headers

//Other libraries headers
#include "utils/drawing/WidgetAligner.h"
#include "utils/ErrorCode.h"
#include "utils/Log.h"

//Own components headers

int32_t IndicatorPanel::init(const IndicatorPanelConfig &cfg,
                             const IndicatorDepletedCb &indicatorDepletedCb,
                             const Point& pos) {
  _indicatorReduceTimerId = cfg.indicatorReduceTimerId;

  if (nullptr == indicatorDepletedCb) {
    LOGERR("Error, nullptr provided for IndicatorDepletedCb");
    return FAILURE;
  }
  _indicatorDepletedCb = indicatorDepletedCb;

  _panel.create(cfg.rsrcId);
  _panel.setPosition(pos);

  _indicator.create(cfg.indicatorRsrcId);
  _indicator.setPosition(pos.x + 79, pos.y + 13);
  _indicator.setCropRect(_indicator.getImageRect());

  _indicatorText.create(cfg.indicatorFontId, "100%", Colors::RED);
  setAndCenterIndicatorText();

  return SUCCESS;
}

void IndicatorPanel::draw() const {
  _panel.draw();
  _indicator.draw();
  _indicatorText.draw();
}

void IndicatorPanel::decreaseIndicator(int32_t delta) {
  _damageTicksLeft += delta;
  if (!isActiveTimerId(_indicatorReduceTimerId)) {
    constexpr auto timerInterval = 20;
    startTimer(timerInterval, _indicatorReduceTimerId, TimerType::PULSE);
  }
}

void IndicatorPanel::onTimeout(const int32_t timerId) {
  if (timerId == _indicatorReduceTimerId) {
    processIndicatorReduceAnim();
  } else {
    LOGERR("Error, received unsupported timerId: %d", timerId);
  }
}

void IndicatorPanel::processIndicatorReduceAnim() {
  auto cropRectangle = _indicator.getCropRect();
  auto &remainingHealth = cropRectangle.w;
  if (0 == remainingHealth) {
    stopTimer(_indicatorReduceTimerId);
    _indicatorDepletedCb();
    return;
  }

  if (0 == _damageTicksLeft) {
    stopTimer(_indicatorReduceTimerId);
    return;
  }
  --_damageTicksLeft;

  --remainingHealth;
  _indicator.setCropRect(cropRectangle);
  setAndCenterIndicatorText();
}

void IndicatorPanel::setAndCenterIndicatorText() {
  const auto totalHealth = _indicator.getImageWidth();
  const auto indicatorCropRect = _indicator.getCropRect();
  const auto remainingHealth = indicatorCropRect.w;
  const auto remainingHealthPecent = (remainingHealth * 100) / totalHealth;
  const auto healthContent = std::to_string(remainingHealthPecent) + "%";

  _indicatorText.setText(healthContent.c_str());

  auto widgetAlignArea = indicatorCropRect;
  if (0 == remainingHealthPecent) {
    widgetAlignArea = _indicator.getImageRect();
  } else if (remainingHealthPecent < 50) {
    widgetAlignArea.x += widgetAlignArea.w;
    widgetAlignArea.w = totalHealth - remainingHealth;
    _indicatorText.setColor(Colors::GREEN);
  }

  const auto indicatorTextWidth = _indicatorText.getImageWidth();
  const auto textPos = WidgetAligner::getPosition(indicatorTextWidth,
      _indicatorText.getImageHeight(), widgetAlignArea,
      WidgetAlignment::CENTER_CENTER);
  _indicatorText.setPosition(textPos);
}