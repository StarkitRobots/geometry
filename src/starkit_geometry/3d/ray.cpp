#include "starkit_geometry/3d/ray.h"

namespace starkit_geometry
{
Ray::Ray()
{
}
Ray::Ray(const Eigen::Vector3d& source, const Eigen::Vector3d& dir) : source(source), dir(dir.normalized())
{
}

}  // namespace starkit_geometry
