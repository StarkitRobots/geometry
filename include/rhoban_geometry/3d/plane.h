#pragma once

#include <Eigen/Core>

namespace rhoban_geometry
{

/// Represents a 3d plane
class Plane {
public:

  /// Default is plane z = 0
  Plane();
  
  /// Note: Plane(normal, dist) = Plane(-normal, -dist)
  Plane(const Eigen::Vector3d & normal, double dist);


  double getDist(const Eigen::Vector3d & point) const;

  /// Return the projection of 'p' on current plane
  Eigen::Vector3d projectPoint(const Eigen::Vector3d & p) const;

  /// The normal to the vector (norm = 1)
  Eigen::Vector3d normal;

  /// The distance to origin
  double dist;
};

}
