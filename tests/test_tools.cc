/*
 * test_vector2d.cc
 *
 *  Created on: 29 Jun 2019
 *      Author: Dima
 */

#include "gtest/gtest.h"

#include "tools/vector2d.h"

namespace {
const float kAbsoluteError = 1e-6;
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
