#include "CursorAttributes.hpp"

bool CursorAttributes::SetPair_Pos(short t_pair_pos) noexcept
{
  if(t_pair_pos > int{COLOR_PAIRS - 1} || t_pair_pos < 0)
    return false;

  m_pair_pos = t_pair_pos;

  return true;
}

short CursorAttributes::GetPair_Pos() const noexcept
{
  return m_pair_pos;
}

void CursorAttributes::SetBrush(char t_brush_char) noexcept
{
  m_brush_char = t_brush_char;
}

char CursorAttributes::GetBrush() const noexcept
{
  return m_brush_char;
}

