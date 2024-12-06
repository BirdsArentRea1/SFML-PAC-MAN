#include "Level.h"

void Level::draw(RenderWindow& window) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            int tileValue = layout[row][col];

            Color tileColor = (tileValue == 1) ? Color::Blue : Color::Black;

            RectangleShape tile(Vector2f(tileSize, tileSize));
            tile.setFillColor(tileColor);
            tile.setPosition(col * tileSize, row * tileSize);
            window.draw(tile);
        }
    }
}

int Level::getTileValue(int row, int col) const {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return layout[row][col];
    }
    return -1;
}
