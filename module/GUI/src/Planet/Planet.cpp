#include "Planet/Planet.h"

namespace SunSystem {
    Planet::Planet(double mass, CenteredCircleShape shape)
    : mass_(mass), CenteredCircleShape(std::move(shape)) {}

    double Planet::getMass() const { return mass_;  }

    void Planet::setMass (double mass)  { mass_  = mass; }
}