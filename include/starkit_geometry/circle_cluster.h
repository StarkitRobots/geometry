#pragma once

#include "starkit_geometry/circle.h"

namespace starkit_geometry
{
class CircleCluster
{
private:
  std::vector<Circle> circles;
  Circle average;

public:
  CircleCluster(const Circle& c) : average(c)
  {
    circles.push_back(c);
  }

  unsigned int size() const
  {
    return circles.size();
  }

  const Circle& getAverage() const
  {
    return average;
  }

  bool acceptCircle(const Circle& candidate, float flatTol, float PercentTol) const;

  void push(const Circle& c);

  /* Return true if the two circles are similar according to the parameter
   * used.
   */
  static bool similarCircles(const Circle& c1, const Circle& c2, float flatTol, float percentTol);
};

}  // namespace starkit_geometry

/**
 * Add the given circle to the clusters, if the circle doesn't match any of
 * the clusters, then create a new Cluster
 */
void addToClusters(const starkit_geometry::Circle& c, std::vector<starkit_geometry::CircleCluster>& clusters,
                   float flatTol, float percentTol);

std::vector<starkit_geometry::CircleCluster> createClusters(const std::vector<starkit_geometry::Circle>& circles,
                                                           float flatTol, float percentTol);
