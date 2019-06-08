#include "MovementHandle.hpp"

void MovementHandle(int t_keypress)
{
    switch(t_keypress)
    {
    case 'q':
        return;

    case 'h':
    case   2:
        MoveLeft(stdscr, 1);
        break;

    case 'j':
    case  14:
        MoveDown(stdscr, 1);
        break;

    case 'k':
    case  16:
        MoveUp(stdscr, 1);
        break;

    case 'l':
    case   6:
        MoveRight(stdscr, 1);
        break;

    case 260:
        MoveLeft(stdscr, 15);
        break;

    case 259:
        MoveUp(stdscr, 15);
        break;

    case 258:
        MoveDown(stdscr, 15);
        break;

    case 261:
        MoveRight(stdscr, 15);
        break;

    default:
        break;
    }
}
