#include "RenderingSystem.hpp"

#include "raycasting.hpp"

void RenderingSystem::render() const
{
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < MAP_SIZE_VERTICAL * MAP_SIZE_HORIZONTAL; i++)
    {
        const MapDataType mapData = map.getMapDataAtIndex(i);

        Color color = GRAY;
        if (mapData != 0)
        {
            color = WHITE;
        }

        DrawRectangle(
            (MAP_SQUARE_SIZE + MAP_GAP_SIZE) * (i % MAP_SIZE_HORIZONTAL),
            (MAP_SQUARE_SIZE + MAP_GAP_SIZE) * (i / MAP_SIZE_VERTICAL),
            MAP_SQUARE_SIZE,
            MAP_SQUARE_SIZE,
            color
        );
    }

    this->player.draw();

    // Draw ray intersection
    auto relativeRayIntersection = cast_ray(this->map, this->player.getPositionRelativeToMap(), get_position_relative_to_map(this->player.getRotationAsNonNormalizedVector()));
    auto rayIntersection = get_absolute_position_on_map(relativeRayIntersection);
    DrawLineV(this->player.pos, rayIntersection, YELLOW);
    DrawCircleV(rayIntersection, 2, GREEN);

    DrawFPS(10, 10);

    EndDrawing();
}
