/*
 * test_vector2d.cc
 *
 *  Created on: 29 Jun 2019
 *      Author: Dima
 */

#include "../source/tools/matrix2d.h"
#include "gtest/gtest.h"

#include "tools/vector2d.h"

namespace {
const float kAbsoluteError = 1e-4;
}

// Vector2D
TEST(Vector2D, Add) {
  tools::Vector2D v1, v2(2.31, 0);
  v1.x = 1.1;
  v1.y = 2.01;
  v1.Add(v2);

  EXPECT_NEAR(v1.x, 3.41, kAbsoluteError);
  EXPECT_NEAR(v1.y, 2.01, kAbsoluteError);
}

TEST(Vector2D, Sub) {
  tools::Vector2D v1, v2(2.31, 0);
  v1.x = 1.1;;
  v1.y = 2.01;;
  v1.Sub(v2);

  EXPECT_NEAR(v1.x, -1.21, kAbsoluteError);
  EXPECT_NEAR(v1.y, 2.01, kAbsoluteError);
}

TEST(Vector2D, Mul) {
  tools::Vector2D v1(2.31, 0);
  v1.Mul(2);

  EXPECT_NEAR(v1.x, 4.62, kAbsoluteError);
  EXPECT_NEAR(v1.y, 0, kAbsoluteError);
}

TEST(Vector2D, Div) {
  tools::Vector2D v1(2.31, 0);
  v1.Div(2);

  EXPECT_NEAR(v1.x, 1.155, kAbsoluteError);
}

TEST(Vector2D, Compare) {
  tools::Vector2D v1(2.31, 0),v2(2.31, 0);

  EXPECT_TRUE(tools::Vector2D::Compare(v1, v2));
}

TEST(Vector2D, Length) {
  tools::Vector2D v1(2.31, 1.1);

  EXPECT_NEAR(v1.Length(), 2.558534736, kAbsoluteError);
}

// Matrix2D
TEST(Matrix2D, Det) {
  tools::Matrix2D m(1.1, 2.3, 4.6, 7.1);

  EXPECT_NEAR(m.Det(), -2.77, kAbsoluteError);
}

TEST(Matrix2D, Invert) {
  tools::Matrix2D m(1.1, 2.3, 4.6, 7.1);
  m.Invert();

  EXPECT_NEAR(m.x[0][0], -2.56317, kAbsoluteError);
  EXPECT_NEAR(m.x[0][1], 0.83032, kAbsoluteError);
  EXPECT_NEAR(m.x[1][0], 1.66064, kAbsoluteError);
  EXPECT_NEAR(m.x[1][1], -0.39711, kAbsoluteError);
}

TEST(Matrix2D, Transform) {
  tools::Matrix2D m(1.1, 2.3, 4.6, 7.1);
  m.Transform();
  EXPECT_NEAR(m.x[0][0], 1.1, kAbsoluteError);
  EXPECT_NEAR(m.x[0][1], 4.6, kAbsoluteError);
  EXPECT_NEAR(m.x[1][0], 2.3, kAbsoluteError);
  EXPECT_NEAR(m.x[1][1], 7.1, kAbsoluteError);
}

TEST(Matrix2D, Mul_Value) {
  tools::Matrix2D m(1.1, 2.3, 4.6, 7.1);
  m.Mul(2);
  EXPECT_NEAR(m.x[0][0],  2.2, kAbsoluteError);
  EXPECT_NEAR(m.x[0][1],  4.6, kAbsoluteError);
  EXPECT_NEAR(m.x[1][0],  9.2, kAbsoluteError);
  EXPECT_NEAR(m.x[1][1], 14.2, kAbsoluteError);
}
