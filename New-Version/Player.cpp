#include "Player.h"
#include "level.h"
#include<iostream>
using namespace std;

Player::Player(float startX, float startY) {
	x = startX;
	y = startY;
	vx = 0;
	vy = 0;
	speed = 200;
	size = 20;
}

void Player::handleInput() {
	vx = 0;
	vy = 0;

	if (Keyboard::isKeyPressed(Keyboard::W)) { vy = -speed; }
	if (Keyboard::isKeyPressed(Keyboard::S)) { vy = speed; }
	if (Keyboard::isKeyPressed(Keyboard::A)) { vx = -speed; }
	if (Keyboard::isKeyPressed(Keyboard::D)) { vx = speed; }
}

void Player::update(float deltaTime, const Level& level) {

	enum DIRECTIONS { RIGHT, LEFT, UP, DOWN, STOP };
	int direction = STOP;

	if (vy < 0) direction = UP; else if (vy > 0) direction = DOWN; else direction = STOP;

	//check for vertical collision
	if (direction == DOWN) {
		if (level.getTileValue(static_cast<int>((y + 30) / 40), static_cast<int>(x / 40)) == 0)
			y += vy * deltaTime;
		else
			cout << "down collision!" << endl;
	}
	else if (direction == UP) {
		if (level.getTileValue(static_cast<int>((y - 10) / 40), static_cast<int>(x / 40)) == 0)
			y += vy * deltaTime;
		else
			cout << "up collision!" << endl;
	}

	//add horizontal collision here
	x += vx * deltaTime;

}

void Player::draw(RenderWindow& window) {
	RectangleShape rectangle(Vector2f(size, size));
	rectangle.setFillColor(Color::Yellow);
	rectangle.setPosition(x, y);
	window.draw(rectangle);
}

/*
Player::Player() {
	shape.setRadius(15);
	shape.setFillColor(Color::Yellow);
	shape.setPosition(288, 576);
}

void Player::move(float deltaX, float deltaY) {
	shape.move(deltaX, deltaY);
}

void Player::draw(RenderWindow& window) {
	window.draw(shape);
}
void handleInput(Player& player, float deltatime) {
	float speed = 200;
	if (Keyboard::isKeyPressed(Keyboard::Left)) player.move(-1, 0);
	if (Keyboard::isKeyPressed(Keyboard::Right)) player.move(1, 0);
	if (Keyboard::isKeyPressed(Keyboard::Up)) player.move(0, -1);
	if (Keyboard::isKeyPressed(Keyboard::Down)) player.move(0, 1);
}*/
