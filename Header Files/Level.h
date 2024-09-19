#pragma once
#include<SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Level {
public:
	Level();
	void loadlevel();
	void draw(RenderWindow& window);
		
private:
	std::vector<RectangleShape> walls;
	const int tileSize = 32;

};
