#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape {
private:
    int centerX, centerY, radius;
public:
    Circle(int centerX, int centerY, int radius);
    void draw(std::vector<std::vector<char> >& grid) const override;
    std::string getInfoForConsole() const override;
    std::string getInfoForFile() const override;
};
#endif // CIRCLE_H