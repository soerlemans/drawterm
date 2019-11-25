#ifndef OFFSET_H
#define OFFSET_H

#include "Cursor.hpp"

class Offset
{
private:
  std::size_t m_offset_x {0}, m_offset_y{0};

public:
  void MoveLeft()  noexcept;
  void MoveDown()  noexcept;
  void MoveUp()    noexcept;
  void MoveRight() noexcept;

  std::size_t GetOffsetx() const;
  std::size_t GetOffsety() const;
};

#endif
