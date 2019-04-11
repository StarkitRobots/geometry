#include "starkit_geometry/point_cluster.h"

namespace starkit_geometry
{
bool PointCluster::acceptPoint(const Point& candidate, float dist_tol) const
{
  return average.getDist(candidate) <= dist_tol;
}

void PointCluster::push(const Point& p)
{
  // Updating average
  int k = size();
  average = (average * k + p) / (k + 1);

  points.push_back(p);
}

}  // namespace starkit_geometry

void addToClusters(const starkit_geometry::Point& p, std::vector<starkit_geometry::PointCluster>& clusters,
                   float dist_tol)
{
  bool accepted = false;
  // Insert in a cluster if possible
  for (unsigned int i = 0; i < clusters.size(); i++)
  {
    if (clusters[i].acceptPoint(p, dist_tol))
    {
      accepted = true;
      clusters[i].push(p);
      break;
    }
  }
  // If no cluster matches, create a new one
  if (!accepted)
  {
    clusters.push_back(starkit_geometry::PointCluster(p));
  }
}

std::vector<starkit_geometry::PointCluster> createClusters(const std::vector<starkit_geometry::Point>& points,
                                                          float dist_tol)
{
  std::vector<starkit_geometry::PointCluster> clusters;
  for (const starkit_geometry::Point& p : points)
  {
    addToClusters(p, clusters, dist_tol);
  }
  return clusters;
}
