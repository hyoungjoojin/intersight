#ifndef INTERSIGHT_MESH_H_
#define INTERSIGHT_MESH_H_

#include "intersight/model/primitives.h"
#include <array>
#include <string>
#include <vector>
namespace intersight {

template <typename T> class Mesh3d {
public:
  Mesh3d();
  Mesh3d(const std::string &);

  void load_obj(const std::string &);

  const std::vector<Vector3d<T>> &get_vertices() const;
  const std::vector<std::array<unsigned int, 3>> &get_faces() const;

private:
  std::vector<Vector3d<T>> vertices_;
  std::vector<std::array<unsigned int, 3>> faces_;
};

template <typename T>
std::ostream &operator<<(std::ostream &ostream, const Mesh3d<T> &mesh) {
  ostream << "Mesh object located at " << &mesh << '\n';
  ostream << "  Number of vertices: " << mesh.get_vertices().size() << '\n';
  ostream << "  Number of faces: " << mesh.get_faces().size() << '\n';
  return ostream;
}

} // namespace intersight

#endif // !INTERSIGHT_MESH_H_
