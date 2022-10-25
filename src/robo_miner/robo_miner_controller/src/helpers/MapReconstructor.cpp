// Corresponding header
#include "include/robo_miner_controller/helpers/MapReconstructor.h"

void MapReconstructor::update_map(const FieldPos& fieldPos, const uint8_t currTile,
                                  const MapDimension& mapDimens) {
    _crystalsPosVec.push_back(std::make_pair(currTile, fieldPos));
    _mapDimens.rows = mapDimens.rows;
    _mapDimens.cols = mapDimens.cols;
    _mapDimens.distanceTopRowCenter = mapDimens.distanceTopRowCenter;
    _mapDimens.distanceBottomRowCenter = mapDimens.distanceBottomRowCenter;
    _mapDimens.distanceLeftColCenter = mapDimens.distanceLeftColCenter;
    _mapDimens.distanceRightColCenter = mapDimens.distanceRightColCenter;
}

void MapReconstructor::reconstruct() {
    int32_t rows = _mapDimens.rows;
    int32_t cols = _mapDimens.cols;

    DataVec map_to_reconstruct(rows * cols, 'X');

    for (auto it = _crystalsPosVec.begin(); it != _crystalsPosVec.end(); ++it) {
        auto& [crystal_type, relative_pos] = *it;
        int32_t actual_map_row = _calcActualRow(relative_pos);
        int32_t actual_map_col = _calcActualCol(relative_pos);
        map_to_reconstruct[actual_map_row * cols + actual_map_col] = crystal_type;
    }

    _reconstructedMap = std::move(map_to_reconstruct);
}

typename MapReconstructor::DataVec MapReconstructor::get_data() const { return _reconstructedMap; }

typename MapReconstructor::CrystalsPosVec MapReconstructor::get_crystals_pos() {
    using pair_type = std::pair<uint8_t, FieldPos>;
    std::for_each(_crystalsPosVec.begin(), _crystalsPosVec.end(), [this](pair_type& pair) -> void {
        auto& [crystal_type, relative_pos] = pair;
        int32_t actual_map_row = _calcActualRow(relative_pos);
        int32_t actual_map_col = _calcActualCol(relative_pos);
        relative_pos.row = actual_map_row;
        relative_pos.col = actual_map_col;
    });

    return _crystalsPosVec;
}

int32_t MapReconstructor::_calcActualRow(const FieldPos& fieldPos) const {
    int32_t actual_map_row = (fieldPos.row <= 0)
                                 ? _mapDimens.distanceTopRowCenter - std::abs(fieldPos.row)
                                 : _mapDimens.distanceTopRowCenter + fieldPos.row;
    return actual_map_row;
}

int32_t MapReconstructor::_calcActualCol(const FieldPos& fieldPos) const {
    int32_t actual_map_col = (fieldPos.col <= 0)
                                 ? _mapDimens.distanceLeftColCenter - std::abs(fieldPos.col)
                                 : _mapDimens.distanceLeftColCenter + fieldPos.col;
    return actual_map_col;
}
