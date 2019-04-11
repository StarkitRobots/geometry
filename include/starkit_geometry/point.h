#pragma once

#include <iostream>
#include <vector>

#include "starkit_utils/angle.h"

#include <Eigen/Core>

namespace starkit_geometry
{
class Point
{
public:
  double x;
  double y;
  Point() : x(0.0), y(0.0){};
  Point(const Point& other) : x(other.x), y(other.y){};
  Point(double x, double y) : x(x), y(y){};
  Point(const Eigen::Vector2d& p);

  double getX() const
  {
    return x;
  };
  double getY() const
  {
    return y;
  };

  // TODO handle case with point at 0.0, 0.0 in getTheta and isCollinear
  starkit_utils::Angle getTheta() const;
  bool isCollinear(const Point& other) const;
  /* Return the distance to point in {0,0} */
  double getLength() const;
  double getDist(const Point& other) const;
  Point& normalize(double newLength = 1);

  /* Return a Point with a rotation of 90° */
  Point perpendicular() const;
  Point rotation(const starkit_utils::Angle& a) const;
  Point rotation(const starkit_utils::Angle& a, const Point& rotCenter) const;

  static double dotProduct(const Point& p1, const Point& p2);
  static double perpDotProduct(const Point& p1, const Point& p2);

  Point operator-() const;

  Point operator+(const Point& other) const;
  Point operator-(const Point& other) const;
  Point operator*(double ratio) const;
  Point operator/(double ratio) const;

  Point& operator+=(const Point& other);
  Point& operator-=(const Point& other);
  Point& operator*=(double ratio);
  Point& operator/=(double ratio);

  static Point mkPointFromPolar(double rho, starkit_utils::Angle theta);

  // Random points creators
  static Point mkRandomPolar(double rhoMax);
  static Point mkRandomPolar(double rhoMin, double rhoMax, double thetaMin = 0.0, double thetaMax = 360.0);

  bool operator==(const Point& other) const;
};

starkit_geometry::Point operator*(double ratio, const starkit_geometry::Point& p);

std::ostream& operator<<(std::ostream& out, const starkit_geometry::Point& p);

}  // namespace starkit_geometry

/* Return the point which is the average of the points in the vector */
starkit_geometry::Point average(const std::vector<starkit_geometry::Point>& points);
/* Return sum(points[i]* weights[i]) / sum(weights[i]) */
starkit_geometry::Point average(const std::vector<starkit_geometry::Point>& points, const std::vector<double>& weights);
/* Return the standard deviation to the average of the points */
double stdDev(const std::vector<starkit_geometry::Point>& points);
