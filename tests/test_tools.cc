/*
 * test_vector2d.cc
 *
 *  Created on: 29 Jun 2019
 *      Author: Dima
 */

#include "gtest/gtest.h"

#include "tools/homogeneous.h"
#include "tools/matrix2d.h"
#include "tools/matrix3d.h"
#include "tools/vector2d.h"
#include "tools/vector3d.h"
#include "tools/vector4d.h"

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
  EXPECT_NEAR(v1.y, 0, kAbsoluteError);
}

TEST(Vector2D, Compare_TrueRes) {
  tools::Vector2D v1(2.31, 0), v2(2.31, 0);

  EXPECT_TRUE(tools::Vector2D::Compare(v1, v2));
}

TEST(Vector2D, Compare_FalseRes) {
  tools::Vector2D v1(2.31, 0), v2(2.31, 1);

  EXPECT_FALSE(tools::Vector2D::Compare(v1, v2));
}

TEST(Vector2D, Length) {
  tools::Vector2D v1(2.31, 1.1);

  EXPECT_NEAR(v1.Length(), 2.558534736, kAbsoluteError);
}

// Vector3D
TEST(Vector3D, Add) {
  tools::Vector3D v1, v2(2.31, 0, 1);
  v1.x = 1.1;
  v1.y = 2.01;
  v1.z = 9;
  v1.Add(v2);

  EXPECT_NEAR(v1.x, 3.41, kAbsoluteError);
  EXPECT_NEAR(v1.y, 2.01, kAbsoluteError);
  EXPECT_NEAR(v1.z, 10, kAbsoluteError);
}

TEST(Vector3D, Sub) {
  tools::Vector3D v1, v2(2.31, 0, 1);
  v1.x = 1.1;
  v1.y = 2.01;
  v1.z = 9;
  v1.Sub(v2);

  EXPECT_NEAR(v1.x, -1.21, kAbsoluteError);
  EXPECT_NEAR(v1.y, 2.01, kAbsoluteError);
  EXPECT_NEAR(v1.z, 8, kAbsoluteError);
}

TEST(Vector3D, Mul) {
  tools::Vector3D v1(2.31, 0, 1);
  v1.Mul(2);

  EXPECT_NEAR(v1.x, 4.62, kAbsoluteError);
  EXPECT_NEAR(v1.y, 0, kAbsoluteError);
  EXPECT_NEAR(v1.z, 2, kAbsoluteError);
}

TEST(Vector3D, Div) {
  tools::Vector3D v1(2.31, 0, 1);
  v1.Div(2);

  EXPECT_NEAR(v1.x, 1.155, kAbsoluteError);
  EXPECT_NEAR(v1.y, 0, kAbsoluteError);
  EXPECT_NEAR(v1.z, 0.5, kAbsoluteError);
}

TEST(Vector3D, Compare_TrueRes) {
  tools::Vector3D v1(2.31, 0, 9), v2(2.31, 0, 9);

  EXPECT_TRUE(tools::Vector3D::Compare(v1, v2));
}

TEST(Vector3D, Compare_FalseRes) {
  tools::Vector3D v1(2.31, 0, 9), v2(2.31, 0, 1);

  EXPECT_FALSE(tools::Vector3D::Compare(v1, v2));
}

TEST(Vector3D, Length) {
  tools::Vector3D v1(2.31, 1.1, 9);

  EXPECT_NEAR(v1.Length(), 9.356607, kAbsoluteError);
}

// Vector4D
TEST(Vector4D, Add) {
  tools::Vector4D v1, v2(2.31, 0, 1, 2.1);
  v1.x = 1.1;
  v1.y = 2.01;
  v1.z = 9;
  v1.Add(v2);

  EXPECT_NEAR(v1.x, 3.41, kAbsoluteError);
  EXPECT_NEAR(v1.y, 2.01, kAbsoluteError);
  EXPECT_NEAR(v1.z, 10, kAbsoluteError);
  EXPECT_NEAR(v1.u, 2.1, kAbsoluteError);
}

TEST(Vector4D, Sub) {
  tools::Vector4D v1, v2(2.31, 0, 1, 2.1);
  v1.x = 1.1;
  v1.y = 2.01;
  v1.z = 9;
  v1.Sub(v2);

  EXPECT_NEAR(v1.x, -1.21, kAbsoluteError);
  EXPECT_NEAR(v1.y, 2.01, kAbsoluteError);
  EXPECT_NEAR(v1.z, 8, kAbsoluteError);
  EXPECT_NEAR(v1.u, -2.1, kAbsoluteError);
}

TEST(Vector4D, Mul) {
  tools::Vector4D v1(2.31, 0, 1, 2.1);
  v1.Mul(2);

  EXPECT_NEAR(v1.x, 4.62, kAbsoluteError);
  EXPECT_NEAR(v1.y, 0, kAbsoluteError);
  EXPECT_NEAR(v1.z, 2, kAbsoluteError);
  EXPECT_NEAR(v1.u, 4.2, kAbsoluteError);
}

