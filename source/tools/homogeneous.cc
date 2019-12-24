/*
 * homogeneous.cc
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#include "homogeneous.h"

namespace tools {

Vector3D Vector2DToHomogeneous(const Vector2D& vector2d) {
  Vector3D result;
  result.x = vector2d.x;
  result.y = vector2d.y;
  result.z = 1;
  return result;
}

Vector4D Vector3DToHomogeneous(const Vector3D& vector2d) {
  Vector4D result;
  result.x = vector2d.x;
  result.y = vector2d.y;
  result.z = vector2d.z;
  result.u = 1;
  return result;
}

}  // namespace tools
