#include "raycasting.hpp"

#include "raymath.h"

RayIntersectionPair get_first_ray_intersection(Vector2 startPosition, radian rotationAngle)
{
    float intersect1X;
    float intersect1Y;
    float intersect2X = 0;
    float intersect2Y = 0;



    if (rotationAngle > 270 * DEG2RAD)
    {
        // Calculate upward right facing
        intersect1X = ceilf(startPosition.x);
        const float difY = tanf(2 * PI - rotationAngle) * (ceilf(startPosition.x) - startPosition.x);
        intersect1Y = startPosition.y - difY;
    } else if (rotationAngle == 270 * DEG2RAD)
    {
        // Calculate upward facing
        intersect1X = startPosition.x;
        intersect1Y = floorf(startPosition.y);
    } else if (rotationAngle > 180 * DEG2RAD)
    {
        // Calculate upward left facing
        intersect1X = floorf(startPosition.x);
        const float difY = tanf(rotationAngle - PI) * (floorf(startPosition.x) - startPosition.x);
        intersect1Y = startPosition.y + difY;
    } else if (rotationAngle == 180 * DEG2RAD)
    {
        // Calculate left facing
        intersect1X = ceilf(startPosition.x) - 1;
        intersect1Y = startPosition.y;
    } else if (rotationAngle > 90 * DEG2RAD)
    {
        // Calculate downward left facing
        intersect1X = floorf(startPosition.x);
        const float difY = tanf(PI - rotationAngle) * (floorf(startPosition.x) - startPosition.x);
        intersect1Y = startPosition.y - difY;
    } else if (rotationAngle == 90 * DEG2RAD)
    {
        // Calculate downward facing
        intersect1X = startPosition.x;
        intersect1Y = ceilf(startPosition.y);
    } else if (rotationAngle > 0)
    {
        // Calculate downward right facing
        intersect1X = ceilf(startPosition.x);
        const float dif1Y = tanf(rotationAngle) * (ceilf(startPosition.x) - startPosition.x);
        intersect1Y = startPosition.y + dif1Y;

        intersect2X = startPosition.x + 1;
        const float dif2Y = tanf(rotationAngle) * (ceilf(startPosition.x) - startPosition.x);
        intersect2Y = startPosition.y + dif2Y;
    } else
    {
        // Calculate right facing
        intersect1X = floorf(startPosition.x) + 1;
        intersect1Y = startPosition.y;

        intersect2X = floorf(startPosition.x) + 2;
        intersect2Y = startPosition.y;
    }

    return RayIntersectionPair{Vector2{intersect1X, intersect1Y}, Vector2{intersect2X, intersect2Y}};
}

int add(int a, int b)
{
    return a + b;
}
