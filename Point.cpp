#include "Point.h"

Point::Point() {}

Point::Point(int _x, int _y, int _z) {
    x = _x;
    y = _y;
    z = _z;
}

Point::~Point() {}


void Point::setX(int _x) {
    x = _x;
}

int Point::getX() {
    return x;
}

void Point::setY(int _y) {
    y = _y;
}

int Point::getY() {
    return y;
}

void Point::setZ(int _z) {
    z = _z;
}

int Point::getZ() {
    return z;
}


void Point::print() {
    std::cout << "(" << x << ", " << y << ", " << z << ")\n";
}

