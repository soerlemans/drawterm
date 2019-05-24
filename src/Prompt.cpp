#include "Prompt.hpp"

void ClearPrompt(WINDOW* t_win)
{
    auto[old_x, old_y] = g_cursor.GetCurxy();

    g_cursor.MovePrompt(t_win, 0);
    clrtoeol();

    g_cursor.Move(t_win, old_x, old_y);
}

void DrawPromptLine(WINDOW* t_win)
{
    auto[old_x, old_y] = g_cursor.GetCurxy();

    g_cursor.MovePromptLine(t_win);
    whline(t_win, ACS_CKBOARD, g_cursor.GetMaxx());
    g_cursor.Move(t_win, old_x, old_y);
}

//draws the basic prompt string
void DrawPrompt(WINDOW* t_win, const std::string& t_text)
{
    auto[old_x, old_y] = g_cursor.GetCurxy();

    ClearPrompt(t_win);

    g_cursor.MovePrompt(t_win, 0);
    printw("%s", t_text.c_str());
    g_cursor.Move(t_win, old_x, old_y);
}

void DrawPromptMessage(WINDOW* t_win, const std::string& t_text, int t_conformation)
{
    auto[old_x, old_y] = g_cursor.GetCurxy();

    ClearPrompt(t_win);

    g_cursor.MovePrompt(t_win);
    printw("%s", t_text.c_str());
    wrefresh(t_win);

    for(int character {'0'}; character != ERR && character != t_conformation; character = getch()){
        g_cursor.MovePrompt(t_win, t_text.size());
    }
    g_cursor.Move(t_win, old_x, old_y);
}

std::string InputPrompt_Str(WINDOW* t_win, const std::string& t_text, int t_input_length)
{
    auto[old_x, old_y] = g_cursor.GetCurxy();

    ClearPrompt(t_win);

    std::string input;
    char character {'0'};

    DrawPrompt(t_win, t_text);
    g_cursor.MovePrompt(t_win, t_text.size());
    
    try{

      echo_on();

    for(int index {0}; index < t_input_length && character != ERR && character != 10; index++)
      {
	character = getch();
	input += character;
      }
    
    echo_off();

    }catch(RT_Error catched){
        throw RT_Error(catched += " InputPrompt()");
    }

    g_cursor.Move(t_win, old_x, old_y);

    return input;
}

int InputPrompt_Int(WINDOW* t_win, const std::string& t_text, int input_lenght, int t_min, int t_max)
{
  std::string value_str;
  int value_int {t_min-1};

  //skip if there is an alpha character in it
  bool skip {false};
  
  for(; value_int < t_min || value_int > t_max; skip = false)
    {
      try{
	value_str = InputPrompt_Str(t_win, t_text, input_lenght);
      }catch(RT_Error catched){
	throw RT_Error(catched += " InputPrompt() + t_min, t_max");
      }
      
	for(const auto character : value_str)
	  {
	    if(!isdigit(character) && character != '\n')
	      skip = true;
	  }
	
	if(!skip)
	  value_int = std::stoi(value_str);
    }
  return value_int;
}
