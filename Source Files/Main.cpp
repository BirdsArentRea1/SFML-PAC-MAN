#include <SFML/Graphics.hpp>
#include "Player.h"
#include "level.h"
using namespace std;

void handleInput(Player& player, float deltatime) {
    float speed = 200.0f; //200 pixels per second
    if (Keyboard::isKeyPressed(Keyboard::Left)) player.move(-1, 0);
    if (Keyboard::isKeyPressed(Keyboard::Right)) player.move(1, 0);
    if (Keyboard::isKeyPressed(Keyboard::Up)) player.move(0, -1);
    if (Keyboard::isKeyPressed(Keyboard::Down)) player.move(0, 1);
}


int main() {
    RenderWindow window(VideoMode(600, 800), "PACMAN Game");
    Player player;
    Clock clock;
    Level level;

    while (window.isOpen()) {
        float deltatime = clock.restart().asSeconds();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        handleInput(player, deltatime);

        window.clear();

        player.draw(window);

        level.draw(window);

        window.display();
    }

    return 0;
}
