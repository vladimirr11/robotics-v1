#ifndef TILESDEFINE_H
#define TILESDEFINE_H

#include <cstdint>

struct MapDimension {
    uint32_t rows{};
    uint32_t cols{};
    uint32_t distanceTopRowCenter{};
    uint32_t distanceBottomRowCenter{};
    uint32_t distanceLeftColCenter{};
    uint32_t distanceRightColCenter{};
};

enum FieldTileType : uint8_t {
    CYAN_CRISTAL = 'c',
    PURPLE_CRISTAL = 'p',
    BLUE_CRISTAL = 'b',
    GREEN_CRISTAL = 'g',
    RED_CRISTAL = 'r',
    OBSTACLE = 'X',
    FIELD_BORDER = '#'
};

enum RobotRotateDir : uint8_t { FORWARD_MOVE, ROTATE_LEFT, ROTATE_RIGHT };

enum SurroundingTile : int32_t { LEFT_TILE, FORWARD_TILE, RIGHT_TILE };

enum RobotDirection : int32_t {
    DIRECTION_UP,
    DIRECTION_RIGHT,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
};

#endif  // !TILESDEFINE_H
