#ifndef RAYCASTING_RAYCASTING_HPP
#define RAYCASTING_RAYCASTING_HPP

#include <vector>

#include "raylib.h"
#include "Map.hpp"

Vector2 Vector2Delta(Vector2 a, Vector2 b);
Vector2 Vector2PythagorasScale(Vector2 a, Vector2 b);

std::vector<Vector2> cast_ray_with_path(const Map& map, Vector2 startPoint, Vector2 direction);

#endif //RAYCASTING_RAYCASTING_HPP
