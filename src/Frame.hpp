#ifndef FRAME_H
#define FRAME_H

#include "RGB.hpp"

#include <iostream>
#include <tuple>

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
  //GetSize doesnt fail if init 1 plus
  Matrix<Character> m_matrix {1};

public:  
  void SetPoint(std::size_t t_x, std::size_t t_y, const Character& t_color) noexcept;

  void Setwh(std::size_t t_w, std::size_t t_h);
  
  std::size_t Getw() const noexcept;
  std::size_t Geth() const noexcept;
  std::tuple<std::size_t,std::size_t> Getwh() const noexcept;
  
  std::vector<Character>& operator[](unsigned t_index);
  
  //draw the frame to the screen
  void DrawFrame(int t_screen_w, int t_screen_h, int t_offset_x = 0, int t_offset_y = 0);
};

#endif // FRAME_H

