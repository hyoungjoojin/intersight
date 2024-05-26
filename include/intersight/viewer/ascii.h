#ifndef INTERSIGHT_VIEWER_ASCII_H_
#define INTERSIGHT_VIEWER_ASCII_H_

#include <intersight/model/texture.h>

namespace intersight {

class AsciiViewer {
public:
  AsciiViewer();

  template <typename T> void view(const Texture2d<T> &) const;
  template <typename T> static char get_character(const T);

private:
  inline static const std::string ASCII_RENDERING_CHARACTERS_ =
      " .:,'-^*+?!|=0#X%WM@";
};

} // namespace intersight

#endif // !INTERSIGHT_VIEWER_ASCII_H_
