#include "Map.hpp"

#include "raymath.h"

Vector2 get_position_relative_to_map(Vector2 pos)
{
    return Vector2Divide(pos, Vector2{MAP_SQUARE_SIZE + MAP_GAP_SIZE, MAP_SQUARE_SIZE + MAP_GAP_SIZE});
}

Vector2 get_absolute_position_on_map(Vector2 relative)
{
    return Vector2Multiply(relative, Vector2{MAP_SQUARE_SIZE + MAP_GAP_SIZE, MAP_SQUARE_SIZE + MAP_GAP_SIZE});
}
