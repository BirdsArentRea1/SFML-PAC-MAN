#include <SFML/Graphics.hpp>
#include "Player.h"
#include "level.h"
using namespace std;

int main() {
    RenderWindow window(VideoMode(760, 1100), "PACMAN");
    Player player(370,730);
    Clock clock;
    Level level;

    while (window.isOpen()) {
        float deltatime = clock.restart().asSeconds();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        player.handleInput();
        player.update(deltatime, level);

        window.clear();
        level.draw(window);
        player.draw(window);
        window.display();
    }

}
