#include "ScreenHandle.hpp"

std::string GetCOLOR_PAIRSRange()
{
  std::stringstream sstream;

  sstream << "0-";
  sstream << COLOR_PAIRS;
  sstream << ":";
    
  return sstream.str();
}

std::string GetCOLORSRange()
{
  std::stringstream sstream;

  sstream << "0-";
  sstream << COLORS;
  sstream << ":";

  return sstream.str();
}

//handles all the keybinds that change the state of the screen or change a certain aspect of it
//like redefining color pairs or changing the specification of a color or changing the cursor color

void CreatePair()
{
  int pair_pos {InputPrompt_Int(stdscr, "Insert Color Pair " + GetCOLOR_PAIRSRange(), std::log10(COLOR_PAIRS)+1, 0, COLOR_PAIRS)};
    
  int color_id_fg = InputPrompt_Int(stdscr, "Insert color ID FG " + GetCOLORSRange(), std::log10(COLORS), 0, COLORS);
  int color_id_bg = InputPrompt_Int(stdscr, "Insert color ID BG " + GetCOLORSRange(), std::log10(COLORS), 0, COLORS);

  init_pair(pair_pos, color_id_fg, color_id_bg);
}

void ChangeColor()
{
  int color_id = InputPrompt_Int(stdscr, "Insert color ID " + GetCOLORSRange(), std::log10(COLORS), 0, COLORS);
  
  int color_r = InputPrompt_Int(stdscr, "Insert R 0-999:", 3, 0, 999);
  int color_g = InputPrompt_Int(stdscr, "Insert G 0-999:", 3, 0, 999);
  int color_b = InputPrompt_Int(stdscr, "Insert B 0-999:", 3, 0, 999);
  
  init_color(color_id, color_r, color_g, color_b);
}

void ChangeCharacter()
{
  auto str = InputPrompt_Str(stdscr, "Insert character from keyboard:", 1);

  SetCharacter(str.front());
}

void ChangePair_Pos()
{
  int pair_pos {InputPrompt_Int(stdscr, "Insert " + GetCOLOR_PAIRSRange(), std::log10(COLOR_PAIRS)+1, 0, COLOR_PAIRS)};

  SetPair_Pos(pair_pos);
}

void ChangeCanvasSize()
{ //set the canvas size

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
