#pragma once

#include <starkit_utils/angle.h>

namespace starkit_geometry
{
/// Represent a vector using pan and tilt to set the direction
/// Positive tilt means that the robot is looking down
class PanTilt
{
public:
  PanTilt(const starkit_utils::Angle& pan, const starkit_utils::Angle& tilt);

  /// Return the PanTilt corresponding to the view vector
  /// Note:
  /// - If vector(0) == 0 and vector(1) == 0, then pan is 0
  /// - If norm(vector) is 0, then throw a runtime_error
  PanTilt(const Eigen::Vector3d& vector);

  Eigen::Vector3d toViewVector() const;

  starkit_utils::Angle pan;

  starkit_utils::Angle tilt;
};

}  // namespace starkit_geometry
