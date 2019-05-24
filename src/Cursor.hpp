#ifndef CURSOR_H
#define CURSOR_H

#include "RGB.hpp"

#include <ncurses.h>
#include <tuple>
#include <iostream>

//only use this for cursor moving dont use the ncurses facilities
class Cursor
{
private:
  static int m_max_x, m_max_y, m_prompt_y;
  static int m_cursor_x, m_cursor_y;       //or else you can scroll out the box
  static unsigned m_palette_pos;
  
public:
  void Update() noexcept; //updates all the vals

  int GetCurx() noexcept;
  int GetCury() noexcept;
  std::tuple<int, int> GetCurxy() noexcept;

  int GetMaxx() noexcept;
  int GetMaxy() noexcept;
  std::tuple<int, int> GetMaxxy() noexcept;

  int GetPrompty() noexcept;

  void SetPalette_Pos(unsigned t_palette_pos) noexcept;
  unsigned GetPalette_Pos() noexcept;
 
  int Boundsx(int t_cursor_x) noexcept;
  int Boundsy(int t_cursor_y) noexcept;

  void Movex(WINDOW* t_win = stdscr, int t_cursor_x = 0) noexcept;
  void Movey(WINDOW* t_win = stdscr, int t_cursor_y = 0) noexcept;
  
  void Move(WINDOW* t_win = stdscr, int t_cursor_x = 0, int t_cursor_y = 0) noexcept;
  
  void MoveUp(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;
  void MoveDown(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;
  void MoveLeft(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;
  void MoveRight(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;
  
  void MovePrompt(WINDOW* t_win = stdscr, int t_cursor_x = 0) noexcept; //move to the prompt area
  void MovePromptLine(WINDOW* t_win = stdscr); //move to line above the prompt area

} extern g_cursor;
//do not use static for this that means that g_cursor will be ctor and dtor multiple times due
//to the variable being static to where it was included so it only allows for multiple definitions
//by avoiding name clashes of seperate variables with the same name by tying them down to their
//own file scope instead of referring to the same variable like extern would

#endif // CURSOR_H
