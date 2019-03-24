#pragma once

#include <Eigen/Core>

namespace rhoban_geometry
{
class Plane;
class Ray;

/// Return true if the intersection between r and p is a simple point
/// Note: ray is oriented, therefore if plane is behind ray, there is no intersection
bool isIntersectionPoint(const Ray& r, const Plane& p);

/// Return the intersection between a ray and a point
/// Note: if there is no intersection, or if intersection is a ray, throws a logic_error
/// @see isIntersectionPoint
Eigen::Vector3d getIntersection(const Ray& r, const Plane& p);

}  // namespace rhoban_geometry
