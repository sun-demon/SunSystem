#include "CenteredCircleShape/CenteredCircleShape.h"

namespace SunSystem {
    CenteredCircleShape::CenteredCircleShape(float radius, std::size_t pointCount)
    : sf::CircleShape(radius, pointCount) {
        setOrigin(radius, radius);
    }
}