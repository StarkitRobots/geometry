#include "rhoban_geometry/3d/pan_tilt.h"

#include <rhoban_utils/util.h>

using rhoban_utils::Angle;

namespace rhoban_geometry
{

PanTilt::PanTilt(const Angle & pan, const Angle & tilt) : pan(pan), tilt(tilt)
{
}

PanTilt::PanTilt(const Eigen::Vector3d & v)
{
  if (v(0) == 0 && v(1) == 0) {
    if (v(2) == 0) throw std::runtime_error(DEBUG_INFO + ": norm of vector is 0");
    pan = Angle(0);
    tilt = v(2) > 0 ? Angle(-90) : Angle(90);
  } else {
    double dxy = sqrt(v(0)*v(0) + v(1)*v(1));
    pan = Angle::fromXY(v(0), v(1));
    tilt = Angle::fromXY(dxy, - v(2));
  }
}

Eigen::Vector3d PanTilt::toViewVector() const
{
  return Eigen::Vector3d(cos(pan) * cos(tilt),
                         sin(pan) * cos(tilt),
                         -sin(tilt));
}

}
