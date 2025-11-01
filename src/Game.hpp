#pragma once

#include "Map.hpp"
#include "Player.hpp"
#include "RaycastingSystem.hpp"
#include "RenderingSystem.hpp"

constexpr int RESOLUTION = 800;
constexpr int WINDOW_DEBUG_AREA_WIDTH = MAP_GRID_SIZE_HORIZONTAL * (MAP_GRID_GAP_SIZE + MAP_GRID_SQUARE_SIZE);
constexpr int WINDOW_WIDTH = WINDOW_DEBUG_AREA_WIDTH + RESOLUTION;
constexpr int WINDOW_HEIGHT = 600;

class Game
{
    Player player;
    const Map map;
    RaycastingSystem raycastingSystem;
    RenderingSystem renderingSystem;

public:
    Game(const Player& player, const Map& map);
    void gameLoop();
};