#include <gtest/gtest.h>

#include "starkit_geometry/3d/plane.h"

using namespace starkit_geometry;

double epsilon = std::pow(10, -12);

TEST(plane, empty_constructor)
{
  Plane p;
  EXPECT_FLOAT_EQ(0.0, p.normal(0));
  EXPECT_FLOAT_EQ(0.0, p.normal(1));
  EXPECT_FLOAT_EQ(1.0, p.normal(2));
  EXPECT_FLOAT_EQ(0.0, p.dist);
}

TEST(plane, constructor_normalization)
{
  Plane p(Eigen::Vector3d(2, 0, 0), 2);
  EXPECT_FLOAT_EQ(1.0, p.normal(0));
  EXPECT_FLOAT_EQ(0.0, p.normal(1));
  EXPECT_FLOAT_EQ(0.0, p.normal(2));
  EXPECT_FLOAT_EQ(2.0, p.dist);
}

TEST(plane, getDist)
{
  EXPECT_FLOAT_EQ(2.0, Plane(Eigen::Vector3d(1, 0, 0), 0.0).getDist(Eigen::Vector3d(2.0, 1.0, 1.0)));
  EXPECT_FLOAT_EQ(1.0, Plane(Eigen::Vector3d(0, 1, 0), 0.0).getDist(Eigen::Vector3d(2.0, 1.0, 1.0)));
  EXPECT_FLOAT_EQ(1.0, Plane(Eigen::Vector3d(1, 0, 0), 1.0).getDist(Eigen::Vector3d(2.0, 1.0, 1.0)));
  EXPECT_FLOAT_EQ(1.0, Plane(Eigen::Vector3d(1, 0, 0), 0.0).getDist(Eigen::Vector3d(-1.0, 1.0, 1.0)));
}

TEST(plane, projectPoint1)
{
  Plane plane(Eigen::Vector3d(1, 1, 0), 0);
  Eigen::Vector3d point(-1, -1, 0);
  Eigen::Vector3d projected = plane.projectPoint(point);
  Eigen::Vector3d expected(0.0, 0.0, 0.0);
  for (int i = 0; i < 3; i++)
  {
    EXPECT_NEAR(expected(i), projected(i), epsilon);
  }
}

TEST(plane, projectPoint2)
{
  Plane plane(Eigen::Vector3d(1, 1, 0), 0);
  Eigen::Vector3d point(1, 1, 0);
  Eigen::Vector3d projected = plane.projectPoint(point);
  Eigen::Vector3d expected(0.0, 0.0, 0.0);
  for (int i = 0; i < 3; i++)
  {
    EXPECT_NEAR(expected(i), projected(i), epsilon);
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
