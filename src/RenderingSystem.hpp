#ifndef RAYCASTING_RENDERINGSYSTEM_H
#define RAYCASTING_RENDERINGSYSTEM_H

#include "Player.hpp"
#include "Map.hpp"


struct RenderingSystem
{
    Player& player;
    Map& map;

    void render() const;
};

#endif //RAYCASTING_RENDERINGSYSTEM_H