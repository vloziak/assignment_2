#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw(std::vector<std::vector<char> >& grid) const = 0;
};


#endif //SHAPE_H
