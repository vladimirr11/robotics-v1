#ifndef MAPRECONSTRUCTOR_H
#define MAPRECONSTRUCTOR_H

// C++ System headers
#include <memory>
#include <vector>

// Own components headers
#include "include/robo_miner_controller/defines/CommonDefines.h"
#include "robo_common/defines/RoboCommonDefines.h"

class MapReconstructor {
private:
    using DataVec = std::vector<uint8_t>;

public:
    MapReconstructor() = default;

    void update_map(const FieldPos& fieeldPos, const uint8_t currTile, const MapDimension& mapDimens);

    void reconstruct();

    DataVec get_data() const;

private:
    int32_t _calcActualRow(const FieldPos& fieldPos) const;

    int32_t _calcActualCol(const FieldPos& fieldPos) const;

private:
    std::vector<std::pair<FieldPos, uint8_t>> _mapValidatorVec;
    MapDimension _mapDimens;
    DataVec _reconstructedMap;
};

#endif  // !MAPRECONSTRUCTOR_H
