/*
 * vector2d.cc
 *
 *  Created on: 29 Jun 2019
 *      Author: Dima
 */

#include "vector2d.h"

#include <assert.h>
#include <cmath>

namespace tools {

Vector2D::Vector2D() : x(0.0), y(0.0) {

}

Vector2D::Vector2D(float _x, float _y) : x(_x), y(_y) {

}

Vector2D::Vector2D(const Vector2D& other) {
  x = other.x;
  y = other.y;
}

Vector2D& Vector2D::operator=(const Vector2D& other) {
  x = other.x;
  y = other.y;
  return *this;
}

Vector2D::Vector2D(Vector2D&& other) {
  x = other.x;
  y = other.y;
}

Vector2D& Vector2D::operator=(Vector2D&& other) {
  x = other.x;
  y = other.y;
  return *this;
}

void Vector2D::Add(const Vector2D& other) {
  x += other.x;
  y += other.y;
}

void Vector2D::Sub(const Vector2D& other) {
  x -= other.x;
  y -= other.y;
}

void Vector2D::Mul(float value) {
  x *= value;
  y *= value;
}

void Vector2D::Div(float value) {
  assert(0.0 != value);

  x /= value;
  y /= value;
}

float Vector2D::Length() const {
  return std::sqrt(x * x + y * y);
}

}  // namespace tools
