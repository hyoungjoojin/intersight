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
const std::vector<std::vector<T>> &Texture2d<T>::get_pixels() const {
  return pixels_;
}

template class intersight::Texture2d<float>;
template class intersight::Texture2d<double>;
template class intersight::Texture2d<long double>;
