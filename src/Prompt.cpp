#include "Prompt.hpp"

void ClearPrompt(WINDOW* t_win)
{
    auto[old_x, old_y] = GetCurxy();

    MovePrompt(t_win, 0);
    clrtoeol();

    Move(t_win, old_x, old_y);
}

//draws the basic prompt string
void DrawPrompt(WINDOW* t_win, const std::string& t_text)
{
    ClearPrompt(t_win);

    MovePrompt(t_win, 0);
    printw("%s", t_text.c_str());
}

void DrawPromptLine(WINDOW* t_win)
{
    MovePromptLine(t_win);
    whline(t_win, ACS_CKBOARD, GetMaxx());
}

void DrawPromptBrush(WINDOW* t_win)
{
  MoveBrush(t_win, 0);

  attron(COLOR_PAIR(GetPair_Pos()));
  waddch(t_win, GetCharacter());
  attroff(COLOR_PAIR(GetPair_Pos()));
  
  MoveBrush(t_win, 1);
  
  //for if the fg an bg colors are the same
  waddch(t_win, GetCharacter());
}

//these do need to return back to their first position cause they can be called any where

void DrawPromptMessage(WINDOW* t_win, const std::string& t_text, int t_conformation)
{
  auto[old_x, old_y] = GetCurxy();

  ClearPrompt(t_win);

  MovePrompt(t_win);
  printw("%s", t_text.c_str());

  for(int character {'0'}; character != ERR && character != t_conformation; character = wgetch(stdscr)){
    MovePrompt(t_win, t_text.size());
  }
  
  Move(t_win, old_x, old_y);
  
}

std::string InputPrompt_Str(WINDOW* t_win, const std::string& t_text, int t_input_length)
{
  auto[old_x, old_y] = GetCurxy();

  ClearPrompt(t_win);
  
  std::string input(t_input_length, '0'); //uniform initialization gives warning and is error prone in this case
  int character {'0'};                    // the char is to small to register the delete character 263

  DrawPrompt(t_win, t_text);
  MovePrompt(t_win, t_text.size());
  
  try{
    echo_on();

    for(int index {0}; index < t_input_length && character != ERR && character != 10; index++)
      {
	character = wgetch(t_win);

	if(character == 263)
	  {
	    index = (index-2 < 0) ? 0 : index-2; //index may not be smaller than0
	    if(index) wdelch(t_win);             //delete the character if it isnt 0
	    else MovePrompt(t_win, t_text.size());
	  }
	else
	  input[index] = character;
      } 
    echo_off();
    
  }catch(RT_Error catched){
    throw RT_Error(catched += " InputPrompt()");
    }
  
  Move(t_win, old_x, old_y);

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
      if(value_str.front() == '\n') return 0;
	
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

/*
int InputPrompt_Int(WINDOW* t_win, const std::string& t_text, int t_min, int t_max)
{
  return InputPrompt_Int(t_win, t_text, std::log(t_max)+1, t_min, t_max);
}
*/
