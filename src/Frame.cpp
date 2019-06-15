#include "Frame.hpp"

//FRAME

Frame::Frame()
{
  m_matrix.resize(1, std::vector<Character>(1, Character{'0', 0}));
}

void Frame::SetPoint(const std::size_t t_x, const std::size_t t_y, const Character& t_color) noexcept
{
  m_matrix[t_x][t_y] = t_color;
}

std::vector<Character>& Frame::operator[](unsigned t_index)
{
    return m_matrix[t_index];
}

void Frame::DrawFrame(int t_screen_w, int t_screen_h, int t_offset_x, int t_offset_y)
{

}
