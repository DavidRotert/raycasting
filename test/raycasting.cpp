#include "raycasting.hpp"

#include <cmath>

#include "catch2/catch_test_macros.hpp"

TEST_CASE("Test pythagoras scale", "[vectormath]")
{
    auto actual = Vector2PythagorasScale(Vector2{0, 0}, Vector2{9, 9});
    auto expected = Vector2{sqrtf(2), sqrtf(2)};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test diagonal", "[raycasting]")
{
    auto map = Map{
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    auto actual = cast_ray_with_path(map, MAP_SIZE_HORIZONTAL, MAP_SIZE_VERTICAL, Vector2{0, 0}, Vector2{9, 9});

    int i = 0;
    for (const auto value : actual)
    {
        REQUIRE(value == i * 11);
        i++;
    }
}
