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
	size = 15;
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

	if (vy < 0) direction = UP;
	else if (vy > 0) direction = DOWN;
	else if (vx < 0) direction = LEFT;
	else if (vx > 0) direction = RIGHT;
	else direction = STOP;

	//vertical collision
	if (direction == DOWN) {
		if (level.getTileValue(static_cast<int>((y+30)/40), static_cast<int>(x / 40)) == 0)
			y += vy * deltaTime;
		else if (level.getTileValue(static_cast<int>((y-10)/40), static_cast<int>(x / 40)) == 2)
			y += vy * deltaTime;
		else
			cout << "down collision!" << endl;
	}
	
	else if (direction == UP) {
		if (level.getTileValue(static_cast<int>((y-10)/40), static_cast<int>(x / 40)) == 0)
			y += vy * deltaTime;
		else if (level.getTileValue(static_cast<int>((y ) / 40), static_cast<int>(x / 40)) == 2)
			y += vy * deltaTime;
		else
			cout << "up collision!" << endl;
	}
	x += vx * deltaTime;
	////horizontal collision
	//if (direction == LEFT) {
	//	if (level.getTileValue(static_cast<int>(y/40), static_cast<int>((x-10)/40)) == 0)
	//		x += vx * deltaTime;
	//	else if (level.getTileValue(static_cast<int>(y / 40), static_cast<int>((x-10 )/ 40)) == 2)
	//		x += vx * deltaTime;
	//	else
	//		cout << "left collision!" << endl;
	//}
	//if (direction == RIGHT) {
	//	if (level.getTileValue(static_cast<int>(y / 40), static_cast<int>((x + 30)/ 40)) == 0)
	//		x += vx * deltaTime;
	//	else if (level.getTileValue(static_cast<int>(y / 40), static_cast<int>((x +30) / 40)) == 2)
	//		x += vx * deltaTime;
	//	else
	//		cout << "right collision!" << endl;
	//}

}

void Player::draw(RenderWindow& window) {
	CircleShape circle(size);
	circle.setFillColor(Color::Yellow);
	circle.setPosition(x, y);
	window.draw(circle);
}
