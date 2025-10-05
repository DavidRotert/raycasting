#pragma once

#include "Player.hpp"
#include "Map.hpp"
#include "RenderingSystem.hpp"

constexpr int WINDOW_WIDTH = 800;
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
