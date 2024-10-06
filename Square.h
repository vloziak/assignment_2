#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    int x, y, width, height;

public:
    Square(int x, int y, int width, int height);
    void draw(std::vector<std::vector<char> >& grid) const override;
};

#endif // SQUARE_H
