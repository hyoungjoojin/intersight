#include <array>
#include <gtest/gtest.h>
#include <intersight/model/geometry.h>
#include <sstream>

using namespace intersight;

TEST(Triangle3d, parse_component) {
  Triangle3d triangle;

  int num_testcases = 3;
  std::string components[] = {"1/2/3", "1//3", "1", "1/2"};
  unsigned int answers[][3] = {{1, 2, 3}, {1, 0, 3}, {1, 0, 0}, {1, 2, 0}};

  for (int i = 0; i < num_testcases; i++) {
    auto &[vertex_index, vertex_texture_coordinate_index, vertex_normal_index] =
        triangle.parse_component(components[i]);

    EXPECT_EQ(vertex_index, answers[i][0]);
    EXPECT_EQ(vertex_texture_coordinate_index, answers[i][1]);
    EXPECT_EQ(vertex_normal_index, answers[i][2]);
  }
}

TEST(Triangle3d, operator_istream) {
  Triangle3d triangle;

  std::stringstream ss("1 2 3");
  ss >> triangle;

  EXPECT_EQ(triangle.get_vertex_indices()[0], 1);
  EXPECT_EQ(triangle.get_vertex_indices()[1], 2);
  EXPECT_EQ(triangle.get_vertex_indices()[2], 3);

  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[0], 0);
  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[1], 0);
  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[2], 0);

  EXPECT_EQ(triangle.get_vertex_normal_incdices()[0], 0);
  EXPECT_EQ(triangle.get_vertex_normal_incdices()[1], 0);
  EXPECT_EQ(triangle.get_vertex_normal_incdices()[2], 0);

  ss.clear();
  ss.str("1/2/3 2/3/4 3/4/5");
  ss >> triangle;

  EXPECT_EQ(triangle.get_vertex_indices()[0], 1);
  EXPECT_EQ(triangle.get_vertex_indices()[1], 2);
  EXPECT_EQ(triangle.get_vertex_indices()[2], 3);

  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[0], 2);
  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[1], 3);
  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[2], 4);

  EXPECT_EQ(triangle.get_vertex_normal_incdices()[0], 3);
  EXPECT_EQ(triangle.get_vertex_normal_incdices()[1], 4);
  EXPECT_EQ(triangle.get_vertex_normal_incdices()[2], 5);

  ss.clear();
  ss.str("1//3 2//4 3//5");
  ss >> triangle;

  EXPECT_EQ(triangle.get_vertex_indices()[0], 1);
  EXPECT_EQ(triangle.get_vertex_indices()[1], 2);
  EXPECT_EQ(triangle.get_vertex_indices()[2], 3);

  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[0], 0);
  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[1], 0);
  EXPECT_EQ(triangle.get_vertex_texture_coordinate_indices()[2], 0);

  EXPECT_EQ(triangle.get_vertex_normal_incdices()[0], 3);
  EXPECT_EQ(triangle.get_vertex_normal_incdices()[1], 4);
  EXPECT_EQ(triangle.get_vertex_normal_incdices()[2], 5);
}
