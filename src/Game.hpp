#pragma once

#include "Player.hpp"
#include "Map.hpp"
#include "RenderingSystem.hpp"

constexpr int RESOLUTION = 800;
constexpr int WINDOW_DEBUG_AREA_WIDTH = MAP_GRID_SIZE_HORIZONTAL * (MAP_GRID_GAP_SIZE + MAP_GRID_SQUARE_SIZE);
constexpr int WINDOW_WIDTH = WINDOW_DEBUG_AREA_WIDTH + RESOLUTION;
constexpr int WINDOW_HEIGHT = 600;

class Game
{
    Player player;
    Map map;
    RenderingSystem renderingSystem;

public:
    Game(Player& player, Map& map);
    void gameLoop();
};