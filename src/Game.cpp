#include "Game.hpp"

Game::Game(Player& player, Map& map) :
    player(player),
    map(map),
    renderingSystem(RenderingSystem{this->player, this->map})
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raycasting");
    SetTargetFPS(60);
}

void Game::gameLoop()
{
    while (!WindowShouldClose())
    {
        // Move and rotate
        if (IsKeyDown(KEY_RIGHT))
        {
            player.rotate(- 5 * DEG2RAD);
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            player.rotate(5 * DEG2RAD);
        }

        renderingSystem.render();
    }

    CloseWindow();
}
