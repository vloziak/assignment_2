#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Shape.h"

class Board {
    std::vector<std::vector<char> > grid;
    std::vector<Shape*> shapes;

public:
    Board();
    void clearAll();
    void resetId();
    void print() const;
    void clear();
    void addShape(Shape* shape);
    void undo();
    void displayShapes() const;
    void listShapes();
    void save(const std::string& filename);
    void load(const std::string& filename);
};
#endif // BOARD_H