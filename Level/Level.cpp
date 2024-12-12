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

            if (tileValue == 2) {
                RectangleShape pellet(Vector2f(pelletSize, pelletSize));
                pellet.setFillColor(Color::White);
                pellet.setPosition(col * tileSize + (tileSize - pelletSize) / 2, row * tileSize + (tileSize - pelletSize) / 2);
                window.draw(pellet);
            }
        }
    }
}

int Level::getTileValue(int row, int col) const {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return layout[row][col];
    }
    return -1;
}

void Level::removePellet(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        layout[row][col] = 0;
    }
}
