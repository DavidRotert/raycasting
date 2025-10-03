#include "raycasting.hpp"

#include <cmath>
#include <iostream>

#include "catch2/catch_test_macros.hpp"
#include "catch2/generators/catch_generators.hpp"

TEST_CASE("Test pythagoras scale diagonal", "[vectormath]")
{
    auto actual = Vector2PythagorasScale(Vector2{1, 1}, Vector2{9, 9});
    auto expected = Vector2{sqrtf(2), sqrtf(2)};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test perfect diagonal", "[raycasting]")
{
    std::array<MapDataType, MAP_SIZE_HORIZONTAL * MAP_SIZE_VERTICAL> mapData = {
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
    auto map = Map(10, 10, mapData);
    auto actual = cast_ray_with_path(map, Vector2{1, 1}, Vector2{9, 9});
    int i = 1;
    for (const auto value : actual)
    {
        REQUIRE(map.calcIndexFromRelPos(value) == i * 11);
        i++;
        std::cout << std::format("x: {}, y: {}", value.x, value.y) << std::endl;
    }
}

TEST_CASE("Raycasting test diagonal", "[raycasting]")
{
    std::array<MapDataType, 7 * 4> mapData = {
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0
    };
    auto map = Map(7, 4, mapData);
    auto actual = cast_ray_with_path(map, Vector2{0, 0}, Vector2{6, 3});
    auto expected = std::array{
        Vector2{0, 0},
        Vector2{1, 0},
        Vector2{2, 0},
        Vector2{2, 1},
        Vector2{3, 1},
        Vector2{4, 1},
        Vector2{5, 2},

    };
    for (int i = 0; i < expected.size(); i++)
    {
        REQUIRE(actual.at(i).x == expected.at(i).x);
        REQUIRE(actual.at(i).y == expected.at(i).y);

        std::cout << std::format("x: {}, y: {}", actual.at(i).x, actual.at(i).y) << std::endl;
    }
}
