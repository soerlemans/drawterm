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
  int pair_pos {InputPrompt_LL("Insert Color Pair ", 0, COLOR_PAIRS)};
    
  int color_id_fg = InputPrompt_ULL("Insert color ID FG ", 0, COLORS);
  int color_id_bg = InputPrompt_ULL("Insert color ID BG ", 0, COLORS);

  init_pair(pair_pos, color_id_fg, color_id_bg);
}

void ChangeColor()
{
  int color_id = InputPrompt_ULL("Insert color ID ", 0, COLORS);
  
  int color_r = InputPrompt_ULL("Insert R ", 0, 999);
  int color_g = InputPrompt_ULL("Insert G ", 0, 999);
  int color_b = InputPrompt_ULL("Insert B ", 0, 999);
  
  init_color(color_id, color_r, color_g, color_b);
}

void ChangeCharacter()
{
  auto str {InputPrompt_Str("Insert character from keyboard:", 1)};

  SetCharacter(str.front());
}

void ChangePair_Pos()
{
  int pair_pos {InputPrompt_ULL("Insert ", 0, COLOR_PAIRS)};

  SetPair_Pos(pair_pos);
}

//helper function for ChangeVideoLength()
void divide_length(double& t_cur_length, std::size_t& t_max_length_formatted)
{
  t_max_length_formatted /= 60;
  t_cur_length /=60;
}

//helper function for formatting the max and current length
char FormatLength(double& t_cur_length, std::size_t& t_max_length_formatted) 
{
  char for_char {InputPrompt_Char("Insert format f(rames),s(econds),m(inutes),h(ours):", "fsmh")};
  
  switch(for_char)
    {
    case 'h':
      divide_length(t_cur_length, t_max_length_formatted);
      [[fallthrough]];
      
    case 'm':
      divide_length(t_cur_length, t_max_length_formatted);
      [[fallthrough]];
      
    case 's':
      divide_length(t_cur_length, t_max_length_formatted);
      break;

    case 'f':
      break;

    default:
      throw LogicExcept("unrecognised format for FormatLength() ");
      break;
    }
  return for_char;
}

void ChangeVideoLength()
{
  double cur_length{GetVideoLength()};

  static constexpr std::size_t max_length_in_frame {5184000};//amount of frames in 24 hours
  std::size_t max_length_formatted {max_length_in_frame};    //the max formatted length
  
  char for_char {FormatLength(cur_length, max_length_formatted)};
  
  std::stringstream ss;
  ss << "Cur length=" << cur_length << for_char << ". Insert length 0-" << max_length_formatted << for_char << ":";
  
  auto new_length{InputPrompt_LL(ss.str(), std::log(max_length_in_frame)+1, 0, max_length_in_frame)};
  SetVideoLength(new_length*max_length_in_frame/max_length_formatted);
}

//TODO decide on a good max canvas size
void ChangeCanvasSize()
{ //set the canvas size
    int width  {InputPrompt_LL("Insert width ", 1, 1000)};
    int height {InputPrompt_LL("Insert height ", 1, 1000)};

    Setwh(width, height);
}

void ScreenHandle(int t_keypress)
{
  static bool sticky_enter {false};
  
    switch(t_keypress)
    {
    case 'v':
      CreatePair();
      break;
      
    case 'c':
      ChangeColor();
      break;

    case 'x':
      ChangeCharacter();
      break;
	
    case 'z':
      ChangePair_Pos();
      break;

    case 's':
      ChangeVideoLength();
      break;
      
    case 'a':
      ChangeCanvasSize();
      break;

    case ',':
      PreviousFrame(1);
      break;

    case '.':
      NextFrame(1);
      break;

    case 'i':
      sticky_enter = !sticky_enter;
      break;

      
    case 10: //10 is the Return
      SetCurrentFramePoint();
      break;
    }

    if(sticky_enter)
      SetCurrentFramePoint();
			       
}
