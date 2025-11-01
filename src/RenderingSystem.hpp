#pragma once

#include <vector>

#include "Player.hpp"
#include "Map.hpp"
#include "raycasting.hpp"


class RenderingSystem
{
    const Player& player;
    const Map& map;

public:
    RenderingSystem(const Player& player, const Map& map);

    void render(const std::vector<RayCastResult>& rayCastResults) const;
};
