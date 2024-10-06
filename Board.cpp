#include "Board.h"
#include <iostream>

Board::Board() : grid(30, std::vector<char>(200, ' ')) {}

void Board::print() const {
    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}

void Board::clear() {
    grid.assign(30, std::vector<char>(200, ' '));
}

void Board::addShape(Shape* shape) {
    shapes.push_back(shape);
    shape->draw(grid);
}

void Board::displayShapes() const {
    std::cout << "List of all available shapes:\n";
    std::cout << "> triangle x y height\n";
    std::cout << "> square x y width height\n";
    std::cout << "> circle x y radius\n";
    std::cout << "> line x y length angle\n";
}
