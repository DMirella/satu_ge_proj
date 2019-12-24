/*
 * vector3d.h
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_VECTOR3D_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_VECTOR3D_H_

namespace tools {

class Vector3D {
 public:
  Vector3D();
  Vector3D(float _x, float _y, float _z);
  Vector3D(const Vector3D& other);
  Vector3D& operator=(const Vector3D& other);
  Vector3D(Vector3D&& other);
  Vector3D& operator=(Vector3D&& other);

  ~Vector3D() { }

  void Add(const Vector3D& other);
  void Sub(const Vector3D& other);
  void Mul(float value);
  void Div(float value);
  float Length() const;

  static bool Compare(const Vector3D& v1, const Vector3D& v2) {
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
  }

  float x, y, z;
};

}  // namespace tools

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_VECTOR3D_H_ */
