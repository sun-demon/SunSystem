#include "Planet/PlanetSystem/PlanetSystem.h"

#include <cmath>

namespace SunSystem {
    const double GRAVITATIONAL_CONSTANT = 6.67430e-11;


    PlanetSystem::PlanetSystem(Planet planet, std::initializer_list<Orbit> orbits)
    : Planet(std::move(planet)), orbits_(orbits) {}

    const std::vector<Orbit> & PlanetSystem::getOrbits() const { return orbits_; }

    void PlanetSystem::setOrbits(const std::vector<Orbit> & orbits) { orbits_ = orbits; }

    void PlanetSystem::scale(float factor) {
        Planet::scale(factor, factor);
        for (auto &orbit: orbits_) {
            orbit.setDistance(orbit.getDistance() * factor);
            orbit.getPlanetSystem().scale(factor);
        }
    }

    void PlanetSystem::accept(double time) {
        for (auto & orbit : orbits_) {
            double angle = pow(GRAVITATIONAL_CONSTANT * getMass() / pow(fabs(orbit.getDistance()), 3), 0.5) * time;
            sf::Vector2f radiusVector(fabs(orbit.getDistance()) * cos(angle), -orbit.getDistance() * sin(angle));
            if (hypot(radiusVector.x, radiusVector.y) < 1)
                radiusVector = sf::Vector2f(radiusVector.x * 50, radiusVector.y * 50);
            orbit.getPlanetSystem().setPosition(getPosition() + radiusVector);
            orbit.getPlanetSystem().accept(time);
        }
    }

    void PlanetSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        for (double radius = getRadius() * getScale().x; radius < log2(getRadius())* getScale().x * 0.5e9; radius *= 1.25) {
            CenteredCircleShape atmosphere(radius);
            atmosphere.setPosition((getPosition()));
            atmosphere.setFillColor(sf::Color(getFillColor().r, getFillColor().g, getFillColor().b, 6));
            target.draw(atmosphere);
        }
        target.draw(Planet(*this));

        for (auto & orbit : orbits_) {
            CenteredCircleShape line(fabs(orbit.getDistance()) - 0.5, 60);
            line.setOutlineThickness(1);
            line.setOutlineColor(sf::Color(255, 255, 255, 10));
            line.setFillColor(sf::Color(0, 0, 0, 0));
            line.setPosition(getPosition());
            target.draw(line);
            target.draw(orbit.getPlanetSystem());
        }
    }


    Orbit::Orbit(double distance, PlanetSystem planetSystem)
    : distance_(distance), planetSystem_(std::move(planetSystem)) {}

    double               Orbit::getDistance()     const { return distance_;     }
    const PlanetSystem & Orbit::getPlanetSystem() const { return planetSystem_; }
    PlanetSystem &       Orbit::getPlanetSystem()       { return planetSystem_; }

    void Orbit::setDistance    (double               distance)     { distance_     = distance;     }
    void Orbit::setPlanetSystem(const PlanetSystem & planetSystem) { planetSystem_ = planetSystem; }
}