#include <gtest/gtest.h>
#include <intersight/model/geometry.h>
#include <sstream>

using namespace intersight;

TEST(Triangle3d, operator_istream) {
  std::stringstream ss("1 2 3");

  Triangle3d triangle;
  ss >> triangle;

  EXPECT_EQ(triangle.get_vertices()[0], 0);
  EXPECT_EQ(triangle.get_vertices()[1], 1);
  EXPECT_EQ(triangle.get_vertices()[2], 2);
  ss.clear();

  ss.str("1/2/3 2/3/4 3/4/5");
  ss >> triangle;

  EXPECT_EQ(triangle.get_vertices()[0], 0);
  EXPECT_EQ(triangle.get_vertices()[1], 1);
  EXPECT_EQ(triangle.get_vertices()[2], 2);
  ss.clear();
}
