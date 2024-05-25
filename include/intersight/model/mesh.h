#ifndef INTERSIGHT_MESH_H_
#define INTERSIGHT_MESH_H_

#include "intersight/model/primitives.h"
#include <string>
#include <vector>
namespace intersight {

template <typename T> class Mesh3d {
public:
  Mesh3d();
  Mesh3d(const std::string &);

  void load_obj(const std::string &);

  const std::vector<Vector3d<T>> &get_vertices() const;

private:
  std::vector<Vector3d<T>> vertices_;
};

template <typename T>
std::ostream &operator<<(std::ostream &ostream, const Mesh3d<T> &mesh) {
  ostream << "Mesh object located at " << &mesh << '\n';
  ostream << "  Number of vertices: " << mesh.get_vertices().size() << '\n';
  return ostream;
}

} // namespace intersight

#endif // !INTERSIGHT_MESH_H_
