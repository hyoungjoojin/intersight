#include <array>
#include <intersight/model/geometry.h>
#include <string>

using namespace intersight;

Triangle3d::Triangle3d() { vertices_ = std::array<unsigned int, 3>(); }

const std::array<unsigned int, 3> &Triangle3d::get_vertices() const {
  return vertices_;
}

void Triangle3d::parse_vertex_(const std::string &vertex_string,
                               unsigned int &vertex_index) {
  if (vertex_string.find('/') != -1) {
    vertex_index = std::stoi(vertex_string.substr(0, vertex_string.find('/')));
  } else {
    vertex_index = std::stoi(vertex_string);
  }

  vertex_index -= 1;
}

namespace intersight {

std::istream &operator>>(std::istream &istream, Triangle3d &triangle) {
  std::string x_string, y_string, z_string;
  istream >> x_string >> y_string >> z_string;

  triangle.parse_vertex_(x_string, triangle.vertices_[0]);
  triangle.parse_vertex_(y_string, triangle.vertices_[1]);
  triangle.parse_vertex_(z_string, triangle.vertices_[2]);

  return istream;
}

} // namespace intersight
