#ifndef Math3D_h
#define Math3D_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

class Math3D {

    public:

        Math3D();

        //Variables para matrices de rotacion, traslación y escalamiento
        float T[4][4], R[4][4], E[4][4], A[4][4];

        //Funcion para cargar la matriz identidad en la matriz que se recibe como parametro
        void LoadIdentity(float M[][4]);

        //Funcion que carga la matriz de escala en la matriz E
        void scale(float x, float y, float z);

        //Funcion que carga el vector de traslacion en la matriz T
        void translate(float x, float y, float z);

        //Pila para el manejo de estados
        stack<Matrix*> mystack;

        //Funcion que multiplica la matriz M1 con la matriz M2, donde el resultado es Res
        void MultM(float M1[][4], float M2[][4], float Res[][4]);

        //multiplica la matriz m por el punto p y regresa el resultado en el punto p
        void MatPoint(float m[][4], float p[3]);

        //multiplica la matriz m por cada punto del objeto definido por la matriz p de size x 3
        void MatObject(float m[][4], int size, float p[][3]);

        void push();
        void pop();



};

#endif // Math3D_h
