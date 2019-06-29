/*
 * vector2d.cc
 *
 *  Created on: 29 Jun 2019
 *      Author: Dima
 */

#include "vector2d.h"

#include <assert.h>


namespace tools {

void Vector2d::Add(float value) {
  x_ += value;
  y_ += value;
}

void Vector2d::Add(const Vector2d& other) {
  x_ += other.x();
  y_ += other.y();
}

void Vector2d::Sub(float value) {
  x_ -= value;
  y_ -= value;
}

void Vector2d::Sub(const Vector2d& other) {
  x_ -= other.x();
  y_ -= other.y();
}

void Vector2d::Mul(float value) {
  x_ *= value;
  y_ *= value;
}

void Vector2d::Div(float value) {
  assert(0.0 == value);

  x_ /= value;
  y_ /= value;
}

} /* namespace tools */
