/*
 * vector2d.h
 *
 *  Created on: 29 Jun 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_VECTOR2D_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_VECTOR2D_H_

namespace tools {

class Vector2d {
 public:
  Vector2d(Vector2d&& other) = delete;
  Vector2d(const Vector2d& other) = delete;
  Vector2d& operator=(Vector2d&& other) = delete;
  Vector2d& operator=(const Vector2d& other) = delete;

  Vector2d() : x_(0.0), y_(0.0) { }
  Vector2d(float x, float y)
      : x_(x), y_(y) { }
  ~Vector2d() { }

  void Add(float value);
  void Add(const Vector2d& other);

  void Sub(float value);
  void Sub(const Vector2d& other);

  void Mul(float value);
  void Div(float value);

  static bool Compare(const Vector2d& v1, const Vector2d& v2) {
    return v1.x() == v2.x() && v1.y() == v2.y();
  }

  float x() const { return x_; }
  float y() const { return y_; }
 private:
  float x_, y_;
};

} /* namespace tools */

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_VECTOR2D_H_ */
