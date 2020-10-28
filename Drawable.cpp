#include "Drawable.h"

Drawable::Drawable() {}

Drawable::Drawable(std::vector <Point> _pointVector) {
    pointVector = _pointVector;
}

Drawable::~Drawable() {}

std::vector <Point> Drawable::getPointVector() {
    return pointVector;
}

void Drawable::setPointVector(std::vector <Point> _pointVector) {
    pointVector = _pointVector;
}

void Drawable::print() {
    for (Point point : pointVector) {
        point.print();
    }
}
