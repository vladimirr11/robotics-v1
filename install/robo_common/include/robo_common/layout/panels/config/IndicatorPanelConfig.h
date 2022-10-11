#ifndef ROBO_COMMON_INDICATORPANELCONFIG_H_
#define ROBO_COMMON_INDICATORPANELCONFIG_H_

//System headers
#include <cstdint>

//Other libraries headers

//Own components headers

struct IndicatorPanelConfig {
  uint64_t rsrcId = 0;
  uint64_t indicatorRsrcId = 0;
  uint64_t indicatorFontId = 0;
  int32_t indicatorModifyTimerId = 0;
};

#endif /* ROBO_COMMON_INDICATORPANELCONFIG_H_ */
