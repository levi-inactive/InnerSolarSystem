#ifndef Point_h
#define Point_h

#include <iostream>

class Point {
public:
    float x;
    float y;
    float z;
    float a = 1;

    Point();
    Point(float, float, float);
    Point(float, float, float, float);
    ~Point();

    void print();
};

#endif // Point_h
