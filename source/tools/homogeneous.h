/*
 * homogeneous.h
 *
 *  Created on: 7 Jul 2019
 *      Author: Dima
 */

#ifndef SATU_GE_PROJ_SOURCE_TOOLS_HOMOGENEOUS_H_
#define SATU_GE_PROJ_SOURCE_TOOLS_HOMOGENEOUS_H_

#include "tools/vector2d.h"
#include "tools/vector3d.h"
#include "tools/vector4d.h"

namespace tools {

Vector3D Vector2DToHomogeneous(const Vector2D& vector2d);
Vector4D Vector3DToHomogeneous(const Vector3D& vector2d);

}  // namespace tools

#endif /* SATU_GE_PROJ_SOURCE_TOOLS_HOMOGENEOUS_H_ */
