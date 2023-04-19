#include <cmath>

#include "Planet/Planet.h"
#include "Planet/PlanetSystem/PlanetSystem.h"

using namespace SunSystem;
using namespace sf;

double angle(double angularVelocity, double factor = 1.0);

int main() {
    Planet sun    (1.9891e30, {    695e6}),
           mercury(  3.33e23, { 2439.7e3}),
           venus  (  4.87e24, { 6051.8e3}),
           earth  (5.9736e24, { 6371.3e3}),
           moon   (  7.35e22, { 1737.1e3}),
           mars   (  6.43e23, { 3389.5e3});
    sun    .setFillColor(Color::White);
    mercury.setFillColor(Color(240, 207, 108));
    earth  .setFillColor(Color::Blue);
    moon   .setFillColor(Color(124, 124, 124));
    mars   .setFillColor(Color::Red);

    PlanetSystem sunSystem
    {sun,
        {
            {  57.9e9, { mercury } },
            {-108.2e9, { venus   } },
            { 149.6e9, { earth , {{ 380e6, moon }} } },
            { 228.0e9, { mars    } }
        }
    };

    Vector2<double> center(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2);

    double boost = 1e-7;
    double factorDistance = std::min(center.x, center.y) / 235e9;

    sunSystem.scale(factorDistance);
    sunSystem.setPosition(center.x, center.y);

    srand(time(nullptr));
    VertexArray stars(Points, 50);
    for (int i = 0; i < 48; i++) {
        stars[i].color = sf::Color(255, 255, 255, 90);
        stars[i].position = Vector2f(rand() % VideoMode::getDesktopMode().width,
                                     rand() % VideoMode::getDesktopMode().height);
    }

    RenderWindow window(VideoMode(VideoMode::getDesktopMode()), "Sun system", Style::Fullscreen);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        window.clear(sf::Color::Black);
        window.draw(stars);

        sunSystem.accept(std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count() * boost);
        window.draw(sunSystem);

        window.display();
    }
    return 0;
}
