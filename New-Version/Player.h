#pragma once
#include <SFML/Graphics.hpp>
#include "level.h"
using namespace sf;

class Player {
private:
    float x;
    float y;
    float vx;
    float vy;
    float speed;
    float size;

public:

    Player(float startX, float startY);
    void handleInput();
    void update(float deltaTime, const Level& level);
    void draw(RenderWindow& window);

};
