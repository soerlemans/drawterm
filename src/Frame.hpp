#ifndef FRAME_H
#define FRAME_H

#include "Cursor.hpp"
#include "NcursesOptions.hpp"
#include "LogicExcept.hpp"
#include "InitExcept.hpp"

#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

template<typename Type>
using Matrix = std::vector<std::vector<Type>>;

//char represents the character and the n FG, BG
//the character has to be filtered to be on the char character sheet
//cause DEL = 263 > 256 what is the max value of a char creates undefined behavior

//char must be a printable char and the int is the color pair that is set
using Character = std::pair<char, int>;

//1 screenstate/frame from the animation
class Frame
{
private:
  Matrix<Character> m_matrix;//it will at least always be 1x1
  
public:
  Frame();
  
  void SetPoint(const std::size_t t_x, const std::size_t t_y, const Character& t_color) noexcept;
  void SetPoint(const std::size_t t_x, const std::size_t t_y, char t_character, int t_color_pair) noexcept;

  void Setwh(std::size_t t_w = 1, std::size_t t_h = 1);
  auto Getwh() ->std::tuple<std::size_t, std::size_t>;
  
  std::vector<Character>& operator[](unsigned t_index);
  void DrawLine(const std::vector<Character>& t_line, std::size_t t_screen_w, std::size_t t_offset_x);
  void DrawFrame(std::size_t t_screen_w, std::size_t t_screen_h, std::size_t t_offset_x, std::size_t t_offset_y);

};

#endif // FRAME_H
