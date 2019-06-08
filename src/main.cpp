#include "MovementHandle.hpp"
#include "ScreenHandle.hpp"

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
    //update the file that takes care of the cursor
    Update();
}

void Loop()
{
    for(int keypress {0}; keypress != ERR && keypress != 'q'; keypress = getch())
    {
      MovementHandle(keypress);
      ScreenHandle(keypress);

      auto[old_x, old_y] = GetCurxy();

      DrawPromptLine();
      DrawPrompt();
      DrawPromptBrush();
      
      Move(stdscr, old_x, old_y);
      
      //      printw("%d", keypress);
      wrefresh(stdscr);
    }
}

#ifndef WINDOWS

//This is an animation program
//that makes animations with ANSI Escape codes
int main()
{
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
}

#else

//remove this later cause Init() covers this
int main()
{
  // if it is windows than quite for now
  std::cerr << "Windows does not support ANSI Escape codes.\n" << "You will have to wait for the windows terminal implementation" << std::endl;
  return 2;
}

#endif //WINDOWS
