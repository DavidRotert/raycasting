#include "Game.hpp"

constexpr int PLAYER_MOVEMENT_SPEED = 2;

Game::Game(const Player& player, const Map& map):
    player(player),
    map(map),
    raycastingSystem(RaycastingSystem(RESOLUTION, this->player, this->map)),
    renderingSystem(RenderingSystem(this->player, this->map))
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raycasting");
    SetTargetFPS(60);
}

void Game::gameLoop()
{
    while (!WindowShouldClose()) {
        // Rotate player
        if (IsKeyDown(KEY_RIGHT)) {
            player.rotate(-1 * DEG2RAD);
        } else if (IsKeyDown(KEY_LEFT)) {
            player.rotate(1 * DEG2RAD);
        }

        // Move Player
        float movementDelta = GetFrameTime() * PLAYER_MOVEMENT_SPEED;
        /*if (IsKeyDown(KEY_W)) {
            player.move(VECTOR2_UP(movementDelta));
        } else if (IsKeyDown(KEY_S)) {
            player.move(VECTOR2_DOWN(movementDelta));
        } else if (IsKeyDown(KEY_A)) {
            player.move(VECTOR2_LEFT(movementDelta));
        } else if (IsKeyDown(KEY_D)) {
            player.move(VECTOR2_RIGHT(movementDelta));
        }*/

        if (IsKeyDown(KEY_W)) {
            player.move(movementDelta, this->player.rotationAngleRadian);
        } else if (IsKeyDown(KEY_S)) {
            player.move(movementDelta, absolute_radian(this->player.rotationAngleRadian - 180 * DEG2RAD));
        } else if (IsKeyDown(KEY_A)) {
            player.move(movementDelta, absolute_radian(this->player.rotationAngleRadian - 90 * DEG2RAD));
        } else if (IsKeyDown(KEY_D)) {
            player.move(movementDelta, absolute_radian(this->player.rotationAngleRadian + 90 * DEG2RAD));
        }

        this->raycastingSystem.calculateRays();

        auto rayCastResults = this->raycastingSystem.getRayCastResults();
        this->renderingSystem.render(rayCastResults);
    }

    CloseWindow();
}