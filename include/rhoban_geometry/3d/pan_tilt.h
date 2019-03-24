#pragma once

#include <rhoban_utils/angle.h>

namespace rhoban_geometry
{
/// Represent a vector using pan and tilt to set the direction
/// Positive tilt means that the robot is looking down
class PanTilt
{
public:
  PanTilt(const rhoban_utils::Angle& pan, const rhoban_utils::Angle& tilt);

  /// Return the PanTilt corresponding to the view vector
  /// Note:
  /// - If vector(0) == 0 and vector(1) == 0, then pan is 0
  /// - If norm(vector) is 0, then throw a runtime_error
  PanTilt(const Eigen::Vector3d& vector);

  Eigen::Vector3d toViewVector() const;

  rhoban_utils::Angle pan;

  rhoban_utils::Angle tilt;
};

}  // namespace rhoban_geometry
