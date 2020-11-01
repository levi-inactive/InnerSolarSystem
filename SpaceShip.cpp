#include "SpaceShip.h"
#include "Pyramid.h"
#include "Sphere.h"
#include <iostream>
using namespace std;

SpaceShip:: SpaceShip(Math3D* _model){
    model = _model;
    loadIdentity(matrix.M);
}

void SpaceShip::drawFace(int i){


}

void SpaceShip::vertex3(double th2,double ph2)
{
   double x = sin(th2)*cos(ph2);
   double y = cos(th2)*cos(ph2);
   double z =          sin(ph2);
   glVertex3d(x,y,z);
}


void SpaceShip::draw(){

    int i;

    for(i=0; i<5;i++){
        glBegin(GL_LINE_LOOP);
            glVertex3fv(vertex[faces[i][3]]);
            glVertex3fv(vertex[faces[i][1]]);
            glVertex3fv(vertex[faces[i][1]]);
            glVertex3fv(vertex[faces[i][2]]);
        glEnd();
    }

    Math3D model;

        model.push();
            model.translate(1, 10, 8);
            model.scale(0.2, 0.2, 0.2);
            Sphere p1(&model);
            p1.draw();
        model.pop();

        model.push();
            model.translate(1, 10, -3);
            model.scale(0.2, 0.2, 0.2);
            Sphere p2(&model);
            p2.draw();
        model.pop();



    glEnd();


}
