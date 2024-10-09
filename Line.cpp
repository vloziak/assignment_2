#include "Line.h"
#include <cmath>
Line::Line(int startX, int startY, int length, double angle) : startX(startX), startY(startY), length(length), angle(angle) {}

void Line::draw(std::vector<std::vector<char> >& grid) const {
    double radians = angle * M_PI / 180.0;

    for (int i = 0; i <= length; ++i) {
        int posX = static_cast<int>(startX + i * cos(radians));
        int posY = static_cast<int>(startY + i * sin(radians));

        if (posX >= 0 && posX < grid[0].size() && posY >= 0 && posY < grid.size()) {
            grid[posY][posX] = '*';
        }
    }
}

std::string Line::getInfo() const {
    return "ID: " + std::to_string(id) + ", Type: Line, Coordinates: (" +
           std::to_string(startX) + ", " + std::to_string(startY) + "), Length: " +
           std::to_string(length) + ", Angle: " + std::to_string(angle);
}