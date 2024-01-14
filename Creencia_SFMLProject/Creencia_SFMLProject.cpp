#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Application");
    sf::CircleShape shape(100.f);
    sf::CircleShape shape2(500.f);

    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Red);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(shape2);

        window.display();
    }

    return 0;
}