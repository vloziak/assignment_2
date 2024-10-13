#include "Square.h"

Square::Square(int x, int y, int width, int height): x(x), y(y), width(width), height(height) {
}
void Square::draw(std::vector<std::vector<char> >& grid) const {
    if (width <= 0 || height <= 0) return;

    for (int j = 0; j < width; ++j) {
        if (y >= 0 && y < grid.size()) {
            if (x + j >= 0 && x + j < grid[0].size()) {
                grid[y][x + j] = '*';
            }
            if (y + height - 1 < grid.size()) {
                if (x + j >= 0 && x + j < grid[0].size()) {
                    grid[y + height - 1][x + j] = '*';
                }
            }
        }
    }

    for (int i = 1; i < height - 1; ++i) {
        if (y + i >= 0 && y + i < grid.size()) {
            if (x >= 0 && x < grid[0].size()) {
                grid[y + i][x] = '*';
            }
            if (x + width - 1 >= 0 && x + width - 1 < grid[0].size()) {
                grid[y + i][x + width - 1] = '*';
            }
        }
    }
}

std::string Square::getInfoForConsole() const {
    return "ID: " + std::to_string(getId()) + ", Type: Square, Coordinates: (" +
           std::to_string(x) + ", " + std::to_string(y) + "), Width: " +
           std::to_string(width) + ", Height: " + std::to_string(height);
}

std::string Square::getInfoForFile() const {
    return std::to_string(getId()) + " Square " +
           std::to_string(x) + " " +
           std::to_string(y) + " " +
           std::to_string(width) + " " +
           std::to_string(height);
}