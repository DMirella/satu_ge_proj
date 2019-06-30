/*
 * vector2d.h
 *
 *  Created on: 29 Jun 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_VECTOR2D_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_VECTOR2D_H_

namespace tools {

class Vector2D {
 public:
  Vector2D(Vector2D&& other) = delete;
  Vector2D(const Vector2D& other) = delete;
  Vector2D& operator=(Vector2D&& other) = delete;
  Vector2D& operator=(const Vector2D& other) = delete;

  Vector2D() : x(0.0), y(0.0) { }
  Vector2D(float _x, float _y)
      : x(_x), y(_y) { }
  ~Vector2D() { }

  void Add(const Vector2D& other);
  void Sub(const Vector2D& other);
  void Mul(float value);
  void Div(float value);
  float Length() const;

  static bool Compare(const Vector2D& v1, const Vector2D& v2) {
    return v1.x == v2.x && v1.y == v2.y;
  }

  float x, y;
};

}  // namespace tools

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_VECTOR2D_H_ */
