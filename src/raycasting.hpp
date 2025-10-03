#ifndef RAYCASTING_RAYCASTING_HPP
#define RAYCASTING_RAYCASTING_HPP

#include "raylib.h"
#include "utils.hpp"

struct RayIntersectionPair
{
    Vector2 intersect1;
    Vector2 intersect2;
};

RayIntersectionPair get_first_ray_intersection(Vector2 startPosition, radian rotationAngle);


int add(int a, int b);

#endif //RAYCASTING_RAYCASTING_HPP
