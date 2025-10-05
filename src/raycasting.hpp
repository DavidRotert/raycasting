#pragma once

#include "raylib.h"
#include "Map.hpp"

Vector2 cast_ray(const Map& map, Vector2 startPoint, Vector2 directionPoint);