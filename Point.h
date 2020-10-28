#ifndef Point_h
#define Point_h

#include <iostream>

class Point {
private:
    int x;
    int y;
    int z;

public:
    Point();
    Point(int, int, int);
    ~Point();

    void setX(int);
    int getX();
    void setY(int);
    int getY();
    void setZ(int);
    int getZ();

    void print();
};

#endif // Point_h
