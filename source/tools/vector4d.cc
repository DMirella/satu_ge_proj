/*
 * vector4d.cc
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#include "vector4d.h"

#include <assert.h>
#include <cmath>

namespace tools {

void Vector4D::Add(const Vector4D& other) {
  x += other.x;
  y += other.y;
  z += other.z;
  u += other.u;
}

void Vector4D::Sub(const Vector4D& other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  u -= other.u;
}

void Vector4D::Mul(float value) {
  x *= value;
  y *= value;
  z *= value;
  u *= value;
}

void Vector4D::Div(float value) {
  assert(0.0 != value);

  x /= value;
  y /= value;
  z /= value;
  u /= value;
}

float Vector4D::Length() const {
  return std::sqrt(x * x + y * y + z * z + u * u);
}

}  // namespace tools
