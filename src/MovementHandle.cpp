#include "MovementHandle.hpp"

void MovementHandle(int t_keypress)
{
    switch(t_keypress)
    {
    case 'q':
        return;

    case 'h':
    case   2:
        g_cursor.MoveLeft(stdscr, 1);
        break;

    case 'j':
    case  14:
        g_cursor.MoveDown(stdscr, 1);
        break;

    case 'k':
    case  16:
        g_cursor.MoveUp(stdscr, 1);
        break;

    case 'l':
    case   6:
        g_cursor.MoveRight(stdscr, 1);
        break;

    case 260:
        g_cursor.MoveLeft(stdscr, 15);
        break;

    case 259:
        g_cursor.MoveUp(stdscr, 15);
        break;

    case 258:
        g_cursor.MoveDown(stdscr, 15);
        break;

    case 261:
        g_cursor.MoveRight(stdscr, 15);
        break;

    default:
        break;
    }
}
