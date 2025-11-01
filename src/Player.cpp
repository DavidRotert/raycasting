#include "Player.hpp"

#include "raycasting.hpp"
#include "raymath.h"
#include "utils.hpp"

void Player::move(Vector2 delta)
{
    this->position = Vector2Add(position, delta);
}

void Player::move(const float delta, const radian rotation)
{
    this->move(
        Vector2Multiply(
            Vector2Subtract(
                this->getRotationAsNonNormalizedVector(rotation),
                this->position
            ),
            Vector2{delta, delta}
        )
    );
}

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

Vector2 Player::getDebugGridPosition() const
{
    return get_absolute_position_on_map(this->position);
}

Vector2 Player::getRotationAsNonNormalizedVector(const radian rotation) const
{
    return Vector2Add(this->position, Vector2{cosf(rotation), sinf(rotation)});
}
