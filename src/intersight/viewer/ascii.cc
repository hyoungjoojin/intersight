#include "intersight/model/texture.h"
#include <intersight/viewer/ascii.h>
#include <iostream>

using namespace intersight;

AsciiViewer::AsciiViewer() {}

template <typename T>
void AsciiViewer::view(const Texture2d<T> &texture) const {
  const Texture2d<T> &normalized_texture = texture.normalize();

  for (const auto &row : normalized_texture.get_pixels()) {
    for (const T value : row)
      std::cout << this->get_character(value);
    std::cout << std::endl;
  }
}

template <typename T> char AsciiViewer::get_character(const T value) {
  return ASCII_RENDERING_CHARACTERS_[int(value *
                                         ASCII_RENDERING_CHARACTERS_.length())];
}

template void AsciiViewer::view(const Texture2d<float> &) const;
template void AsciiViewer::view(const Texture2d<double> &) const;
template void AsciiViewer::view(const Texture2d<long double> &) const;
