#ifndef RAYCASTING_PLAYER_HPP
#define RAYCASTING_PLAYER_HPP

#include "raylib.h"
#include "Map.hpp"
#include "utils.hpp"

constexpr Color PLAYER_COLOR = RED;
constexpr float PLAYER_DEBUG_RAY_LENGTH = 5 * (MAP_SQUARE_SIZE + MAP_GAP_SIZE);


struct Player
{
    Vector2 pos;
    radian rotationAngleRadian;

    void rotate(radian angle);
    Vector2 getPositionRelativeToMap() const;
    void draw() const;
};

#endif //RAYCASTING_PLAYER_HPP