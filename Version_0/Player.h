#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Player {
public:
	Player();
	void move(float deltaX, float deltaY);
	void draw(RenderWindow& window);

private:
	CircleShape shape;
};
