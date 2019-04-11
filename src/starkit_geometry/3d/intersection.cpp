#include "starkit_geometry/3d/intersection.h"
#include "starkit_geometry/3d/plane.h"
#include "starkit_geometry/3d/ray.h"

#include <starkit_utils/util.h>

namespace starkit_geometry
{
static double epsilon = std::pow(10, -12);

bool isIntersectionPoint(const Ray& r, const Plane& p)
{
  // Ray orientation is bad
  double dot_product = r.dir.dot(p.normal);
  if (std::fabs(dot_product) < epsilon)
  {
    return false;
  }
  // Check if plane is in front of ray
  Eigen::Vector3d projected_source = p.projectPoint(r.source);
  Eigen::Vector3d source_to_plane = projected_source - r.source;
  if (source_to_plane.dot(r.dir) < 0)
  {
    return false;
  }
  return true;
}

Eigen::Vector3d getIntersection(const Ray& r, const Plane& p)
{
  if (!isIntersectionPoint(r, p))
  {
    throw std::logic_error(DEBUG_INFO + " no interception can be found between r and p");
  }
  return r.source + p.getDist(r.source) * r.dir / std::fabs(r.dir.dot(p.normal));
}

}  // namespace starkit_geometry
