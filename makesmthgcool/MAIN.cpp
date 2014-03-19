#include <SFML/Graphics.hpp>

sf::RectangleShape shape(sf::Vector2f(100, 100));
sf::Vector2f.setOrigin(20,20);
void updateGame (sf::Time elapsed) {

    const sf::Vector2f origin = shape.getOrigin();
    shape.setOrigin(sf::Vector2f(currentOrigin.x+1, currentOrigin.y+1));
}

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Quadrat Blanc");
    shape.setFillColor(sf::Color::White);
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        updateGame(elapsed);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
