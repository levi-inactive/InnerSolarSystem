#ifndef Drawable_h
#define Drawable_h

#include <iostream>
#include <vector>

#include <GL/glut.h>

#include "Point.h";

#include <cmath>

class Drawable {
private:
    std::vector<Point> pointVector;

    void bresenham(Point, Point);

public:
    Drawable();
    Drawable(std::vector <Point>);
    ~Drawable();

    std::vector <Point> getPointVector();
    void setPointVector(std::vector <Point>);

    void print();
};

#endif // Drawable_h
