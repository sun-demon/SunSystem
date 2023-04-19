#ifndef SUNSYSTEM_PLANET_H
#define SUNSYSTEM_PLANET_H


#include "CenteredCircleShape/CenteredCircleShape.h"

namespace SunSystem {
    class Planet : public CenteredCircleShape {
    public:
        Planet(double mass, CenteredCircleShape shape);

        double getMass() const;

        void setMass(double mass);

    private:
        double mass_;
    };
}


#endif //SUNSYSTEM_PLANET_H
