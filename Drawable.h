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
    /* Translation control variables. */
    float deltaX = 0;
    float deltaY = 0;
    float deltaZ = 0;

    /* Escalation control variables. */
    float deltaWidth;
    float deltaHeight;
    float deltaDepth;

    /* Rotation control variables. */
    char rotationMode = 'g';
    Point rotationAxis[2] = {Point(0, 0, 0), Point(0, 0, 1)};
    float deltaTheta = 0;

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
