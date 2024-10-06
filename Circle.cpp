#include "Circle.h"

Circle::Circle(int centerX, int centerY, int radius) : centerX(centerX), centerY(centerY), radius(radius) {}


void Circle::drawBorders(std::vector<std::vector<char> >& grid, int centerX, int centerY, int x, int y) const {
    if (centerX + x < grid[0].size() && centerY + y < grid.size())
        grid[centerY + y][centerX + x] = '*';
    if (centerX - x >= 0 && centerY + y < grid.size())
        grid[centerY + y][centerX - x] = '*';
    if (centerX + x < grid[0].size() && centerY - y >= 0)
        grid[centerY - y][centerX + x] = '*';
    if (centerX - x >= 0 && centerY - y >= 0)
        grid[centerY - y][centerX - x] = '*';
}

void Circle::draw(std::vector<std::vector<char> >& grid) const {
    int x = radius;
    int y = 0;
    int radiusError = 1 - radius;

    while (x >= y) {
        drawBorders(grid, centerX, centerY, x, y);
        y++;
        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        } else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}