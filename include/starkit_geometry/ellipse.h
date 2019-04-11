#pragma once

#include "starkit_geometry/point.h"

namespace starkit_geometry
{
class Ellipse
{
private:
  Point origin;
  starkit_utils::Angle theta;  // Angle from x-axis to m axis
  double m;
  double n;  // n <= m
public:
  Ellipse() : origin(), theta(), m(1), n(1)
  {
  }
  Ellipse(const Point& p, const starkit_utils::Angle& axisAngle, double bigAxisLength, double smallAxisLength)
  {
    origin = p;
    theta = axisAngle;
    m = bigAxisLength;
    n = smallAxisLength;
  }
  Ellipse(const Ellipse& e) : origin(e.origin), theta(e.theta), m(e.m), n(e.n)
  {
  }

  Point getCenter() const
  {
    return origin;
  }
  double getBigRadius() const
  {
    return m;
  }
  double getSmallRadius() const
  {
    return n;
  }
  starkit_utils::Angle getAngle() const
  {
    return theta;
  }
};

}  // namespace starkit_geometry
