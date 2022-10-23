// Corresponding header
#include "include/robo_miner_controller/helpers/MapReconstructor.h"

void MapReconstructor::update_map(const FieldPos& fieldPos, const uint8_t currTile,
                              const MapDimension& mapDimens) {
    _mapValidatorVec.push_back(std::make_pair(fieldPos, currTile));
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

    DataVec map_to_reconst(rows * cols, 'X');

    for (auto it = _mapValidatorVec.begin(); it != _mapValidatorVec.end(); ++it) {
        auto [relative_pos, cristal_type] = *it;
        int32_t actual_map_row = _calcActualRow(relative_pos);
        int32_t actual_map_col = _calcActualCol(relative_pos);
        map_to_reconst[actual_map_row * cols + actual_map_col] = cristal_type;
    }

    _reconstructedMap = std::move(map_to_reconst);
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

typename MapReconstructor::DataVec MapReconstructor::get_data() const {
    return _reconstructedMap;
}
