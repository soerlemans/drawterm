#include "Frame.hpp"

//FRAME

void Frame::SetPoint(std::size_t t_x, std::size_t t_y, const Character& t_color) noexcept
{
  m_matrix[t_x][t_y] = t_color;
}

void Frame::Setwh(std::size_t t_w, std::size_t t_h)
{
  if(!t_w)
    t_w = 1;

  if(!t_h)
    t_h = 1;
  
  m_matrix[0].resize(t_w);
  m_matrix.resize(t_h);
}

std::size_t Frame::Getw() const noexcept
{
  return m_matrix.at(0).size();
}

std::size_t Frame::Geth() const noexcept
{
  return m_matrix.size();
}

auto Frame::Getwh() const noexcept ->std::tuple<std::size_t, std::size_t>
{
  return {Getw(), Geth()};
}

std::vector<Character>& Frame::operator[](unsigned t_index)
{
    return m_matrix[t_index];
}

void Frame::DrawFrame(int t_screen_w, int t_screen_h, int t_offset_x, int t_offset_y)
{

}
