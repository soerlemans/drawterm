#include "Offset.hpp"

void Offset::MoveLeft() noexcept
{
  if(GetCurx() == 0 && m_offset_x != 0)
    m_offset_x--;
}

void Offset::MoveDown() noexcept
{
  if(GetCury() == GetMaxy()-1)
    m_offset_y++;
}

void Offset::MoveUp() noexcept
{
  if(GetCury() == 0 && m_offset_y != 0)
    m_offset_y--;
}

void Offset::MoveRight() noexcept
{
  if(GetCurx() == GetMaxx()-1)
    m_offset_x++;
}

std::size_t Offset::GetOffsetx() const 
{
  return m_offset_x;
}

std::size_t Offset::GetOffsety() const 
{
  return m_offset_y;
}
