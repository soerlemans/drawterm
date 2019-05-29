#include "MovementHandle.hpp"
#include "ScreenHandle.hpp"

#include <iostream>
#include <stdexcept>

#ifdef __linux__
#include <unistd.h>
#endif

#ifdef _WIN32
#define WINDOWS
#elif _WIN64
#define WINDOWS
#endif // _WIN32

void Init()
{
    initscr();

    try{

    color_on();
    cbreak_on();
    echo_off();
    keypad_on();

    //tell them where it came from
    }catch(RT_Error catched){
        throw RT_Error{catched += " Init()"};
    }
}

void Loop()
{
    //update the wrapper class for the cursor
    g_cursor.Update();

    //give these their own seperate functions
    for(int keypress {0}; keypress != ERR && keypress != 'q'; keypress = getch())
    {
        DrawPromptLine(stdscr);
        DrawPrompt(stdscr);
	//	DrawPromptPalette(stdscr);

        MovementHandle(keypress);
        ScreenHandle(keypress);
        printw("%d", keypress);

        wrefresh(stdscr);
    }
}

//This is an animation program
//that makes animations with ANSI Escape codes
int main()
{
    #ifndef WINDOWS

    try{
        Init();
    }catch(RT_Error except)
    {
        std::cerr << "exception: " << except.what() << "\nterminating..." << std::endl;
        return 1;
    }

    Loop();

    endwin();
    return 0;

    #else

    // if it is windows than quite for now
    std::cerr << "Windows does not support ANSI Escape codes.\n"
              << "You will have to wait for the windows terminal implementation" << std::endl;
    return 2;

    #endif //WINDOWS
}
