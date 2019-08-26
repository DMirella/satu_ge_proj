/*
 * quaternion.cc
 *
 *  Created on: 26 Aug 2019
 *      Author: Dima
 */

#include "quaternion.h"

namespace tools {

void Quaternion::Normalize() {
  float current_norm = fsqr(scalar) + fsqr(vector.x) + fsqr(vector.y) + fsqr(vector.z);
  scalar /= current_norm;
  vector.Div(current_norm);
}

void Quaternion::Add(const Quaternion& other) {
  scalar += other.scalar;
  vector.Add(other.vector);
}

void Quaternion::Sub(const Quaternion& other) {
  scalar -= other.scalar;
  vector.Sub(other.vector);
}

void Quaternion::Mul(float value) {
  scalar *= value;
  vector.Mul(value);
}

} /* namespace tools */
