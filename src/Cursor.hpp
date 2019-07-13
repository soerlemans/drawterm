#ifndef CURSOR_H
#define CURSOR_H

#include <ncurses.h>
#include <tuple>

//only use this for cursor moving dont use the ncurses facilities
extern void Update() noexcept; //updates all the vals

extern int GetCurx() noexcept;
extern int GetCury() noexcept;
extern auto GetCurxy() noexcept ->std::tuple<int, int>;

extern int GetMaxx() noexcept;
extern int GetMaxy() noexcept;
extern auto GetMaxxy() noexcept ->std::tuple<int, int>;

extern int GetPrompty() noexcept;

extern bool  SetPair_Pos(short t_pair_pos) noexcept;
extern short GetPair_Pos() noexcept;

extern void SetCharacter(char t_character) noexcept;
extern char GetCharacter() noexcept;

extern int Boundsx(int t_cursor_x) noexcept;
extern int Boundsy(int t_cursor_y) noexcept;

extern void Movex(WINDOW* t_win = stdscr, int t_cursor_x = 0) noexcept;
extern void Movey(WINDOW* t_win = stdscr, int t_cursor_y = 0) noexcept;

extern void Move(WINDOW* t_win = stdscr, int t_cursor_x = 0, int t_cursor_y = 0) noexcept;

extern void MoveUp(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;
extern void MoveDown(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;
extern void MoveLeft(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;
extern void MoveRight(WINDOW* t_win = stdscr, int t_amount = 1) noexcept;

extern void MovePrompt(WINDOW* t_win = stdscr, int t_cursor_x = 0) noexcept; //move to the prompt area
extern void MoveBrush(WINDOW* t_win = stdscr, int t_cursor_x = 0) noexcept;

extern void MovePromptLine(WINDOW* t_win = stdscr); //move to line above the prompt area

#endif // CURSOR_H
