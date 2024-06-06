#include <array>
#include <intersight/model/geometry.h>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

using namespace intersight;

Triangle3d::Triangle3d() {
  vertex_indices_ = std::array<unsigned int, 3>({0});
  vertex_texture_coordinate_indices_ = std::array<unsigned int, 3>({0});
  vertex_normal_indices_ = std::array<unsigned int, 3>({0});
}

const std::tuple<unsigned int, unsigned int, unsigned int>
Triangle3d::parse_component(const std::string &str, const char delimiter) {
  unsigned int vertex_index, vertex_texture_coordinate_index,
      vertex_normal_index;

  unsigned long first_pos = str.find(delimiter);
  if (first_pos == std::string::npos)
    return {std::stoi(str), 0, 0};

  vertex_index = std::stoi(str.substr(0, first_pos));

  unsigned long second_pos = str.find(delimiter, first_pos + 1);
  if (second_pos == std::string::npos)
    return {vertex_index, std::stoi(str.substr(first_pos + 1)), 0};

  vertex_texture_coordinate_index =
      (first_pos + 1 == second_pos
           ? 0
           : std::stoi(str.substr(first_pos + 1, second_pos)));
  vertex_normal_index = std::stoi(str.substr(second_pos + 1));

  return {vertex_index, vertex_texture_coordinate_index, vertex_normal_index};
}

namespace intersight {

std::istream &operator>>(std::istream &istream, Triangle3d &triangle) {
  std::string vertex_information;

  for (int i = 0; i < 3; i++) {
    istream >> vertex_information;

    int current_pos = 0;

    std::string delimiter = "/";

    auto &[vertex_index, vertex_texture_coordinate_index, vertex_normal_index] =
        triangle.parse_component(vertex_information);

    triangle.vertex_indices_[i] = vertex_index;
    triangle.vertex_texture_coordinate_indices_[i] =
        vertex_texture_coordinate_index;
    triangle.vertex_normal_indices_[i] = vertex_normal_index;
  }

  return istream;
}

} // namespace intersight
