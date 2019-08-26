/*
 * quaternion.h
 *
 *  Created on: 26 Aug 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_QUATERNION_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_QUATERNION_H_

#include "tools/vector3d.h"

namespace tools {

class Quaternion {
 public:
  Quaternion() = delete;
  Quaternion(const Quaternion& other) = delete;
  Quaternion& operator=(const Quaternion& other) = delete;
  Quaternion(Quaternion&& other) = delete;
  Quaternion& operator=(Quaternion&& other) = delete;

  Quaternion(float _scalar, const Vector3D& _vector) : scalar(_scalar), vector(_vector) { }

  void Normalize();
  void Add(const Quaternion& other);
  void Sub(const Quaternion& other);
  void Mul(float value);

  float scalar;
  Vector3D vector;

 private:
  float fsqr(float value) { return value * value; }
};

} /* namespace tools */

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_QUATERNION_H_ */
