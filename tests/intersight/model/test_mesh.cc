#include <gtest/gtest.h>
#include <intersight/model/mesh.h>

using namespace intersight;

TEST(Mesh3d, no_args_constructor) {
  Mesh3d<float> mesh;
  EXPECT_EQ(mesh.get_vertices().size(), 0);
}
