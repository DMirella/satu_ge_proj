/*
 * matrix3d.h
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_MATRIX3D_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_MATRIX3D_H_

namespace tools {

class Matrix3D {
 public:
  Matrix3D(Matrix3D &&other) = delete;
  Matrix3D& operator=(Matrix3D &&other) = delete;

  Matrix3D(const Matrix3D &other);
  Matrix3D& operator=(const Matrix3D &other);

  Matrix3D() : x{} { }
  Matrix3D(float x11, float x12, float x13,
           float x21, float x22, float x23,
           float x31, float x32, float x33);
  ~Matrix3D() { }

  float Det() const;
  Matrix3D& Invert();
  Matrix3D& Transform();
  Matrix3D& Mul(float value);

  float x[3][3];
};

} /* namespace tools */

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_MATRIX3D_H_ */
