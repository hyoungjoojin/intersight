#include <intersight/model/primitives.h>

using namespace intersight;

template <typename T> Vector2d<T>::Vector2d() : x_(0), y_(0) {}

template <typename T> Vector2d<T>::Vector2d(T x, T y) : x_(x), y_(y) {}

template <typename T>
Vector2d<T> Vector2d<T>::operator+(const Vector2d<T> &vector) const {
  return Vector2d(x_ + vector.x_, y_ + vector.y_);
}

template <typename T> Vector2d<T> Vector2d<T>::operator*(const T scalar) const {
  return Vector2d(scalar * x_, scalar * y_);
}

template <typename T> const T Vector2d<T>::get_x() const { return x_; }
template <typename T> const T Vector2d<T>::get_y() const { return y_; }

template class intersight::Vector2d<float>;
template class intersight::Vector2d<double>;
template class intersight::Vector2d<long double>;

template <typename T> Vector3d<T>::Vector3d() : x_(0), y_(0), z_(0) {}

template <typename T>
Vector3d<T>::Vector3d(T x, T y, T z) : x_(x), y_(y), z_(z) {}

template <typename T>
Vector3d<T> Vector3d<T>::operator+(const Vector3d<T> &vector) const {
  return Vector3d(x_ + vector.x_, y_ + vector.y_, z_ + vector.z_);
}

template <typename T>
Vector3d<T> Vector3d<T>::operator-(const Vector3d<T> &vector) const {
  return Vector3d(x_ - vector.x_, y_ - vector.y_, z_ - vector.z_);
}

template <typename T> Vector3d<T> Vector3d<T>::operator*(const T scalar) const {
  return Vector3d(scalar * x_, scalar * y_, scalar * z_);
}

template <typename T> Vector3d<T> Vector3d<T>::operator/(const T scalar) const {
  return Vector3d(x_ / scalar, y_ / scalar, z_ / scalar);
}

template <typename T>
T Vector3d<T>::operator*(const Vector3d<T> &vector) const {
  return x_ * vector.x_ + y_ * vector.y_ + z_ * vector.z_;
}

template <typename T> const T Vector3d<T>::get_x() const { return x_; }
template <typename T> const T Vector3d<T>::get_y() const { return y_; }
template <typename T> const T Vector3d<T>::get_z() const { return z_; }

template <typename T> void Vector3d<T>::set_x(T x) { x_ = x; }
template <typename T> void Vector3d<T>::set_y(T y) { y_ = y; }
template <typename T> void Vector3d<T>::set_z(T z) { z_ = z; }

template class intersight::Vector3d<float>;
template class intersight::Vector3d<double>;
template class intersight::Vector3d<long double>;
