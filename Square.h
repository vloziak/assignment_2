#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
    int x, y, width, height;

public:
    Square(int x, int y, int width, int height);
    void draw(std::vector<std::vector<char> >& grid) const override;
    std::string getInfoForFile() const override;
    std::string getInfoForConsole() const override;
};

#endif // SQUARE_H
