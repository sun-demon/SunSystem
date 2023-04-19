#ifndef SUNSYSTEM_CENTEREDCIRCLESHAPE_H
#define SUNSYSTEM_CENTEREDCIRCLESHAPE_H


#include <SFML/Graphics.hpp>

namespace SunSystem {
    class CenteredCircleShape : public sf::CircleShape {
    public:
        CenteredCircleShape(float radius = 0, std::size_t pointCount = 30);
    };
}


#endif //SUNSYSTEM_CENTEREDCIRCLESHAPE_H
