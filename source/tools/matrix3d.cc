/*
 * matrix3d.cc
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#include "matrix3d.h"

#include <assert.h>
#include <algorithm>

#include "tools/matrix2d.h"

namespace {
const int kMatrixSize = 3;
}  // namespace

namespace tools {

Matrix3D::Matrix3D(float x11, float x12, float x13,
                   float x21, float x22, float x23,
                   float x31, float x32, float x33)
    : x{{x11, x12, x13},
        {x21, x22, x23},
        {x31, x32, x33}} {

}

Matrix3D::Matrix3D(const Matrix3D &other) {
  for (int i = 0; i < kMatrixSize; i++) {
    for (int j = 0; j < kMatrixSize; j++) {
      x[i][j] = other.x[i][j];
    }
  }
}

Matrix3D& Matrix3D::operator=(const Matrix3D &other) {
  for (int i = 0; i < kMatrixSize; i++) {
    for (int j = 0; j < kMatrixSize; j++) {
      x[i][j] = other.x[i][j];
    }
  }
  return *this;
}

float Matrix3D::Det() const {
  return x[0][0] * (x[1][1] * x[2][2] - x[2][1] * x[1][2]) -
         x[0][1] * (x[1][0] * x[2][2] - x[1][2] * x[2][0]) +
         x[0][2] * (x[1][0] * x[2][1] - x[1][1] * x[2][0]);
}

Matrix3D& Matrix3D::Invert() {
  const int kMatrix2DSize = 2;

  auto det_matrix = Det();
  assert(0.0 != det_matrix);
  auto invert_det_matrix = 1.0 / det_matrix;

  auto copy_matrix = *this;
  int current_matrix3d_cell_num = 0;
  for (int i = 0; i < kMatrixSize; i++) {
    for (int j = 0; j < kMatrixSize; j++) {
      Matrix2D current_submatrix_2d;
      int current_matrix2d_cell_num = 0;
      for (int z = 0; z < kMatrixSize; z++) {
        for (int u = 0; u < kMatrixSize; u++) {
          if (z != i && u != j) {
            current_submatrix_2d.x[current_matrix2d_cell_num / kMatrix2DSize][current_matrix2d_cell_num % kMatrix2DSize] = copy_matrix.x[z][u];
            current_matrix2d_cell_num++;
          }
        }
      }
      x[i][j] = current_submatrix_2d.Det();
      if (current_matrix3d_cell_num & 1) {
        x[i][j] *= -1;
      }
      current_matrix3d_cell_num++;
    }
  }

  return Transform().Mul(invert_det_matrix);
}

Matrix3D& Matrix3D::Transform() {
  std::swap(x[1][0], x[0][1]);
  std::swap(x[2][0], x[0][2]);
  std::swap(x[2][1], x[1][2]);
  return *this;
}

Matrix3D& Matrix3D::Mul(float value) {
  for (int i = 0; i < kMatrixSize; i++) {
    for (int j = 0; j < kMatrixSize; j++) {
      x[i][j] *= value;
    }
  }
  return *this;
}

} /* namespace tools */
