/*
 * matrix_2d.cc
 *
 *  Created on: 30 Jun 2019
 *      Author: Dima
 */

#include "matrix_2d.h"

namespace tools {

Matrix2D::Matrix2D(const Matrix2D &other) {
  x[0][0] = other.x[0][0];
  x[0][1] = other.x[0][1];
  x[1][0] = other.x[1][0];
  x[1][1] = other.x[1][1];
}

Matrix2D& Matrix2D::operator=(const Matrix2D &other) {
  x[0][0] = other.x[0][0];
  x[0][1] = other.x[0][1];
  x[1][0] = other.x[1][0];
  x[1][1] = other.x[1][1];
  return *this;
}

float Matrix2D::det() const {
  return x[0][0] * x[1][1] - x[0][1] * x[1][0];
}

Matrix2D& Matrix2D::invert() {
  auto det_matrix = det();
  transform();
  det_matrix = 1.0 / det_matrix;
  return Mul(det_matrix);
}

Matrix2D& Matrix2D::transform() const {
  auto tmp = x[1][0];
  x[1][0] = x[1][1];
  x[0][1] = tmp;
  return *this;
}

Matrix2D& Matrix2D::Mul(float value) {
  x[0][0] *= value;
  x[0][1] *= value;
  x[1][0] *= value;
  x[1][1] *= value;
  return *this;
}

} /* namespace tools */
