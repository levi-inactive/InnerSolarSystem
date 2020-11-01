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
  float translationMatrix[ROWS][COLS];
  loadIdentity(translationMatrix);
  translationMatrix[0][3] = x;
  translationMatrix[1][3] = y;
  translationMatrix[2][3] = z;
  operate(translationMatrix);
}

void Math3D::scale(float x, float y, float z) {
  float scalationMatrix[ROWS][COLS];
  loadIdentity(scalationMatrix);
  scalationMatrix[0][0] = x;
  scalationMatrix[1][1] = y;
  scalationMatrix[2][2] = z;
  operate(scalationMatrix);
}

void Math3D::rotateX(float theta) {
  float rotationMatrix[ROWS][COLS];
  loadIdentity(rotationMatrix);
  rotationMatrix[1][1] = cos(theta);
  rotationMatrix[1][2] = -sin(theta);
  rotationMatrix[2][1] = sin(theta);
  rotationMatrix[2][2] = cos(theta);
  operate(rotationMatrix);
}

void Math3D::rotateY(float theta) {
  float rotationMatrix[ROWS][COLS];
  loadIdentity(rotationMatrix);
  rotationMatrix[0][0] = cos(theta);
  rotationMatrix[0][2] = sin(theta);
  rotationMatrix[2][0] = -sin(theta);
  rotationMatrix[2][2] = cos(theta);
  operate(rotationMatrix);
}

void Math3D::rotateZ(float theta) {
  float rotationMatrix[ROWS][COLS];
  loadIdentity(rotationMatrix);
  rotationMatrix[0][0] = cos(theta);
  rotationMatrix[0][1] = -sin(theta);
  rotationMatrix[1][0] = sin(theta);
  rotationMatrix[1][1] = cos(theta);
  operate(rotationMatrix);
}

void Math3D::rotate(float theta, Point p1, Point p2) {
  /* 1. Translate a point of the rotation axis to the origin. */
  translate(-p1.x, -p1.y, -p1.z);

  /* 2. Rotate to meet Z axis. */
  float componentX = p2.x - p1.x;
  float componentY = p2.y - p1.y;
  float componentZ = p2.z - p1.z;

  float alpha = atan(componentY / componentZ);
  rotateX(alpha);

  float beta = atan(componentX / componentZ);
  rotateY(beta);

  /* 3. Rotate along Z axis. */
  rotateZ(theta);

  /* 4. Rotate back to original orientation. */
  rotateY(-beta);
  rotateX(-alpha);

  /* 5. Translate back to original position. */
  translate(p1.x, p1.y, p1.z);
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
