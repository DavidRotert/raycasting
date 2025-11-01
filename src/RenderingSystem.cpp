#include "RenderingSystem.hpp"

#include "Game.hpp"
#include "raycasting.hpp"
#include "raymath.h"

constexpr float DARKNESS_FACTOR = 13.0;
constexpr float PIXEL_COLUMN_HEIGHT_FACTOR = 1.3;

RenderingSystem::RenderingSystem(const Player& player, const Map& map): player(player), map(map) {}


void RenderingSystem::render(const std::vector<RayCastResult>& rayCastResults) const
{
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < MAP_GRID_SIZE_VERTICAL * MAP_GRID_SIZE_HORIZONTAL; i++) {
        const MapDataType mapData = map.getMapDataAtIndex(i);

        Color color = GRAY;
        if (mapData != 0) {
            color = WHITE;
        }

        DrawRectangle(
            (MAP_GRID_SQUARE_SIZE + MAP_GRID_GAP_SIZE) * (i % MAP_GRID_SIZE_HORIZONTAL),
            (MAP_GRID_SQUARE_SIZE + MAP_GRID_GAP_SIZE) * (i / MAP_GRID_SIZE_VERTICAL),
            MAP_GRID_SQUARE_SIZE,
            MAP_GRID_SQUARE_SIZE,
            color
        );
    }

    // Draw 2D debug player
    DrawCircleV(this->player.getDebugGridPosition(), MAP_GRID_SQUARE_SIZE * 0.3, GREEN);

    // Draw rays
    radian startAngle = absolute_radian(this->player.rotationAngleRadian - (this->player.fov / 2));
    for (int i = 0; i < rayCastResults.capacity(); i++) {
        const RayCastResult rayCastResult = rayCastResults.at(i);

        const Vector2 rayIntersection = get_absolute_position_on_map(rayCastResult.rayIntersection);
        const float rayLength = rayCastResult.rayLength;

        // Render 3D
        const float pixelColumnHeight = (WINDOW_HEIGHT / rayLength) * PIXEL_COLUMN_HEIGHT_FACTOR;
        DrawLineV(
            Vector2Subtract(
                Vector2{static_cast<float>(WINDOW_DEBUG_AREA_WIDTH + i), static_cast<float>(WINDOW_HEIGHT / 2)},
                Vector2{0, pixelColumnHeight / 2}
            ),
            Vector2Add(
                Vector2{static_cast<float>(WINDOW_DEBUG_AREA_WIDTH + i),static_cast<float>(WINDOW_HEIGHT / 2)},
                Vector2{0, pixelColumnHeight / 2}
            ),
            ColorBrightness(BROWN, -(rayLength / DARKNESS_FACTOR))
        );

        // Render 2D debug map
        DrawLineV(this->player.getDebugGridPosition(), rayIntersection, YELLOW);
        DrawCircleV(rayIntersection, 2, GREEN);
    }

    DrawFPS(10, 10);

    EndDrawing();
}
