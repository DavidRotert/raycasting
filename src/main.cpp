#include <iostream>

#include "raylib.h"

#include "Game.hpp"
#include "Map.hpp"
#include "Player.hpp"

int main()
{
    auto player = Player{
        Vector2{
            7 * (MAP_SQUARE_SIZE + MAP_GAP_SIZE) + MAP_SQUARE_SIZE / 2.0,
            2 * (MAP_SQUARE_SIZE + MAP_GAP_SIZE) + MAP_SQUARE_SIZE / 2.0
        },
        0 * DEG2RAD,
    };
    auto mapData = std::array<MapDataType, MAP_SIZE_HORIZONTAL * MAP_SIZE_VERTICAL>{
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
    auto map = Map(MAP_SIZE_HORIZONTAL, MAP_SIZE_VERTICAL, mapData);

    auto game = Game(player, map);
    game.gameLoop();

    return 0;
}