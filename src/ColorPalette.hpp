#ifndef COLORPALETTE_H
#define COLORPALETTE_H

#include "RGB.hpp"

#include <array>

RGB g_color_cursor;

class ColorPalette
{
private:
  std::array<RGB, 9> m_color_palette;  
  short m_position {0};
  
public:

  RGB& operator[](unsigned t_index) noexcept;
}

#endif
