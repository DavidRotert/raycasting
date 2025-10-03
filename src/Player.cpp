#include "Player.hpp"

#include "raycasting.hpp"
#include "raymath.h"
#include "utils.hpp"

void Player::rotate(radian angle)
{
    radian newAngle = this->rotationAngleRadian + angle;

    if (newAngle < 0)
    {
        this->rotationAngleRadian = 2 * PI + angle;
    } else if (newAngle > 2 * PI)
    {
        this->rotationAngleRadian = newAngle - 2 * PI;
    } else
    {
        this->rotationAngleRadian = newAngle;
    }
}

Vector2 Player::getPositionRelativeToMap() const
{
    return get_position_relative_to_map(this->pos);
}

void Player::draw() const
{
    // Draw player
    DrawCircleV(this->pos, MAP_SQUARE_SIZE * 0.3, PLAYER_COLOR);

    // Draw debug ray
    Vector2 debugRayEndPos = Vector2Add(
        this->pos,
        Vector2Rotate(
            VECTOR2_RIGHT(PLAYER_DEBUG_RAY_LENGTH),
            this->rotationAngleRadian
        )
    );
    DrawLineV(this->pos, debugRayEndPos, YELLOW);

    // Draw 2 intersect points
    /*RayIntersectionPair lastIntersect = get_first_ray_intersection(this->getPositionRelativeToMap(), this->rotationAngleRadian);
    for (int i = 0; i < 1; ++i)
    {
        DrawCircleV( get_absolute_position_on_map(lastIntersect.intersect1), 2, GREEN);
        DrawCircleV( get_absolute_position_on_map(lastIntersect.intersect2), 2, GREEN);
    }*/
}
