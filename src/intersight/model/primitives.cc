#include <intersight/model/primitives.h>

using namespace intersight;

template <typename T> Vector3d<T>::Vector3d() : x_(0), y_(0), z_(0) {}

template <typename T>
Vector3d<T>::Vector3d(T x, T y, T z) : x_(x), y_(y), z_(z) {}

template <typename T> const T Vector3d<T>::get_x() const { return x_; }
template <typename T> const T Vector3d<T>::get_y() const { return y_; }
template <typename T> const T Vector3d<T>::get_z() const { return z_; }

template <typename T> void Vector3d<T>::set_x(T x) { x_ = x; }
template <typename T> void Vector3d<T>::set_y(T y) { y_ = y; }
template <typename T> void Vector3d<T>::set_z(T z) { z_ = z; }

template class intersight::Vector3d<float>;
template class intersight::Vector3d<double>;
template class intersight::Vector3d<long double>;
