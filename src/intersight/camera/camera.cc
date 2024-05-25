#include <intersight/camera/camera.h>
#include <intersight/model/primitives.h>

using namespace intersight;

template <typename T> Camera<T>::Camera() {
  position_ = Vector3d<T>();
  direction_ = Vector3d<T>();
}

template class intersight::Camera<float>;
template class intersight::Camera<double>;
template class intersight::Camera<long double>;
