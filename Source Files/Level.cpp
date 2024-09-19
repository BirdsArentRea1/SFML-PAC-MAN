#include "Level.h"
using namespace std;

Level::Level() {
	loadlevel();
	
}

void Level::draw(RenderWindow& window) {
	for (int i = 0; i < walls.size(); i++) {
		window.draw(walls[i]);
	}
}

void Level::loadlevel() {
	int levelData[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (levelData[y][x] == 1) {
				RectangleShape wall(Vector2f(tileSize, tileSize));
				wall.setFillColor(Color::Blue);
				wall.setPosition(x * tileSize, y * tileSize);
				walls.push_back(wall);
			}
		}
	}
}
