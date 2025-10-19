#pragma once

#include "raylib.h"
#include "Map.hpp"

struct RayCastResult
{
    Vector2 rayIntersection;
    MapDataType mapDataAtHit;
    float rayLength;
};

RayCastResult cast_ray(const Map& map, Vector2 startPoint, Vector2 directionPoint);
