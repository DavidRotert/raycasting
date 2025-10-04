#ifndef RAYCASTING_RAYCASTING_HPP
#define RAYCASTING_RAYCASTING_HPP

#include "raylib.h"
#include "Map.hpp"

Vector2 cast_ray(const Map& map, Vector2 startPoint, Vector2 directionPoint);

#endif //RAYCASTING_RAYCASTING_HPP
