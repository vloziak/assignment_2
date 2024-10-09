#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Shape.h"
class Board {
    std::vector<std::vector<char> > grid;
    std::vector<Shape*> shapes;
public:
    Board();
    void print() const;
    void clear();
    void addShape(Shape* shape);
    void displayShapes() const;
    void listShapes();
};
#endif // BOARD_H