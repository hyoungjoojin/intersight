#include <intersight/model/primitives.h>
#include <intersight/renderer/renderer.h>

using namespace intersight;

Renderer::Renderer() {}

template <typename T>
void Renderer::render_mesh(const Mesh3d<T> &mesh, const Camera<T> &camera,
                           Texture2d<T> &texture) const {
  const auto &vertices = mesh.get_vertices();

  for (const auto &face : mesh.get_faces()) {
    Vector3d<T> point_1 = vertices[face.get_vertices()[0]];
    Vector3d<T> point_2 = vertices[face.get_vertices()[1]];
    Vector3d<T> point_3 = vertices[face.get_vertices()[2]];

    Vector2d<T> projected_point_1 = Vector2d(point_1.get_x(), point_1.get_y());
    Vector2d<T> projected_point_2 = Vector2d(point_2.get_x(), point_2.get_y());
    Vector2d<T> projected_point_3 = Vector2d(point_3.get_x(), point_3.get_y());

    draw_line_(texture, projected_point_1, projected_point_2);
    draw_line_(texture, projected_point_2, projected_point_3);
    draw_line_(texture, projected_point_1, projected_point_3);
  }
}

template <typename T>
void Renderer::draw_line_(Texture2d<T> &texture, const Vector2d<T> &u,
                          const Vector2d<T> &v) const {
  for (float t = 0; t < 1; t += 0.05) {
    texture.add_pixel(u + v * t);
  }
}

template void Renderer::render_mesh<float>(const Mesh3d<float> &,
                                           const Camera<float> &,
                                           Texture2d<float> &) const;
template void Renderer::render_mesh<double>(const Mesh3d<double> &,
                                            const Camera<double> &,
                                            Texture2d<double> &) const;
template void
Renderer::render_mesh<long double>(const Mesh3d<long double> &,
                                   const Camera<long double> &,
                                   Texture2d<long double> &) const;
