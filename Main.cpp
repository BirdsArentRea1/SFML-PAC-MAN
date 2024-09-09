#include <SFML/Graphics.hpp>
using namespace sf;


int main() {
    RenderWindow window(VideoMode(800, 600), "PACMAN Game");

    while (window.isOpen()) {

        Event event;
        while (window.poll(event)) {
            if (event.type == Event::Closed)
            window.close();
        }

        window.clear();

        window.display();
    }

    return 0;
}
