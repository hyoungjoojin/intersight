#ifndef INTERSIGHT_MODEL_PRIMITIVES_H_
#define INTERSIGHT_MODEL_PRIMITIVES_H_

#include <cstdlib>
#include <iostream>

namespace intersight {

template <typename T> class Vector2d {
public:
  Vector2d();
  Vector2d(T, T);

  Vector2d<T> operator+(const Vector2d<T> &) const;
  Vector2d<T> operator*(const T) const;

  const T get_x() const;
  const T get_y() const;

private:
  T x_;
  T y_;
};

template <typename T> class Vector3d {
public:
  Vector3d();
  Vector3d(T, T, T);

  Vector3d<T> operator+(const Vector3d<T> &) const;
  Vector3d<T> operator-(const Vector3d<T> &) const;
  Vector3d<T> operator*(const T) const;
  Vector3d<T> operator/(const T) const;

  T operator*(const Vector3d<T> &) const;

  const T get_x() const;
  const T get_y() const;
  const T get_z() const;

  void set_x(T x);
  void set_y(T y);
  void set_z(T z);

private:
  T x_;
  T y_;
  T z_;
};

template <typename T>
std::istream &operator>>(std::istream &istream, Vector3d<T> &vector) {
  T x, y, z;
  istream >> x >> y >> z;

  if (!istream) {
    istream.fail();
  } else {
    vector.set_x(x);
    vector.set_y(y);
    vector.set_z(z);
  }

  return istream;
}

template <typename T>
std::ostream &operator<<(std::ostream &ostream, const Vector3d<T> &vector) {
  return ostream << "[" << vector.get_x() << ", " << vector.get_y() << ", "
                 << vector.get_z() << "]";
}

} // namespace intersight

#endif // !INTERSIGHT_MODEL_PRIMITIVES_H_
