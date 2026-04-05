#include <SFML/Graphics.hpp>
#include "game.h"

#define windowWidth 1000
#define windowHeight 1000


int main()
{
    sf::RenderWindow window(sf::VideoMode({ windowWidth, windowHeight }), "Simulation");
    window.setVerticalSyncEnabled(true);
    sf::Vector2f Size = sf::Vector2f(200, 200);
    sf::RectangleShape shape(Size);
    shape.setFillColor(sf::Color::Red);

    game simulation(window, windowWidth, windowHeight);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            simulation.handleEvents(event);
        }
        simulation.update();

        window.clear();
        simulation.draw();
        window.display();
    }
}