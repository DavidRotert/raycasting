#include "Player.hpp"

#include "raycasting.hpp"
#include "raymath.h"
#include "utils.hpp"

void Player::rotate(radian angle)
{
    radian newAngle = this->rotationAngleRadian + angle;

    if (newAngle < 0) {
        this->rotationAngleRadian = 2 * PI + angle;
    } else if (newAngle > 2 * PI) {
        this->rotationAngleRadian = newAngle - 2 * PI;
    } else {
        this->rotationAngleRadian = newAngle;
    }
}

Vector2 Player::getPositionRelativeToMap() const
{
    return get_position_relative_to_map(this->pos);
}

void Player::draw() const
{
    DrawCircleV(this->pos, MAP_SQUARE_SIZE * 0.3, PLAYER_COLOR);
}

Vector2 Player::getRotationAsNonNormalizedVector()
{
    return Vector2Add(this->pos, Vector2{cosf(this->rotationAngleRadian), sinf(this->rotationAngleRadian)});
}