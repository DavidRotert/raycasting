#include "RenderingSystem.hpp"

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

    DrawFPS(10, 10);

    EndDrawing();
}