#include "utils.hpp"

#include "raymath.h"

radian absolute_radian(radian angle)
{
    if (angle > 2 * PI) {
        angle = angle - 2 * PI;
    } else if (angle < 0) {
        angle = 2 * PI + angle;
    }

    return angle;
}
