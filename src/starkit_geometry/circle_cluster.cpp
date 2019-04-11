#include "starkit_geometry/circle_cluster.h"

namespace starkit_geometry
{
bool CircleCluster::acceptCircle(const Circle& candidate, float flatTol, float percentTol) const
{
  return similarCircles(getAverage(), candidate, flatTol, percentTol);
}

void CircleCluster::push(const Circle& c)
{
  // Updating average
  int k = size();
  float newRadius = (average.getRadius() * k + c.getRadius()) / (k + 1);
  Point newCenter = (average.getCenter() * k + c.getCenter()) / (k + 1);
  average = Circle(newCenter, newRadius);

  circles.push_back(c);
}

bool CircleCluster::similarCircles(const Circle& c1, const Circle& c2, float flatTol, float percentTol)
{
  // Ensures that c2 radius is bigger than c1 radius, otherwise swap params
  if (c1.getRadius() > c2.getRadius())
    return similarCircles(c2, c1, flatTol, percentTol);
  float tol = flatTol + c1.getRadius() * (percentTol / 100);
  bool radOk = (c2.getRadius() - c1.getRadius()) < tol;
  float centerDist = (c1.getCenter() - c2.getCenter()).getLength();
  bool centerOk = centerDist < tol;
  return radOk && centerOk;
}

}  // namespace starkit_geometry

void addToClusters(const starkit_geometry::Circle& c, std::vector<starkit_geometry::CircleCluster>& clusters,
                   float flatTol, float percentTol)
{
  bool accepted = false;
  // Insert in a cluster if possible
  for (unsigned int i = 0; i < clusters.size(); i++)
  {
    if (clusters[i].acceptCircle(c, flatTol, percentTol))
    {
      accepted = true;
      clusters[i].push(c);
      break;
    }
  }
  // If no cluster matches, create a new one
  if (!accepted)
  {
    clusters.push_back(starkit_geometry::CircleCluster(c));
  }
}

std::vector<starkit_geometry::CircleCluster> createClusters(const std::vector<starkit_geometry::Circle>& circles,
                                                           float flatTol, float percentTol)
{
  std::vector<starkit_geometry::CircleCluster> clusters;
  for (const starkit_geometry::Circle& c : circles)
  {
    addToClusters(c, clusters, flatTol, percentTol);
  }
  return clusters;
}
