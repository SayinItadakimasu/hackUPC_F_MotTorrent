#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

class player {
private:
    RectangleShape rect;
public:
    player(const Vector2f& size, const Vector2f& pos) {
        rect.setSize(size);
        rect.setPosition(pos);
    }

    void move(const Vector2f& pos) {
        rect.move(pos);
    }
    RectangleShape shape() {
        return rect;
    }
};

int main()
{
    RenderWindow window(VideoMode(1024, 720), "My window");
    player p1(Vector2f(50, 50), Vector2f(100, 100));

    while(window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape) window.close();
                else if (event.key.code == Keyboard::Left) p1.move(Vector2f(-4,0));
                else if (event.key.code == Keyboard::Right) p1.move(Vector2f(4,0));
                else if (event.key.code == Keyboard::Up) p1.move(Vector2f(0,-4));
                else if (event.key.code == Keyboard::Down) p1.move(Vector2f(0,4));
                break;
            default: break;
            }


            if (event.type == Event::KeyPressed and event.key.code == Keyboard::Escape) {
                window.close();
            }

        }
        window.clear(Color::Black);
        window.draw(p1.shape());
        window.display();
      }

    return 0;
}

