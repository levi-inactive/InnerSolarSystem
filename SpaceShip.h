#ifndef SpaceShip_h
#define SpaceShip_h

#include "Drawable.h"

class SpaceShip : public Drawable {

    public:
        SpaceShip(Math3D*);
        float vertex[8][3] =
        {
            {-1.0,-1.0,1.0},
            {-1.0,1.0,1.0},
            {1.0,1.0,1.0},
            {1.0,-1.0,1.0},
            {-1.0,-1.0,-1.0},
            {-1.0,1.0,-1.0},
            {1.0,1.0,-1.0},
            {1.0,-1.0,-1.0},
        };

        int faces[6][4] = {

            {0,1,1,2},
            {7,6,5,4},
            {0,4,5,1},
            {2,1,5,6},
            {3,2,6,7},
            {0,3,7,4},

        };
        void vertex3(double th2,double ph2);
        void drawFace(int);
        void draw();

};

#endif // SpaceShip_h
