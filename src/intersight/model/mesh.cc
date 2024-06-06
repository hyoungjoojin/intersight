#include <algorithm>
#include <array>
#include <fstream>
#include <intersight/model/geometry.h>
#include <intersight/model/mesh.h>
#include <intersight/model/primitives.h>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace intersight;

template <typename T> Mesh3d<T>::Mesh3d() {
  vertices_ = std::vector<Vector3d<T>>();
  faces_ = std::vector<Triangle3d>();
}

template <typename T>
Mesh3d<T>::Mesh3d(const std::string &filename, bool normalize) {
  vertices_ = std::vector<Vector3d<T>>();
  faces_ = std::vector<Triangle3d>();

  load_obj(filename);

  if (normalize)
    normalize_();
}

template <typename T> void Mesh3d<T>::load_obj(const std::string &filename) {
  std::ifstream ifstream(filename);

  if (ifstream.fail()) {
    std::cerr << "Failed to open file " << filename << '\n';
    return;
  }

  std::string line, command;
  while (std::getline(ifstream, line)) {
    std::istringstream istream(line);
    istream >> command;

    if (command == "#")
      continue;

    if (command == "v") {
      Vector3d<T> vertex;
      istream >> vertex;
      vertices_.emplace_back(vertex);
      continue;
    }

    if (command == "f") {
      Triangle3d triangle;
      istream >> triangle;
      faces_.emplace_back(triangle);
      continue;
    }
  }
}

template <typename T>
const std::vector<Vector3d<T>> &Mesh3d<T>::get_vertices() const {
  return vertices_;
}

template <typename T>
const std::vector<Triangle3d> &Mesh3d<T>::get_faces() const {
  return faces_;
}

template <typename T> void Mesh3d<T>::normalize_() {
  T min_x = std::numeric_limits<T>::max(),
    min_y = std::numeric_limits<T>::max(),
    min_z = std::numeric_limits<T>::max(),
    max_x = std::numeric_limits<T>::min(),
    max_y = std::numeric_limits<T>::min(),
    max_z = std::numeric_limits<T>::min();

  for (const Vector3d<T> &vertex : vertices_) {
    min_x = std::min(min_x, vertex.get_x());
    min_y = std::min(min_y, vertex.get_y());
    min_z = std::min(min_z, vertex.get_z());
    max_x = std::max(max_x, vertex.get_x());
    max_y = std::max(max_y, vertex.get_y());
    max_z = std::max(max_z, vertex.get_z());
  }

  std::array<T, 3> differences = {max_x - min_x, max_y - min_y, max_z - min_z};
  T scale = *std::max_element(differences.begin(), differences.end());

  Vector3d<T> translate((max_x + min_x) / 2, (max_y + min_y) / 2,
                        (max_z + min_z) / 2);

  for (Vector3d<T> &vertex : vertices_) {
    vertex -= translate;
    vertex /= scale;
  }
}

template class intersight::Mesh3d<float>;
template class intersight::Mesh3d<double>;
template class intersight::Mesh3d<long double>;
