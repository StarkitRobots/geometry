#include "starkit_geometry/3d/plane.h"

namespace starkit_geometry
{
Plane::Plane() : Plane(Eigen::Vector3d::UnitZ(), 0)
{
}

Plane::Plane(const Eigen::Vector3d& normal, double dist) : normal(normal.normalized()), dist(dist)
{
}

double Plane::getDist(const Eigen::Vector3d& point) const
{
  return std::fabs(point.dot(normal) - dist);
}

Eigen::Vector3d Plane::projectPoint(const Eigen::Vector3d& point) const
{
  return point + normal * (dist - point.dot(normal));
}

}  // namespace starkit_geometry