TEST(Vector4D, Div) {
  tools::Vector4D v1(2.31, 0, 1, 2.1);
  v1.Div(2);

  EXPECT_NEAR(v1.x, 1.155, kAbsoluteError);
  EXPECT_NEAR(v1.y, 0, kAbsoluteError);
  EXPECT_NEAR(v1.z, 0.5, kAbsoluteError);
  EXPECT_NEAR(v1.u, 1.05, kAbsoluteError);
}

TEST(Vector4D, Compare_TrueRes) {
  tools::Vector4D v1(2.31, 0, 9, 1.45), v2(2.31, 0, 9, 1.45);

  EXPECT_TRUE(tools::Vector4D::Compare(v1, v2));
}

TEST(Vector4D, Compare_FalseRes) {
  tools::Vector4D v1(2.31, 0, 1, 1.44), v2(2.31, 0, 1, 1.45);

  EXPECT_FALSE(tools::Vector4D::Compare(v1, v2));
}

TEST(Vector4D, Length) {
  tools::Vector4D v1(2.31, 1.1, 9, 2.1);

  EXPECT_NEAR(v1.Length(), 9.58937, kAbsoluteError);
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

// Matrix3D
TEST(Matrix3D, Det) {
  tools::Matrix3D m(  1.1, 2.3,   4.6,
                      7.1,  -2, -5.66,
                    -1.23,   3,     4);

  EXPECT_NEAR(m.Det(), 47.23414, kAbsoluteError);
}

TEST(Matrix3D, Invert) {
  tools::Matrix3D m(  1.1, 2.3,   4.6,
                      7.1,  -2, -5.66,
                    -1.23,   3,     4);
  m.Invert();

  EXPECT_NEAR(m.x[0][0], 0.19011, kAbsoluteError);
  EXPECT_NEAR(m.x[0][1], 0.09738, kAbsoluteError);
  EXPECT_NEAR(m.x[0][2], -0.08083, kAbsoluteError);
  EXPECT_NEAR(m.x[1][0], -0.45387, kAbsoluteError);
  EXPECT_NEAR(m.x[1][1], 0.21293, kAbsoluteError);
  EXPECT_NEAR(m.x[1][2], 0.82326, kAbsoluteError);
  EXPECT_NEAR(m.x[2][0], 0.39886, kAbsoluteError);
  EXPECT_NEAR(m.x[2][1], -0.12975, kAbsoluteError);
  EXPECT_NEAR(m.x[2][2], -0.39230, kAbsoluteError);
}

TEST(Matrix3D, Transform) {
  tools::Matrix3D m(  1.1, 2.3,   4.6,
                      7.1,  -2, -5.66,
                    -1.23,   3,     4);
  m.Transform();
  EXPECT_NEAR(m.x[0][0], 1.1, kAbsoluteError);
  EXPECT_NEAR(m.x[0][1], 7.1, kAbsoluteError);
  EXPECT_NEAR(m.x[0][2], -1.23, kAbsoluteError);
  EXPECT_NEAR(m.x[1][0], 2.3, kAbsoluteError);
  EXPECT_NEAR(m.x[1][1], -2, kAbsoluteError);
  EXPECT_NEAR(m.x[1][2], 3, kAbsoluteError);
  EXPECT_NEAR(m.x[2][0], 4.6, kAbsoluteError);
  EXPECT_NEAR(m.x[2][1], -5.66, kAbsoluteError);
  EXPECT_NEAR(m.x[2][2], 4, kAbsoluteError);
}

TEST(Matrix3D, Mul_Value) {
  tools::Matrix3D m(  1.1, 2.3,   4.6,
                      7.1,  -2, -5.66,
                    -1.23,   3,     4);
  m.Mul(2);
  EXPECT_NEAR(m.x[0][0], 2.2, kAbsoluteError);
  EXPECT_NEAR(m.x[0][1], 4.6, kAbsoluteError);
  EXPECT_NEAR(m.x[0][2], 9.2, kAbsoluteError);
  EXPECT_NEAR(m.x[1][0], 14.2, kAbsoluteError);
  EXPECT_NEAR(m.x[1][1], -4, kAbsoluteError);
  EXPECT_NEAR(m.x[1][2], -11.32, kAbsoluteError);
  EXPECT_NEAR(m.x[2][0], -2.46, kAbsoluteError);
  EXPECT_NEAR(m.x[2][1], 6, kAbsoluteError);
  EXPECT_NEAR(m.x[2][2], 8, kAbsoluteError);
}

// Homogeneous
TEST(Homogeneous, Vector2DToHomogeneous) {
  tools::Vector2D v(1.1, 2.3);
  tools::Vector3D result = tools::Vector2DToHomogeneous(v);
  EXPECT_NEAR(result.x,  v.x, kAbsoluteError);
  EXPECT_NEAR(result.y,  v.y, kAbsoluteError);
  EXPECT_NEAR(result.z,  1, kAbsoluteError);
}

TEST(Homogeneous, Vector3DToHomogeneous) {
  tools::Vector3D v(1.1, 2.3, 5);
  tools::Vector4D result = tools::Vector3DToHomogeneous(v);
  EXPECT_NEAR(result.x,  v.x, kAbsoluteError);
  EXPECT_NEAR(result.y,  v.y, kAbsoluteError);
  EXPECT_NEAR(result.z,  v.z, kAbsoluteError);
  EXPECT_NEAR(result.u,  1, kAbsoluteError);
}

