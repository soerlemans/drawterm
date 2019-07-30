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
    }catch(InitExcept& catched){
      catched += " Init()";
      throw catched;
    }
    //update the file that takes care of the cursor
    Update();

    //Set the standard video dimensions
    SetVideoLength(1);
    Setwh(1, 1);
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
      
      wrefresh(stdscr);
    }
}

#ifndef WINDOWS

//This is an animation program
//that makes animations with ANSI Escape codes
int main()
{
  try{
    try{
      Init();
    }catch(InitExcept& except)
      {
	endwin();
	std::cerr << "something failed to initialize\n"
		  << "exception: " << except.what()
		  << "\nterminating..." << std::endl;
	return 2;
      }

    Loop();
  }catch(const Except& except)
    {
      endwin();
      std::cerr << "an exception slipped past to main()\n"
		<< "exception:" << except.what()
		<< "\nterminating..." << std::endl;
      return 3;
    }

  endwin();
  return 0;
}

#else

//remove this later cause Init() covers this
int main()
{
  // if it is windows than quite for now
  std::cerr << "Windows does not support ANSI Escape codes.\n" << "You will have to wait for the windows terminal implementation" << std::endl;
  return 1;
}

#endif //WINDOWS
