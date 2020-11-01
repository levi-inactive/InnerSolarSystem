#include "Earth.h"

Earth::Earth(Math3D* _model) {
    model = _model;
    loadIdentity(matrix.M);
}


void Earth::draw() {

    double x, y, z;

    int i, j;


     for (i=-90;i<90;i+=5) {
      glBegin(GL_QUAD_STRIP);
      for (j=0;j<=360;j+=2*5) {

        glColor3f(0.0,1.0,0.0); //green

        x = sin(j)*cos(i);
        y = cos(j)*cos(i);
        z = sin(i);

        Point point(x, y, z);
        updatePoint(&point);

        glVertex3d(point.x,point.y,point.z);

        glColor3f(0.0,0.0,1.0); //blue

        x = sin(j)*cos(i+5);
        y = cos(j)*cos(i+5);
        z = sin(i+5);

        Point point2(x, y, z);
        updatePoint(&point2);

        glVertex3d(point2.x,point2.y,point2.z);

      }
      glEnd();
    }


}
