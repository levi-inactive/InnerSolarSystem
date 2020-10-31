#include "Math3D.h"

Math3D::Math3D() {
  loadIdentity(matrix.M);
}

Math3D::~Math3D() {}

void Math3D::loadIdentity(float M[][4]) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (i == j) {
        M[i][j]=1;
      } else {
        M[i][j]=0;
      }
    }
  }
}

void Math3D::translate(float x, float y, float z) {
  loadIdentity(T);
  T[0][3] = x;
  T[1][3] = y;
  T[2][3] = z;
  operate(T);
}

void Math3D::scale(float x, float y, float z) {
  loadIdentity(E);
  E[0][0] = x;
  E[1][1] = y;
  E[2][2] = z;
  operate(E);
}

void Math3D::rotateX(float theta) {
  loadIdentity(R);
  R[1][1] = cos(theta);
  R[1][2] = -sin(theta);
  R[2][1] = sin(theta);
  R[2][2] = cos(theta);
  operate(R);
}

void Math3D::rotateY(float theta) {
  loadIdentity(R);
  R[0][0] = cos(theta);
  R[0][2] = sin(theta);
  R[2][0] = -sin(theta);
  R[2][2] = cos(theta);
  operate(R);
}

void Math3D::rotateZ(float theta) {
  loadIdentity(R);
  R[0][0] = cos(theta);
  R[0][1] = -sin(theta);
  R[1][0] = sin(theta);
  R[1][1] = cos(theta);
  operate(R);
}

void Math3D::operate(float inputMatrix[][4]) {
  float tmp[4][4];
  int i, j, k;

  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++){
      tmp[i][j] = 0;
      for(k = 0; k < 4; k++) {
        tmp[i][j] += inputMatrix[i][k] * matrix.M[k][j];
      }
    }
  }

  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      matrix.M[i][j] = tmp[i][j];
    }
  }
}

void Math3D::MatPoint(float M[][4], float p[3]) {
  float tmp[4];
  int i, j;
  
  for(i = 0; i < 3; i++) { 
    tmp[i] = p[i];
    p[i] = 0;
  }

  tmp[3]=1;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 4; j++) {
      p[i] += M[i][j] * tmp[j];
    }
  }
}

//Multiplica la matriz m por cada punto del objeto definido por la matriz p de size x 3
void Math3D::MatObject(float M[][4], int size, float p[][3]) {
  int i;
  for(i = 0; i < size; i++) {
    MatPoint(M, p[i]);
  }
}

void Math3D::push() {
  matrixStack.push(matrix);
}

void Math3D::pop() {
  matrix = matrixStack.top();
  matrixStack.pop();
}

void Math3D::print() {
  for (unsigned int i = 0; i < ROWS; i++) {
    for (unsigned int j = 0; j < COLS; j++) {
      std::cout << matrix.M[i][j] << " ";
    }
    std::cout << "\n";
  }
}
