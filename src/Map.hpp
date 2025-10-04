#ifndef MAP_HPP
#define MAP_HPP

#include <array>
#include <cstdint>
#include <span>

#include "raylib.h"

constexpr int MAP_SIZE_HORIZONTAL = 10;
constexpr int MAP_SIZE_VERTICAL = 10;
constexpr int MAP_SQUARE_SIZE = 40;
constexpr int MAP_GAP_SIZE = 3;

typedef std::size_t MapSizeType;
typedef uint8_t MapDataType;
typedef std::array<MapDataType, MAP_SIZE_HORIZONTAL * MAP_SIZE_VERTICAL> Maps;

class Map
{
    std::span<MapDataType> mapData;
    const MapSizeType horizontalSize;
    const MapSizeType verticalSize;

public:
    Map(const MapSizeType horizontalSize, const MapSizeType verticalSize, const std::span<MapDataType> mapData) :
        mapData(mapData), horizontalSize(horizontalSize), verticalSize(verticalSize)
    {
    }

    MapSizeType getHorizontalSize() const { return horizontalSize; }
    MapSizeType getVerticalSize() const { return verticalSize; }
    MapDataType getMapDataAtIndex(std::size_t pos) const;
    MapDataType getMapDataFromRelPos(Vector2 pos) const;
    std::size_t calcIndexFromRelPos(Vector2 pos) const;
    Vector2 calcRelPosFromIndex(std::size_t index) const;
};

Vector2 get_position_relative_to_map(Vector2 pos);
Vector2 get_absolute_position_on_map(Vector2 relative);

#endif // MAP_HPP
