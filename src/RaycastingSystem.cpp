#include "RaycastingSystem.hpp"

#include <cmath>

RaycastingSystem::RaycastingSystem(const int horizontalResolution, const Player& player, const Map& map):
    horizontalResolution(horizontalResolution),
    player(player),
    map(map),
    rayCastResults(std::vector(this->horizontalResolution, RayCastResult{Vector2{0, 0}, 0, 0}))
{}

void RaycastingSystem::calculateRays()
{
    radian absoluteStartAngle = absolute_radian(this->player.rotationAngleRadian - (this->player.fov / 2));
    const radian anglePerRay = (this->player.fov / this->horizontalResolution);

    for (int i = 0; i < this->horizontalResolution; i++) {
        radian currentAngleRelativeToCamera = absolute_radian(std::abs(this->horizontalResolution / 2 - i) * anglePerRay);
        radian currentAbsoluteAngle = absolute_radian(absoluteStartAngle + i * anglePerRay);

        RayCastResult rayCastResult = cast_ray(
            this->map,
            this->player.position,
            this->player.getRotationAsNonNormalizedVector(currentAbsoluteAngle)
        );
        rayCastResult.rayLength = std::cos(currentAngleRelativeToCamera) * rayCastResult.rayLength;
        this->rayCastResults.at(i) = rayCastResult;
    }
}

std::vector<RayCastResult> RaycastingSystem::getRayCastResults() const
{
    return this->rayCastResults;
}