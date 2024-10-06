#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int centerX, centerY, radius;
    void drawBorders(std::vector<std::vector<char> >& grid, int centerX, int centerY, int x, int y) const;

public:
    Circle(int centerX, int centerY, int radius);
    void draw(std::vector<std::vector<char> >& grid) const override;
};

#endif // CIRCLE_H
