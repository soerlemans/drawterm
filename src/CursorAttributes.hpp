#ifndef CURSORATTRIBUTES_H
#define CURSORATTRIBUTES_H

#include "Cursor.hpp"

class CursorAttributes
{
private:
  short m_pair_pos {1};
  char  m_brush_char {'X'};

public:
  bool  SetPair_Pos(short t_pair_pos) noexcept;
  short GetPair_Pos() const noexcept;
  
  void SetBrush(char t_brush_char) noexcept;
  char GetBrush() const noexcept;
  
};

#endif 
