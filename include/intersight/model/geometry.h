#ifndef INTERSIGHT_MODEL_GEOMETRY_H_
#define INTERSIGHT_MODEL_GEOMETRY_H_

#include <array>
#include <istream>
namespace intersight {

class Triangle3d {
public:
  Triangle3d();

  const std::array<unsigned int, 3> &get_vertices() const;

  friend std::istream &operator>>(std::istream &, Triangle3d &);

private:
  std::array<unsigned int, 3> vertices_;

  static void parse_vertex_(const std::string &, unsigned int &);
};

} // namespace intersight

#endif // !INTERSIGHT_MODEL_GEOMETRY_H_
