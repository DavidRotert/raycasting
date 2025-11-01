#pragma once

#include <vector>

#include "Player.hpp"
#include "raycasting.hpp"

class RaycastingSystem
{
    const int horizontalResolution;
    const Player& player;
    const Map& map;
    std::vector<RayCastResult> rayCastResults;

public:
    RaycastingSystem(int horizontalResolution, const Player& player, const Map& map);

    void calculateRays();
    std::vector<RayCastResult> getRayCastResults() const;
};
