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
    return Vector2{sqrtf(1 + delta.y / delta.x), sqrtf(1 + delta.x / delta.y)};
}

std::vector<MapDataType> cast_ray_with_path(const Map& map, int mapSizeHorizontal, int mapSizeVertical, const Vector2 startPoint, const Vector2 direction)
{
    std::vector<MapDataType> pathCrossingResult = {};
    pathCrossingResult.reserve(map.size());

    // FIXME: Add branches for non diagonal directions

    Vector2 scaleValues = Vector2PythagorasScale(startPoint, direction);

    int diffX = startPoint.x < direction.x ? 1 : -1;
    int diffY = startPoint.y < direction.y ? 1 : -1;

    int testX = startPoint.x;
    int testY = startPoint.y;
    float currentXLength = scaleValues.x * testX;
    float currentYLength = scaleValues.y * testY;

    pathCrossingResult.push_back(testY * mapSizeHorizontal + testX);

    while (testX < mapSizeHorizontal && testY < mapSizeVertical && testX >= 0 && testY >= 0)
    {
        if (currentXLength <= currentYLength)
        {
            testX += diffX;
            currentXLength = scaleValues.x * testX;

        }
        if (currentXLength >= currentYLength)
        {
            testY += diffY;
            currentYLength = scaleValues.y * testY;
        }

        pathCrossingResult.push_back(testY * mapSizeHorizontal + testX);
    }

    return pathCrossingResult;
}
