#pragma once

#define VECTOR2_RIGHT(value) Vector2{value, 0}
#define VECTOR2_LEFT(value) Vector2{-value, 0}
#define VECTOR2_DOWN(value) Vector2{0, value}
#define VECTOR2_UP(value) Vector2{0, -value}

typedef float radian;

/**
 * Gets the absolute radian so that radian values can be smaller than 0 and larger than 2PI. It makes calculations easier.
 * @param angle
 * @return
 */
radian absolute_radian(radian angle);
