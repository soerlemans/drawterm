#include "Cursor.hpp"

int Cursor::m_max_x {getmaxx(stdscr)};
int Cursor::m_max_y {getmaxy(stdscr)-2};

int Cursor::m_cursor_x {getcurx(stdscr)};
int Cursor::m_cursor_y {getcury(stdscr)};

unsigned Cursor::m_palette_pos {0};

void Cursor::Update() noexcept
{
    m_max_x = getmaxx(stdscr);
    m_max_y = getmaxy(stdscr)-2;

    m_cursor_x = getcurx(stdscr);
    m_cursor_y = getcury(stdscr);
}

int Cursor::GetCurx() noexcept
{
    return m_cursor_x;
}

int Cursor::GetCury() noexcept
{
    return m_cursor_y;
}

auto Cursor::GetCurxy() noexcept ->std::tuple<int, int>
{
    return std::tuple<int, int>{m_cursor_x, m_cursor_y};
}

int Cursor::GetMaxx() noexcept
{
    return m_max_x;
}

int Cursor::GetMaxy() noexcept
{
    return m_max_y;
}

auto Cursor::GetMaxxy() noexcept ->std::tuple<int, int>
{
    return std::tuple<int, int>{m_max_x, m_max_y};
}

int Cursor::GetPrompty() noexcept
{
    return m_max_y+1;
}

void Cursor::SetPalette_Pos(unsigned t_palette_pos) noexcept
{
  m_palette_pos = t_palette_pos;
}

unsigned Cursor::GetPalette_Pos() noexcept
{
  return m_palette_pos;
}

int Cursor::Boundsx(int t_cursor_x) noexcept
{
    if(t_cursor_x < 0) t_cursor_x = 0;
    else if(t_cursor_x >= m_max_x) t_cursor_x = m_max_x-1;

    return t_cursor_x;
}

int Cursor::Boundsy(int t_cursor_y) noexcept
{
    if(t_cursor_y < 0) t_cursor_y = 0;
    else if(t_cursor_y >= m_max_y) t_cursor_y = m_max_y-1;

    return t_cursor_y;
}

void Cursor::Movex(WINDOW* t_win, int t_cursor_x) noexcept
{
    m_cursor_x = Boundsx(t_cursor_x);
    wmove(t_win, m_cursor_y, m_cursor_x);
    wrefresh(t_win);
}

void Cursor::Movey(WINDOW* t_win, int t_cursor_y) noexcept
{
    m_cursor_y = Boundsy(t_cursor_y);
    wmove(t_win, m_cursor_y, m_cursor_x);
    wrefresh(t_win);
}

void Cursor::Move(WINDOW* t_win, int t_cursor_x, int t_cursor_y) noexcept
{
    m_cursor_x = Boundsx(t_cursor_x);
    m_cursor_y = Boundsy(t_cursor_y);

    wmove(t_win, m_cursor_y, m_cursor_x);
    wrefresh(t_win);
}

void Cursor::MoveLeft(WINDOW* t_win, int t_amount) noexcept
{
    Movex(t_win, m_cursor_x-t_amount);
}

void Cursor::MoveRight(WINDOW* t_win, int t_amount) noexcept
{
    Movex(t_win, m_cursor_x+t_amount);
}

void Cursor::MoveUp(WINDOW* t_win, int t_amount) noexcept
{
    Movey(t_win, m_cursor_y-t_amount);
}

void Cursor::MoveDown(WINDOW* t_win, int t_amount) noexcept
{
    Movey(t_win, m_cursor_y+t_amount);
}


//goes to the prompt area what is normally out of bounds
void Cursor::MovePrompt(WINDOW* t_win, int t_cursor_x) noexcept
{
    m_cursor_x = t_cursor_x;
    m_cursor_y = m_max_y+1;

    wmove(t_win, m_max_y+1, t_cursor_x);
    wrefresh(t_win);
}

//goes one place up the prompt are to draw the line normally out of bounds
void Cursor::MovePromptLine(WINDOW* t_win)
{
    m_cursor_x = 0;
    m_cursor_y = m_max_y;

    wmove(t_win, m_max_y, m_cursor_x);
    wrefresh(t_win);
}

Cursor g_cursor;
