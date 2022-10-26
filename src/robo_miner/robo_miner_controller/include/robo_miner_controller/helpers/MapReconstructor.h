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
    using CrystalsPosVec  = std::vector<std::pair<uint8_t, FieldPos>>;
    using Map2D = std::vector<std::vector<int32_t>>;

public:
    MapReconstructor() = default;

    void update_map(const FieldPos& fieeldPos, const uint8_t currTile, const MapDimension& mapDimens);

    void reconstruct();

    DataVec get_map_data() const;

    CrystalsPosVec get_crystals_positions();

    Map2D get_2d_map_representation() const;

    std::pair<uint8_t, FieldPos> get_current_position();

private:
    int32_t _calcActualRow(const FieldPos& fieldPos) const;

    int32_t _calcActualCol(const FieldPos& fieldPos) const;

private:
    CrystalsPosVec _crystalsPosVec;
    MapDimension _mapDimens;
    DataVec _reconstructedMap;
};

#endif  // !MAPRECONSTRUCTOR_H
