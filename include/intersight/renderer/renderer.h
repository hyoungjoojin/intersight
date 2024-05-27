#ifndef INTERSIGHT_RENDERER_RENDERER_H_
#define INTERSIGHT_RENDERER_RENDERER_H_

#include <intersight/camera/camera.h>
#include <intersight/model/mesh.h>
#include <intersight/model/primitives.h>
#include <intersight/model/texture.h>

namespace intersight {

class Renderer {
public:
  Renderer();

  template <typename T>
  void render_mesh(const Mesh3d<T> &, const Camera<T> &, Texture2d<T> &) const;

private:
  template <typename T>
  void draw_line_(Texture2d<T> &, const Vector2d<T> &,
                  const Vector2d<T> &) const;
};

} // namespace intersight

#endif // !INTERSIGHT_RENDERER_RENDERER_H_
