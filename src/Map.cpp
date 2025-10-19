#include "Map.hpp"

#include <format>
#include <stdexcept>

#include "raymath.h"

MapDataType Map::getMapDataAtIndex(std::size_t pos) const
{
    if (pos >= this->mapData.size()) {
        throw std::out_of_range(std::format("{} is out of bounds, maximum index is {}", pos, this->mapData.size()));
    }
    return this->mapData[pos];
}

MapDataType Map::getMapDataFromRelPos(const Vector2 pos) const
{
    return this->getMapDataAtIndex(this->calcIndexFromRelPos(pos));
}

std::size_t Map::calcIndexFromRelPos(Vector2 pos) const
{
    return pos.y * this->horizontalSize + pos.x;
}


Vector2 get_position_relative_to_map(const Vector2 pos)
{
    return Vector2Divide(pos, Vector2{MAP_GRID_SQUARE_SIZE + MAP_GRID_GAP_SIZE, MAP_GRID_SQUARE_SIZE + MAP_GRID_GAP_SIZE});
}

Vector2 get_absolute_position_on_map(const Vector2 relative)
{
    return Vector2Multiply(relative, Vector2{MAP_GRID_SQUARE_SIZE + MAP_GRID_GAP_SIZE, MAP_GRID_SQUARE_SIZE + MAP_GRID_GAP_SIZE});
}