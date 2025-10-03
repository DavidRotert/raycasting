#include <iostream>

#include "raylib.h"

#include "Game.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "raycasting.hpp"

int main()
{
    auto player = Player{
        .pos = Vector2{
            7 * (MAP_SQUARE_SIZE + MAP_GAP_SIZE) + MAP_SQUARE_SIZE / 2.0,
            2 * (MAP_SQUARE_SIZE + MAP_GAP_SIZE) + MAP_SQUARE_SIZE / 2.0
        },
        .rotationAngleRadian = 0 * DEG2RAD,
    };
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

    auto game = Game(player, map);
    game.gameLoop();

    return 0;
}
