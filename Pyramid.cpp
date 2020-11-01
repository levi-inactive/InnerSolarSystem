#include "Pyramid.h"

using namespace std;

Pyramid::Pyramid() {}

Pyramid:: Pyramid(Math3D* _model){
    model = _model;
    loadIdentity(matrix.M);
}

float Pyramid::Norma(float p1[3], float p2[3])
{
      float n=0;
      int i;
      for(i=0;i<3;i++)
        n += pow(p2[i]-p1[i],2);
      return(sqrt(n));
}

void Pyramid::ImprimeMallaPiramide(int k)
{
     int i,j;
     float U[3],d,norma;
     for(i=0;i<3;i++)
     {
        norma = Norma(points[i],points[i+1]);
        d = norma/(float)k;
        U[0] = (points[i+1][0]-points[i][0])/norma;
        U[1] = (points[i+1][1]-points[i][1])/norma;
        U[2] = (points[i+1][2]-points[i][2])/norma;
        for(j = 1; j < k; j++)
        {
           glBegin(GL_LINES);
             glVertex3f(points[4][0],points[4][1],points[4][2]);
             glVertex3f(points[i][0]+U[0]*d*j,points[i][1]+U[1]*d*j,points[i][2]+U[2]*d*j);
           glEnd();
        }
     }
     norma = Norma(points[i],points[0]);
     d = norma /(float)k;
     U[0] = (points[0][0]-points[i][0])/norma;
     U[1] = (points[0][1]-points[i][1])/norma;
     U[2] = (points[0][2]-points[i][2])/norma;
     for(j = 1; j < k; j++)
        {
           glBegin(GL_LINES);
             glVertex3f(points[4][0],points[4][1],points[4][2]);
             glVertex3f(points[i][0]+U[0]*d*j,points[i][1]+U[1]*d*j,points[i][2]+U[2]*d*j);
           glEnd();
        }

}

void Pyramid::draw() {
    glColor3f(1.0f, 1.0f, 1.0f);
    int i, x, y, z;
    glBegin(GL_LINE_LOOP);
      for(i=0;i<4;i++){

        x = points[i][0];
        y = points[i][1];
        z = points[i][2];

        Point point(x, y, z);
        updatePoint(&point);

        glVertex3f(point.x,point.y,point.z);
      }
    glEnd();
    glBegin(GL_LINES);
      for(i=0;i<4;i++){

        x = points[4][0];
        y = points[4][1];
        z = points[4][2];

        Point point(x, y, z);
        updatePoint(&point);

        glVertex3f(point.x,point.y,point.z);

        x = points[i][0];
        y = points[i][1];
        z = points[i][2];

        Point point2(x, y, z);
        updatePoint(&point2);

        glVertex3f(point2.x,point2.y,point2.z);
        }
    glEnd();

    //Enmallado
    int i1,j1;
     float U[3],d,norma;
     for(i1=0;i1<3;i1++)
     {
        norma = Norma(points[i1],points[i1+1]);
        d = norma/(float)20;
        U[0] = (points[i1+1][0]-points[i1][0])/norma;
        U[1] = (points[i1+1][1]-points[i1][1])/norma;
        U[2] = (points[i1+1][2]-points[i1][2])/norma;
        for(j1 = 1; j1 < 20; j1++)
        {
           glBegin(GL_LINES);

            x = points[4][0];
            y = points[4][1];
            z = points[4][2];

            Point point(x, y, z);
            updatePoint(&point);

            glVertex3f(point.x,point.y, point.z);

            x = points[i1][0]+U[0]*d*j1;
            y = points[i1][1]+U[1]*d*j1;
            z = points[i1][2]+U[2]*d*j1;

            Point point2(x, y, z);
            updatePoint(&point2);


            glVertex3f(point2.x,point2.y,point2.z);

           glEnd();
        }
     }
     norma = Norma(points[i],points[0]);
     d = norma /(float)20;
     U[0] = (points[0][0]-points[i1][0])/norma;
     U[1] = (points[0][1]-points[i1][1])/norma;
     U[2] = (points[0][2]-points[i1][2])/norma;
     for(j1 = 1; j1 < 20; j1++)
        {
           glBegin(GL_LINES);

                x = points[4][0];
                y = points[4][1];
                z = points[4][2];

                Point point(x, y, z);
                updatePoint(&point);

                glVertex3f(point.x,point.y,point.z);

                x = points[i1][0]+U[0]*d*j1;
                y = points[i1][1]+U[1]*d*j1;
                z = points[i1][2]+U[2]*d*j1;

                Point point2(x, y, z);
                updatePoint(&point2);

                glVertex3f(point2.x,point2.y,point2.z);

           glEnd();
        }

    //ImprimeMallaPiramide(20);
}
