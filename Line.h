#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
private:
    int startX, startY, length, angle;

public:
    Line(int startX, int startY, int length, int angle);
    void draw(std::vector<std::vector<char> >& grid) const override;
    std::string getInfoForConsole() const override;
    std::string getInfoForFile() const override;
};

#endif // LINE_H
