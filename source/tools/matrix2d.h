/*
 * matrix_2d.h
 *
 *  Created on: 30 Jun 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_MATRIX2D_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_MATRIX2D_H_

namespace tools {

class Matrix2D {
 public:
  Matrix2D(Matrix2D &&other) = delete;
  Matrix2D& operator=(Matrix2D &&other) = delete;

  Matrix2D(const Matrix2D &other);
  Matrix2D& operator=(const Matrix2D &other);

  Matrix2D() : x{} { }
  Matrix2D(float x11, float x12, float x21, float x22)
      : x{{x11, x12}, {x21, x22}} { }
  ~Matrix2D() { }

  float Det() const;
  Matrix2D& Invert();
  Matrix2D& Transform();
  Matrix2D& Mul(float value);

  float x[2][2];
};

} /* namespace tools */

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_MATRIX2D_H_ */
