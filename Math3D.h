#ifndef Math3D_h
#define Math3D_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <time.h>

#include <stack>
#include <iostream>

using namespace std;

class Matrix {
public:
    float M[4][4];
};

class Math3D {
private:
    /* Variables para matrices de traslación, rotacion y escalamiento. */
    float T[4][4], R[4][4], E[4][4], A[4][4];
    Matrix matrix;

    /* Pila para el manejo de estados */
    stack<Matrix> matrixStack;

public:
    Math3D();
    ~Math3D();

    /* Carga la matriz identidad en la matriz que se recibe como parametro. */
    void loadIdentity(float M[][4]);

    /* Carga el vector de traslacion en la matriz T. */
    void translate(float x, float y, float z);
    
    /* Carga la matriz de escala en la matriz E. */
    void scale(float x, float y, float z);

    /* Carga la matriz de rotación sobre el eje X en la matriz R. */
    void rotateX(float theta);

    /* Carga la matriz de rotación sobre el eje Y en la matriz R. */
    void rotateY(float theta);

    /* Carga la matriz de rotación sobre el eje Z en la matriz R. */
    void rotateZ(float theta);

    /* Multiplica la matriz inputMatrix con la matriz matrix.M. */
    void operate(float inputMatrix[][4]);

    /* Multiplica la matriz M por el punto p y regresa el resultado en el punto p. */
    void MatPoint(float M[][4], float p[3]);

    /* Multiplica la matriz M por cada punto del objeto definido por la matriz p de size x 3. */
    void MatObject(float M[][4], int size, float p[][3]);

    void pushMatrix();
    void popMatrix();

    void printCurrentMatrix();
};

#endif // Math3D_h
