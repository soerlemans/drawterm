#include "MovementHandle.hpp"

void MovementHandle(int t_keypress)
{
    switch(t_keypress)
    {
    case 'q':
        return;

    case 'h':
    case   2:
        MoveLeft(1);
        break;

    case 'j':
    case  14:
        MoveDown(1);
        break;

    case 'k':
    case  16:
        MoveUp(1);
        break;

    case 'l':
    case   6:
        MoveRight(1);
        break;

    case 260: //arrow left
        MoveLeft(15);
        break;

    case 259: //arrow up
        MoveUp(15);
        break;

    case 258: //arrow down
        MoveDown(15);
        break;

    case 261: //arrow right
        MoveRight(15);
        break;

    default:
        break;
    }
}
