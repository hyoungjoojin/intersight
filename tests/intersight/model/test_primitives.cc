#include <gtest/gtest.h>
#include <intersight/model/primitives.h>
#include <sstream>

using namespace intersight;

const double ABS_ERROR = 1e-4;

TEST(Vector3d, no_args_constructor_float) {
  Vector3d<float> vector;
  EXPECT_NEAR(vector.get_x(), 0, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 0, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 0, ABS_ERROR);
}

TEST(Vector3d, no_args_constructor_double) {
  Vector3d<double> vector;
  EXPECT_NEAR(vector.get_x(), 0, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 0, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 0, ABS_ERROR);
}

TEST(Vector3d, no_args_constructor_long_double) {
  Vector3d<long double> vector;
  EXPECT_NEAR(vector.get_x(), 0, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 0, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 0, ABS_ERROR);
}

TEST(Vector3d, all_args_constructor_float) {
  Vector3d<float> vector(1.5, 2.5, 3.5);
  EXPECT_NEAR(vector.get_x(), 1.5, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 2.5, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 3.5, ABS_ERROR);
}

TEST(Vector3d, all_args_constructor_double) {
  Vector3d<double> vector(1.5, 2.5, 3.5);
  EXPECT_NEAR(vector.get_x(), 1.5, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 2.5, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 3.5, ABS_ERROR);
}

TEST(Vector3d, all_args_constructor_long_double) {
  Vector3d<long double> vector(1.5, 2.5, 3.5);
  EXPECT_NEAR(vector.get_x(), 1.5, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 2.5, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 3.5, ABS_ERROR);
}

TEST(Vector3d, operator_add) {
  Vector3d<float> vector_lhs(1.1, 2.2, 3.3);
  Vector3d<float> vector_rhs(2.2, 3.3, 4.4);
  Vector3d<float> vector_result = vector_lhs + vector_rhs;

  EXPECT_NEAR(vector_result.get_x(), 3.3, ABS_ERROR);
  EXPECT_NEAR(vector_result.get_y(), 5.5, ABS_ERROR);
  EXPECT_NEAR(vector_result.get_z(), 7.7, ABS_ERROR);
}

TEST(Vector3d, operator_subtract) {
  Vector3d<float> vector_lhs(2.2, 3.3, 4.4);
  Vector3d<float> vector_rhs(1.1, 2.2, 3.3);
  Vector3d<float> vector_result = vector_lhs - vector_rhs;

  EXPECT_NEAR(vector_result.get_x(), 1.1, ABS_ERROR);
  EXPECT_NEAR(vector_result.get_y(), 1.1, ABS_ERROR);
  EXPECT_NEAR(vector_result.get_z(), 1.1, ABS_ERROR);
}

TEST(Vector3d, setter) {
  Vector3d<float> vector;
  vector.set_x(1.1);
  vector.set_y(2.2);
  vector.set_z(3.3);
  EXPECT_NEAR(vector.get_x(), 1.1, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 2.2, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 3.3, ABS_ERROR);
}

TEST(Vector3d, operator_istream) {
  std::stringstream ss("4.4 5.5 6.6");
  Vector3d<float> vector;
  ss >> vector;
  EXPECT_NEAR(vector.get_x(), 4.4, ABS_ERROR);
  EXPECT_NEAR(vector.get_y(), 5.5, ABS_ERROR);
  EXPECT_NEAR(vector.get_z(), 6.6, ABS_ERROR);
}

TEST(Vector3d, operator_ostream) {
  std::stringstream ss;
  Vector3d<float> vector(7, 8, 9);
  ss << vector;
  EXPECT_EQ(ss.str(), "[7, 8, 9]");
}
