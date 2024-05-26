#ifndef INTERSIGHT_MODEL_TEXTURE_H_
#define INTERSIGHT_MODEL_TEXTURE_H_

#include <vector>
namespace intersight {

template <typename T> class Texture2d {
public:
  Texture2d();
  Texture2d(int, int);

  const std::vector<std::vector<T>> &get_pixels() const;

private:
  int width_;
  int height_;
  std::vector<std::vector<T>> pixels_;
};

} // namespace intersight

#endif // !INTERSIGHT_MODEL_TEXTURE_H_
