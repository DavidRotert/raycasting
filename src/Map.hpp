#ifndef MAP_HPP
#define MAP_HPP

#include <array>
#include <cstdint>

#include "raylib.h"

constexpr int MAP_SIZE_HORIZONTAL = 10;
constexpr int MAP_SIZE_VERTICAL = 10;
constexpr int MAP_SQUARE_SIZE = 40;
constexpr int MAP_GAP_SIZE = 5;

typedef uint8_t MapDataType;
typedef std::array<MapDataType, MAP_SIZE_HORIZONTAL * MAP_SIZE_VERTICAL> Map;



Vector2 get_position_relative_to_map(Vector2 pos);
Vector2 get_absolute_position_on_map(Vector2 relative);

#endif // MAP_HPP