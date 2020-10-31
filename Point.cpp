#include "Point.h"

Point::Point() {}

Point::Point(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

Point::Point(float _x, float _y, float _z, float _a) {
    x = _x;
    y = _y;
    z = _z;
    a = _a;
}

Point::~Point() {}

void Point::print() {
    std::cout << "(" << x << ", " << y << ", " << z << ", " << a << ")\n";
}
