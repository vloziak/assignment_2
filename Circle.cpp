#include "Circle.h"
#include <iostream>
#include <math.h>

Circle::Circle(int centerX, int centerY, int radius) : centerX(centerX), centerY(centerY), radius(radius) {}

void Circle::draw(std::vector<std::vector<char> >& grid) const {
    for (int x = 0; x <= 2 * radius; x++) {
        for (int y = 0; y <= 2 * radius; y++) {
            double distance = sqrt((x - radius) * (x - radius) + (y - radius) * (y - radius));

            if (distance > radius - 0.65 && distance < radius + 0.2) {

                if (x >= 0 && y < grid[0].size() && y >= 0 && y < grid.size()) {
                    grid[y][x] = '*';
                }
            }
        }
    }
}


std::string Circle::getInfoForConsole() const {
    return "ID: " + std::to_string(getId()) + ", Type: Circle, Coordinates: (" +
           std::to_string(centerX) + ", " + std::to_string(centerY) + "), Radius: " +
           std::to_string(radius);
}

std::string Circle::getInfoForFile() const {
    return std::to_string(getId()) + " Circle " +
           std::to_string(centerX) + " " +
           std::to_string(centerY) + " " +
           std::to_string(radius);
}