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

//initialize ncurses and make the program good to go
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
  
  init_color(1, 0, 200, 0);     //bg
  init_color(2, 999, 999, 999); //fg
  init_pair(1, 2, 1);
}

void Loop()
{
  CursorAttributes attributes;
  Video video;
  
  video.SetVideoLength(1);
  video.Setwh(1, 1);

  for(int keypress {0}; keypress != ERR && keypress != 'q'; keypress = getch())
    {
      MovementHandle(keypress);
      ScreenHandle(keypress, video, attributes);

      auto[old_x, old_y] = GetCurxy();

      DrawPromptLine();
      DrawPrompt();
      DrawPromptBrush(attributes);

      auto[w, h, l] = video.Getwhl();
      DrawDimensions(old_x,  w, old_y, h, video.GetVideo_Pos(), l);

      video.DrawCurrentFrame(GetMaxx(), GetMaxy());
      Move(old_x, old_y);

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
