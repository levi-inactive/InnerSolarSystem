#ifndef Pyramid_h
#define Pyramid_h

#include "Drawable.h"

class Pyramid: public Drawable {
public:
    Pyramid(Math3D*);
    float points[5][3] = {{0,0,2},{2,0,2},{2,0,0},{0,0,0},{1,1.5,1}};
    float Norma(float p1[3], float p2[3]);
    void ImprimeMallaPiramide(int k);
    void draw();
};

#endif // Pyramid_h
