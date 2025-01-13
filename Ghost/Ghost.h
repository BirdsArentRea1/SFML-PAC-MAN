#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"

using namespace sf;

class Ghost {
private:
    float x, y;         
    float speed;        
    float size;         
    float vx, vy;       
    int direction;


public:
    Ghost(float startX, float startY);
    void update(float deltaTime, const Player& player, const Level& level);
    void draw(RenderWindow& window);
};
