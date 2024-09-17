#include "Player.h"

Player::Player() {
	shape.setRadius(15);
	shape.setFillColor(Color::Yellow);
	shape.setPosition(100, 100);
}

void Player::move(float deltaX, float deltaY) {
	shape.move(deltaX, deltaY);
}

void Player::draw(RenderWindow& window) {
	window.draw(shape);
}
