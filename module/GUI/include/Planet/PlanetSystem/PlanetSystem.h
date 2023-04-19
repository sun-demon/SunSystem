#ifndef SUNSYSTEM_PLANETSYSTEM_H
#define SUNSYSTEM_PLANETSYSTEM_H


#include <vector>
#include <initializer_list>
#include <chrono>

#include "Planet/Planet.h"
#include "FunctionalInterface/IConsumer.h"

namespace SunSystem {
    class Orbit;


    class PlanetSystem : public Planet, public IConsumer<double> {
    public:
        PlanetSystem(Planet planet, std::initializer_list<Orbit> orbits = {});

        const std::vector<Orbit> & getOrbits() const;

        void setOrbits(const std::vector<Orbit> & orbits);

        void scale(float factor);

        void accept(double time) override;

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        std::vector<Orbit> orbits_;
    };


    class Orbit {
    public:
        Orbit(double distance, PlanetSystem planetSystem);

        double getDistance() const;
        const PlanetSystem & getPlanetSystem() const;
        PlanetSystem & getPlanetSystem();

        void setDistance(double distance);
        void setPlanetSystem(const PlanetSystem & planetSystem);

    private:
        double distance_;
        PlanetSystem planetSystem_;
    };
}


#endif //SUNSYSTEM_PLANETSYSTEM_H
