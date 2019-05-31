#include "ScreenHandle.hpp"

//handles all the keybinds that change the state of the screen

void ChangeColor()
{
  short color_id = InputPrompt_Int(stdscr, "Insert color ID:", std::log(COLORS)+1, 0, COLORS);
  
  short color_r = InputPrompt_Int(stdscr, "Insert R:", 3, 0, 999);
  short color_g = InputPrompt_Int(stdscr, "Insert G:", 3, 0, 999);
  short color_b = InputPrompt_Int(stdscr, "Insert B:", 3, 0, 999);
  
  init_color(color_id, color_r, color_g, color_b);
}

void ChangeCharacter()
{
  auto str = InputPrompt_Str(stdscr, "Insert character:", 1);

  //  no fucking clue why this gives an error TODO
  //  g_character = str.front()
}

void ChangePair_Pos()
{
  std::stringstream sstream;

  sstream << "Insert number in between 0-";
  sstream << COLORS;
  sstream << ": PRESS ENTER"; 

  DrawPromptMessage(stdscr, sstream.str());

  //very unlikely for terminals to support over 256 colors
  auto pair_pos {InputPrompt_Int(stdscr, "Insert:", std::log(COLORS)+1, 0, COLORS)};
  g_cursor.SetPair_Pos(pair_pos);
  
}

void ScreenHandle(int t_keypress)
{
    switch(t_keypress)
    {
    case 'c':
      ChangeColor();
      break;

    case 'x':
      ChangeCharacter();
      break;
	
    case 'z':
      ChangePair_Pos();
      break;
    }
    
    
}
