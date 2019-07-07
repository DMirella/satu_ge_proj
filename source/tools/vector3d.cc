/*
 * vector3d.cc
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#include "vector3d.h"

#include <assert.h>
#include <cmath>

namespace tools {
Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0) {

}

Vector3D::Vector3D(float _x, float _y, float _z)
  : x(_x), y(_y), z(_z) {

}

Vector3D::Vector3D(const Vector3D& other) {
  x = other.x;
  y = other.y;
  z = other.z;
}

Vector3D& Vector3D::operator=(const Vector3D& other) {
  x = other.x;
  y = other.y;
  z = other.z;
  return *this;
}

Vector3D::Vector3D(Vector3D&& other) {
  x = other.x;
  y = other.y;
  z = other.z;
}

Vector3D& Vector3D::operator=(Vector3D&& other) {
  x = other.x;
  y = other.y;
  z = other.z;
  return *this;
}

void Vector3D::Add(const Vector3D& other) {
  x += other.x;
  y += other.y;
  z += other.z;
}

void Vector3D::Sub(const Vector3D& other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
}

void Vector3D::Mul(float value) {
  x *= value;
  y *= value;
  z *= value;
}

void Vector3D::Div(float value) {
  assert(0.0 != value);

  x /= value;
  y /= value;
  z /= value;
}

float Vector3D::Length() const {
  return std::sqrt(x * x + y * y + z * z);
}

}  // namespace tools

