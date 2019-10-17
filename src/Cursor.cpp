#include "Cursor.hpp"

/*getmax(y)|(x) returns the screen height or width
  cause we only use stdscr so the getbeg(y)|(x) always
  returns 0 no matter what (atleast in most instances)
*/
namespace{
  short g_pair_pos {1};
  char  g_character {' '};
}

int GetCurx() noexcept
{
  return getcurx(stdscr);
}

int GetCury() noexcept
{
  return getcury(stdscr);
}

auto GetCurxy() noexcept ->std::tuple<int, int>
{
  return {GetCurx(), GetCury()};
}

int GetMaxx() noexcept
{
  return getmaxx(stdscr);
}

int GetMaxy() noexcept
{
    return getmaxy(stdscr)-2;
}

auto GetMaxxy() noexcept ->std::tuple<int, int>
{
  return {getmaxx(stdscr), getmaxy(stdscr)-2};
}

int GetPrompty() noexcept
{
  return getmaxy(stdscr)-1;
}

int Boundsx(int t_cursor_x) noexcept
{
  const auto maxx {GetMaxx()};
  
    if(t_cursor_x < 0) t_cursor_x = 0;
    else if(t_cursor_x >= maxx) t_cursor_x = maxx-1;

    return t_cursor_x;
}

int Boundsy(int t_cursor_y) noexcept
{
  const auto maxy {GetMaxy()};

  if(t_cursor_y < 0) t_cursor_y = 0;
  else if(t_cursor_y >= maxy) t_cursor_y = maxy-1;
  
  return t_cursor_y;
}

bool SetPair_Pos(short t_pair_pos) noexcept
{
  if(t_pair_pos > int{COLOR_PAIRS - 1} || t_pair_pos < 0)
    return false;
  
  g_pair_pos = t_pair_pos;

  return true;
}

short GetPair_Pos() noexcept
{
  return g_pair_pos;
}

void SetCharacter(char t_character) noexcept
{
  g_character = t_character;
}

char GetCharacter() noexcept
{
  return g_character;
}

void Movex(int t_cursor_x) noexcept
{
  wmove(stdscr, GetCury(), Boundsx(t_cursor_x));
}

void Movey(int t_cursor_y) noexcept
{
  wmove(stdscr, Boundsy(t_cursor_y), GetCurx());
}

void Move(int t_cursor_x, int t_cursor_y) noexcept
{
  wmove(stdscr, Boundsy(t_cursor_y), Boundsx(t_cursor_x));
}

void MoveLeft(int t_amount) noexcept
{
  Movex(GetCurx()-t_amount);
}

void MoveRight(int t_amount) noexcept
{
    Movex(GetCurx()+t_amount);
}

void MoveUp(int t_amount) noexcept
{
    Movey(GetCury()-t_amount);
}

void MoveDown(int t_amount) noexcept
{
    Movey(GetCury()+t_amount);
}

void MovePrompt(int t_cursor_x) noexcept
//goes to the prompt area what is normally out of bounds
{
  wmove(stdscr, GetMaxy()+1, t_cursor_x);
}

//add a test to test if it is under 0
void MoveBrush(int t_cursor_x) noexcept
//goes from right to left
{
  wmove(stdscr, GetMaxy()+1, GetMaxx()-(++t_cursor_x));
}
  
void MovePromptLine()
//goes one place up the prompt are to draw the line normally out of bounds
{
  wmove(stdscr, GetMaxy(), 0);
}

