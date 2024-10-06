#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
private:
    int startX, startY, length;
    double angle;

public:
    Line(int startX, int startY, int length, double angle);
    void draw(std::vector<std::vector<char> >& grid) const override;
};

#endif // LINE_H
