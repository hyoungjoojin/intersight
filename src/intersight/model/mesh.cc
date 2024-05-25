#include <array>
#include <fstream>
#include <intersight/model/mesh.h>
#include <intersight/model/primitives.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace intersight;

template <typename T> Mesh3d<T>::Mesh3d() {
  vertices_ = std::vector<Vector3d<T>>();
  faces_ = std::vector<std::array<unsigned int, 3>>();
}

template <typename T> Mesh3d<T>::Mesh3d(const std::string &filename) {
  vertices_ = std::vector<Vector3d<T>>();
  faces_ = std::vector<std::array<unsigned int, 3>>();

  // TODO: Right now assuming all file are .obj files.
  this->load_obj(filename);
}

// TODO: This function is getting pretty big now.
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
      std::array<unsigned int, 3> face;
      for (int i = 0; i < 3; i++) {
        istream >> face[i];
        if (--face[i] < vertices_.size())
          continue;

        std::cerr
            << "Given file contains a face that has vertices out of bounds."
            << filename << '\n';
        return;
      }

      faces_.emplace_back(face);
    }
  }
}

template <typename T>
const std::vector<Vector3d<T>> &Mesh3d<T>::get_vertices() const {
  return vertices_;
}

template <typename T>
const std::vector<std::array<unsigned int, 3>> &Mesh3d<T>::get_faces() const {
  return faces_;
}

template class intersight::Mesh3d<float>;
template class intersight::Mesh3d<double>;
template class intersight::Mesh3d<long double>;
