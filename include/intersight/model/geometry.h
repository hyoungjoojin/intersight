#ifndef INTERSIGHT_MODEL_GEOMETRY_H_
#define INTERSIGHT_MODEL_GEOMETRY_H_

#include <array>
#include <istream>
namespace intersight {

class Triangle3d {
public:
  Triangle3d();

  inline const std::array<unsigned int, 3> &get_vertex_indices() const {
    return vertex_indices_;
  }

  inline const std::array<unsigned int, 3> &
  get_vertex_texture_coordinate_indices() const {
    return vertex_texture_coordinate_indices_;
  }

  inline const std::array<unsigned int, 3> &get_vertex_normal_incdices() const {
    return vertex_normal_indices_;
  }

  static const std::tuple<unsigned int, unsigned int, unsigned int>
  parse_component(const std::string &a, const char delimiter = '/');

  friend std::istream &operator>>(std::istream &, Triangle3d &);

private:
  std::array<unsigned int, 3> vertex_indices_;
  std::array<unsigned int, 3> vertex_texture_coordinate_indices_;
  std::array<unsigned int, 3> vertex_normal_indices_;
};

} // namespace intersight

#endif // !INTERSIGHT_MODEL_GEOMETRY_H_
