#include <algorithm>
#include <intersight/model/primitives.h>
#include <intersight/model/texture.h>
#include <vector>

using namespace intersight;

template <typename T> Texture2d<T>::Texture2d() : width_(800), height_(800) {
  pixels_ = std::vector<std::vector<T>>(height_, std::vector<T>(width_));
};

template <typename T>
Texture2d<T>::Texture2d(int width, int height)
    : width_(width), height_(height) {
  pixels_ = std::vector<std::vector<T>>(height_, std::vector<T>(width_));
};

template <typename T>
Texture2d<T>::Texture2d(const std::vector<std::vector<T>> &pixels)
    : pixels_(pixels) {
  width_ = pixels_[0].size();
  height_ = pixels_.size();
};

template <typename T> void Texture2d<T>::add_pixel(const Vector2d<T> &vector) {
  // Assuming pixel range is between -1 and 1.
  T x = vector.get_x(), y = vector.get_y();
  if (x < -1 || x >= 1 || y < -1 || y >= 1)
    return;

  int w = int((x + 1) * width_ / 2);
  int h = int((y + 1) * height_ / 2);
  pixels_[h][w] += 1;
}

template <typename T> const Texture2d<T> Texture2d<T>::normalize() const {
  T max_value = 0;

  for (const auto &row : pixels_)
    for (const auto &value : row)
      max_value = std::max(max_value, value);

  std::vector<std::vector<T>> normalized_pixels = pixels_;
  for (auto &row : normalized_pixels) {
    for (auto &value : row) {
      value /= max_value;
    }
  }

  Texture2d<T> normalized_texture = Texture2d(normalized_pixels);

  return normalized_texture;
}

template <typename T>
const std::vector<std::vector<T>> &Texture2d<T>::get_pixels() const {
  return pixels_;
}

template class intersight::Texture2d<float>;
template class intersight::Texture2d<double>;
template class intersight::Texture2d<long double>;
