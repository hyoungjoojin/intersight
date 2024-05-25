#ifndef INTERSIGHT_CAMERA_CAMERA_H_
#define INTERSIGHT_CAMERA_CAMERA_H_

#include <intersight/model/primitives.h>

namespace intersight {

template <typename T> class Camera {
public:
  Camera();

private:
  Vector3d<T> position_;
  Vector3d<T> direction_;
};

} // namespace intersight

#endif // !INTERSIGHT_CAMERA_CAMERA_H_
