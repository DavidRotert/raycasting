#include "raycasting.hpp"

#include <iostream>

#include "raymath.h"

Vector2 cast_ray(const Map& map, const Vector2 startPoint, const Vector2 directionPoint)
{
    auto rayDirection = Vector2Normalize(Vector2Subtract(directionPoint, startPoint));
    auto unitStepValues = Vector2{
        std::fabsf(std::sqrtf(1 + std::powf(rayDirection.y / rayDirection.x, 2))),
        std::fabsf(std::sqrtf(1 + std::powf(rayDirection.x / rayDirection.y, 2)))
    };

    auto testPos = Vector2{std::floor(startPoint.x), std::floor(startPoint.y)};

    float currentXRayLength;
    float currentYRayLength;
    float stepX;
    float stepY;

    if (rayDirection.x < 0) {
        stepX = -1;
        currentXRayLength = (startPoint.x - testPos.x) * unitStepValues.x;
    } else {
        stepX = 1;
        currentXRayLength = (testPos.x + 1 - startPoint.x) * unitStepValues.x;
    }

    if (rayDirection.y < 0) {
        stepY = -1;
        currentYRayLength = (startPoint.y - testPos.y) * unitStepValues.y;
    } else {
        stepY = 1;
        currentYRayLength = (testPos.y + 1 - startPoint.y) * unitStepValues.y;
    }

    float rayLength = 0;
    while (testPos.x < map.getHorizontalSize() && testPos.y < map.getVerticalSize()) {
        if (currentXRayLength < currentYRayLength) {
            testPos.x += stepX;
            rayLength = currentXRayLength;
            currentXRayLength += unitStepValues.x;
        } else if (currentXRayLength > currentYRayLength) {
            testPos.y += stepY;
            rayLength = currentYRayLength;
            currentYRayLength += unitStepValues.y;
        } else {
            testPos.x += stepX;
            currentXRayLength += unitStepValues.x;
            testPos.y += stepY;
            rayLength = currentYRayLength;
            currentYRayLength += unitStepValues.y;
        }

        if (map.getMapDataFromRelPos(testPos)) {
            break;
        }
    }

    return Vector2Add(startPoint, Vector2Multiply(rayDirection, {rayLength, rayLength}));
}