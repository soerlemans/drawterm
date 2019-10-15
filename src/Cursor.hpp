#ifndef CURSOR_H
#define CURSOR_H

#include <ncurses.h>
#include <tuple>

//only use this for cursor moving dont use the ncurses facilities
extern void Update() noexcept; //updates all the vals

extern int  GetCurx() noexcept;
extern int  GetCury() noexcept;
extern auto GetCurxy() noexcept ->std::tuple<int, int>;

extern int  GetMaxx() noexcept;
extern int  GetMaxy() noexcept;
extern auto GetMaxxy() noexcept ->std::tuple<int, int>;

extern int GetPrompty() noexcept;

extern bool  SetPair_Pos(short t_pair_pos) noexcept;
extern short GetPair_Pos() noexcept;

extern void SetCharacter(char t_character) noexcept;
extern char GetCharacter() noexcept;

extern int Boundsx(int t_cursor_x) noexcept;
extern int Boundsy(int t_cursor_y) noexcept;

extern void Movex(int t_cursor_x = 0) noexcept;
extern void Movey(int t_cursor_y = 0) noexcept;

extern void Move(int t_cursor_x = 0, int t_cursor_y = 0) noexcept;

extern void MoveUp(int t_amount = 1) noexcept;
extern void MoveDown(int t_amount = 1) noexcept;
extern void MoveLeft(int t_amount = 1) noexcept;
extern void MoveRight(int t_amount = 1) noexcept;

extern void MovePrompt(int t_cursor_x = 0) noexcept; //move to the prompt area
extern void MoveBrush(int t_cursor_x = 0) noexcept;

extern void MovePromptLine(); //move to line above the prompt area

#endif // CURSOR_H
