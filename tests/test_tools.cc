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

// Vector2d
TEST(Vector2d, Add) {
  tools::Vector2d v1, v2(2.31, 0);

  v1.set_x(1.1);
  v1.set_y(2.01);

  v1.Add(v2);

  EXPECT_NEAR(v1.x(), 3.41, kAbsoluteError);
  EXPECT_NEAR(v1.y(), 2.01, kAbsoluteError);
}

TEST(Vector2d, Sub) {
  tools::Vector2d v1, v2(2.31, 0);

  v1.set_x(1.1);
  v1.set_y(2.01);

  v1.Sub(v2);

  EXPECT_NEAR(v1.x(), -1.21, kAbsoluteError);
  EXPECT_NEAR(v1.y(), 2.01, kAbsoluteError);
}

TEST(Vector2d, Mul) {
  tools::Vector2d v1(2.31, 0);

  v1.Mul(2);

  EXPECT_NEAR(v1.x(), 4.62, kAbsoluteError);
  EXPECT_NEAR(v1.y(), 0, kAbsoluteError);
}

TEST(Vector2d, Div) {
  tools::Vector2d v1(2.31, 0);

  v1.Div(2);

  EXPECT_NEAR(v1.x(), 1.155, kAbsoluteError);
}

TEST(Vector2d, Compare) {
  tools::Vector2d v1(2.31, 0),v2(2.31, 0);

  EXPECT_TRUE(tools::Vector2d::Compare(v1, v2));
}

TEST(Vector2d, Length) {
  tools::Vector2d v1(2.31, 1.1);

  EXPECT_NEAR(v1.Length(), 2.558534736, kAbsoluteError);
}
