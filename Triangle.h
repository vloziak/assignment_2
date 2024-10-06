#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    int x, y, height;

public:
    Triangle(int x, int y, int height);
    void draw(std::vector<std::vector<char> >& grid) const override;
};

#endif // TRIANGLE_H
