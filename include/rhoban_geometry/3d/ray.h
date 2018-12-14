#pragma once

#include <Eigen/Core>

namespace rhoban_geometry
{

class Ray {
public:
  /// Default builder: source is (0,0,0) and dir is (1,0,0)
  Ray();

  /// Automatically normalize dir
  Ray(const Eigen::Vector3d & source, const Eigen::Vector3d & dir);

  
  /// Source of the ray
  Eigen::Vector3d source;

  /// Direction of the ray (norm = 1)
  Eigen::Vector3d dir;
};

}
