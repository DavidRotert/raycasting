#pragma once

#include "raylib.h"
#include "Map.hpp"
#include "utils.hpp"

constexpr Color PLAYER_COLOR = RED;
constexpr float PLAYER_DEBUG_RAY_LENGTH = 5 * (MAP_GRID_SQUARE_SIZE + MAP_GRID_GAP_SIZE);


struct Player
{
    Vector2 pos;
    radian rotationAngleRadian;
    radian fov;


    void rotate(radian angle);
    void move(Vector2 delta);
    Vector2 getRotationAsNonNormalizedVector(radian rotation) const;
    Vector2 getPositionRelativeToMap() const;
};