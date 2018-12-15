#include <gtest/gtest.h>

#include "rhoban_geometry/3d/intersection.h"
#include "rhoban_geometry/3d/plane.h"
#include "rhoban_geometry/3d/ray.h"

using namespace rhoban_geometry;

double epsilon = std::pow(10,-12);

TEST(rayAndPoint, isIntersectionPoint) {
  Ray r; Plane p;
  /// Line of ray does not intersect plane
  r = Ray(Eigen::Vector3d(0,0,0), Eigen::Vector3d(1,0,0));
  p = Plane(Eigen::Vector3d(0,1,0), 1);
  EXPECT_FALSE(isIntersectionPoint(r,p));
  /// Ray is included in the plane
  r = Ray(Eigen::Vector3d(0,0,0), Eigen::Vector3d(1,0,0));
  p = Plane(Eigen::Vector3d(0,1,0), 0);
  EXPECT_FALSE(isIntersectionPoint(r,p));
  /// Plane behind ray
  r = Ray(Eigen::Vector3d(5,0,0), Eigen::Vector3d(1,0,0));
  p = Plane(Eigen::Vector3d(1,0,0), 0);
  EXPECT_FALSE(isIntersectionPoint(r,p));
  /// Successful intersection
  r = Ray(Eigen::Vector3d(1,0,1), Eigen::Vector3d(0,0,-1));
  p = Plane(Eigen::Vector3d(0,0,1), 0);
  EXPECT_TRUE(isIntersectionPoint(r,p));
}

TEST(rayAndPoint, getIntersection) {
  Ray r; Plane p;
  Eigen::Vector3d computed, expected;
  /// Perpendicular ray
  r = Ray(Eigen::Vector3d(1,0,1), Eigen::Vector3d(0,0,-1));
  p = Plane(Eigen::Vector3d(0,0,1), 0);
  computed = getIntersection(r,p);
  expected = Eigen::Vector3d(1,0,0);
  for (int d = 0; d < 3; d++) {
    EXPECT_NEAR(expected(d), computed(d), epsilon);
  }
  /// Non-perpendicular ray
  r = Ray(Eigen::Vector3d(0,0,1), Eigen::Vector3d(2.0,1.0,-0.2));
  p = Plane(Eigen::Vector3d(0,0,1), 0.6);
  computed = getIntersection(r,p);
  expected = Eigen::Vector3d(4,2,0.6);
  for (int d = 0; d < 3; d++) {
    EXPECT_NEAR(expected(d), computed(d), epsilon);
  }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
