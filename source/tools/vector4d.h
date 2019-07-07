/*
 * vector4d.h
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_VECTOR4D_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_VECTOR4D_H_

namespace tools {

class Vector4D {
 public:
  Vector4D(Vector4D&& other) = delete;
  Vector4D(const Vector4D& other) = delete;
  Vector4D& operator=(Vector4D&& other) = delete;
  Vector4D& operator=(const Vector4D& other) = delete;

  Vector4D() : x(0.0), y(0.0), z(0.0), u(0.0) { }
  Vector4D(float _x, float _y, float _z, float _u)
      : x(_x), y(_y), z(_z), u(_u) { }
  ~Vector4D() { }

  void Add(const Vector4D& other);
  void Sub(const Vector4D& other);
  void Mul(float value);
  void Div(float value);
  float Length() const;

  static bool Compare(const Vector4D& v1, const Vector4D& v2) {
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.u == v2.u;
  }

  float x, y, z, u;
};

} /* namespace tools */

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_VECTOR4D_H_ */
