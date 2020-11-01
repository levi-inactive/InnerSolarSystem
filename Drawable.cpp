#include "Drawable.h"

void Drawable::loadIdentity(float M[][4]) {
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

Drawable::Drawable() {}

Drawable::Drawable(Math3D* _model) {
    model = _model;
    loadIdentity(matrix.M);
}

Drawable::~Drawable() {}

std::vector <Point> Drawable::getPointVector() {
    return pointVector;
}

void Drawable::setPointVector(std::vector <Point> _pointVector) {
    pointVector = _pointVector;
}

void Drawable::updatePoint(Point* p) {
    Point tmp;

    /* Update point with internal model matrix. */
    tmp.x = matrix.M[0][0] * p->x
          + matrix.M[0][1] * p->y
          + matrix.M[0][2] * p->z
          + matrix.M[0][3] * p->a;
    tmp.y = matrix.M[1][0] * p->x
          + matrix.M[1][1] * p->y
          + matrix.M[1][2] * p->z
          + matrix.M[1][3] * p->a;
    tmp.z = matrix.M[2][0] * p->x
          + matrix.M[2][1] * p->y
          + matrix.M[2][2] * p->z
          + matrix.M[2][3] * p->a;
    tmp.a = matrix.M[3][0] * p->x
          + matrix.M[3][1] * p->y
          + matrix.M[3][2] * p->z
          + matrix.M[3][3] * p->a;

    p->x = tmp.x;
    p->y = tmp.y;
    p->z = tmp.z;
    p->a = tmp.a;

    /* Update point with global model matrix. */
    tmp.x = model->matrix.M[0][0] * p->x
          + model->matrix.M[0][1] * p->y
          + model->matrix.M[0][2] * p->z
          + model->matrix.M[0][3] * p->a;
    tmp.y = model->matrix.M[1][0] * p->x
          + model->matrix.M[1][1] * p->y
          + model->matrix.M[1][2] * p->z
          + model->matrix.M[1][3] * p->a;
    tmp.z = model->matrix.M[2][0] * p->x
          + model->matrix.M[2][1] * p->y
          + model->matrix.M[2][2] * p->z
          + model->matrix.M[2][3] * p->a;
    tmp.a = model->matrix.M[3][0] * p->x
          + model->matrix.M[3][1] * p->y
          + model->matrix.M[3][2] * p->z
          + model->matrix.M[3][3] * p->a;

    p->x = tmp.x;
    p->y = tmp.y;
    p->z = tmp.z;
    p->a = tmp.a;
}

void Drawable::print() {
    for (Point point : pointVector) {
        point.print();
    }
}
