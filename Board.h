#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Shape.h"

class Board {
    std::vector<std::vector<char> > grid;

public:
    Board();
    void print() const;
    void clear();
    void addShape(Shape* shape);
    void displayShapes() const;

private:
    std::vector<Shape*> shapes;
};

#endif // BOARD_H
