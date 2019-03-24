#include "rhoban_geometry/3d/ray.h"

namespace rhoban_geometry
{
Ray::Ray()
{
}
Ray::Ray(const Eigen::Vector3d& source, const Eigen::Vector3d& dir) : source(source), dir(dir.normalized())
{
}

}  // namespace rhoban_geometry
