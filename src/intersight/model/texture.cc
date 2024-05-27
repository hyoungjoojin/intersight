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

template <typename T> void Texture2d<T>::add_pixel(const Vector2d<T> &vector) {
  // Assuming pixel range is between -1 and 1.
  T x = vector.get_x(), y = vector.get_y();
  if (x < -1 || x >= 1 || y < -1 || y >= 1)
    return;

  int w = int((x + 1) * width_ / 2);
  int h = int((y + 1) * height_ / 2);
  pixels_[h][w] += 1;
}

template <typename T>
const std::vector<std::vector<T>> &Texture2d<T>::get_pixels() const {
  return pixels_;
}

template class intersight::Texture2d<float>;
template class intersight::Texture2d<double>;
template class intersight::Texture2d<long double>;
