#include "raycasting.hpp"

#include <cmath>

#include "catch2/catch_test_macros.hpp"

TEST_CASE("Raycasting test south east", "[raycasting]")
{
    auto mapData = std::array<MapDataType, 7 * 4>{
        0, 0, 0, 1, 1, 1, 1,
        1, 1, 0, 0, 0, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
    };
    auto map = Map(7, 4, mapData);
    auto actual = cast_ray(map, Vector2{0, 0}, Vector2{5, 2});
    auto expected = Vector2{5, 2};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test south west", "[raycasting]")
{
    auto mapData = std::array<MapDataType, 7 * 4>{
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
    };
    auto map = Map(7, 4, mapData);
    auto actual = cast_ray(map, Vector2{6, 1}, Vector2{1, 3});
    auto expected = Vector2{1, 3};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test north east", "[raycasting]")
{
    auto mapData = std::array<MapDataType, 7 * 4>{
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
    };
    auto map = Map(7, 4, mapData);
    auto actual = cast_ray(map, Vector2{1, 3}, Vector2{6, 1});
    auto expected = Vector2{6, 1};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test north west", "[raycasting]")
{
    auto mapData = std::array<MapDataType, 7 * 4>{
        1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 1, 1, 1,
        1, 1, 1, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1,
    };
    auto map = Map(7, 4, mapData);
    auto actual = cast_ray(map, Vector2{6, 3}, Vector2{1, 1});
    auto expected = Vector2{1, 1};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test south east diagonal", "[raycasting]")
{
    auto mapData = std::array<MapDataType, 7 * 7>{
        0, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 1, 1, 1, 1,
        1, 1, 0, 1, 1, 1, 1,
        1, 1, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 0, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
    };
    auto map = Map(7, 7, mapData);
    auto actual = cast_ray(map, Vector2{0, 0}, Vector2{4, 4});
    auto expected = Vector2{5, 5};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test x axis alignment", "[raycasting]")
{
    auto mapData = std::array<MapDataType, 7 * 7>{
        1, 0, 0, 0, 0, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
    };
    auto map = Map(7, 7, mapData);
    auto actual = cast_ray(map, Vector2{1, 0}, Vector2{6, 0});
    auto expected = Vector2{5, 0};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}

TEST_CASE("Raycasting test y axis alignment", "[raycasting]")
{
    auto mapData = std::array<MapDataType, 7 * 7>{
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 0, 1, 1, 1, 1,
        1, 1, 0, 1, 1, 1, 1,
        1, 1, 0, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
    };
    auto map = Map(7, 7, mapData);
    auto actual = cast_ray(map, Vector2{2, 1}, Vector2{2, 6});
    auto expected = Vector2{2, 4};
    REQUIRE(actual.x == expected.x);
    REQUIRE(actual.y == expected.y);
}
