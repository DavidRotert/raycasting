#include "raycasting.hpp"

#include "raymath.h"
#include "utils.hpp"

Vector2 Vector2Delta(const Vector2 a, const Vector2 b)
{
    return Vector2(fabsf(a.x - b.x), fabsf(a.y - b.y));
}

Vector2 Vector2PythagorasScale(const Vector2 a, const Vector2 b)
{
    Vector2 delta = Vector2Delta(a, b);
    return Vector2{sqrtf(1 + powf(delta.y / delta.x, 2)), sqrtf(1 + powf(delta.x / delta.y, 2))};
}

std::vector<Vector2> cast_ray_with_path(const Map& map, const Vector2 startPoint, const Vector2 direction)
{
    std::vector<Vector2> pathCrossingResult = {};
    pathCrossingResult.reserve(map.getHorizontalSize() * map.getVerticalSize());

    // FIXME: Add branches for non diagonal directions

    Vector2 scaleValues = Vector2PythagorasScale(startPoint, direction);

    int diffX = startPoint.x < direction.x ? 1 : -1;
    int diffY = startPoint.y < direction.y ? 1 : -1;

    auto testPos = Vector2{startPoint.x, startPoint.y};
    float currentXLength = scaleValues.x;
    float currentYLength = scaleValues.y;

    pathCrossingResult.push_back(testPos);

    if (map.getMapDataFromRelPos(testPos) != 0)
    {
        return pathCrossingResult;
    }

    bool hit = false;
    while (testPos.x < map.getHorizontalSize() && testPos.y < map.getVerticalSize() && testPos.x >= 0 && testPos.y >= 0)
    {
        if (currentXLength < currentYLength)
        {
            testPos.x += diffX;
            currentXLength += scaleValues.x;
        } else if (currentXLength > currentYLength)
        {
            testPos.y += diffY;
            currentYLength += scaleValues.y;
        } else
        {
            testPos.x += diffX;
            currentXLength += scaleValues.x;
            testPos.y += diffY;
            currentYLength += scaleValues.y;
        }

        if (hit)
        {
            break;
        }

        if (map.getMapDataFromRelPos(testPos) != 0)
        {
            hit = true;
        }
        pathCrossingResult.push_back(testPos);
    }

    return pathCrossingResult;
}
