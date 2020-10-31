#ifndef Drawable_h
#define Drawable_h

#include <iostream>
#include <vector>

#include <GL/glut.h>

#include "Point.h"
#include "Matrix.h"
#include "Math3D.h"

#include <cmath>

class Drawable {
public:
    void loadIdentity(float M[][4]);
    Matrix matrix;
    Math3D* model;
    std::vector <Point> pointVector;
    
    Drawable();
    Drawable(Math3D*);
    ~Drawable();

    std::vector <Point> getPointVector();
    void setPointVector(std::vector <Point>);

    void update();
    void updatePoint(Point*);
    void draw();

    void print();
};

#endif // Drawable_h
