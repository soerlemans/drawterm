#include "Prompt.hpp"

void ClearPrompt(WINDOW* t_win) noexcept
{
    auto[old_x, old_y] = GetCurxy();

    MovePrompt(t_win, 0);
    clrtoeol();

    Move(t_win, old_x, old_y);
}

//draws the basic prompt string
void DrawPrompt(WINDOW* t_win, const std::string& t_text) noexcept
{
    ClearPrompt(t_win);

    MovePrompt(t_win, 0);
    printw("%s", t_text.c_str());
}

void DrawPromptLine(WINDOW* t_win) noexcept
{
    MovePromptLine(t_win);
    whline(t_win, ACS_CKBOARD, GetMaxx());
}

void DrawPromptBrush(WINDOW* t_win) 
{
  MoveBrush(t_win, 0);
  try{
    attron(COLOR_PAIR(GetPair_Pos()));
    waddch(t_win, GetCharacter());
    attroff(COLOR_PAIR(GetPair_Pos()));
  }catch(InitExcept& catched)
    {
      catched += "DrawPromptBrush() ";
      throw catched;
    }
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

//Handle the delete if InputPrompt_Str finds one
int HandleDelete(WINDOW* t_win, int t_index, std::size_t t_textsize)
{
  t_index = (t_index-2 < 0) ? -1 : t_index-2; //index may not be smaller than 0 gets incrementend from -1 to 0
  if(t_index+1){               //the t_index isnt incremented yet
    wdelch(t_win);             //delete the character if it isnt 0
    
  }else{
    MovePrompt(t_win, t_textsize+1);
    wdelch(t_win);
    MovePrompt(t_win, t_textsize);
  }
  return t_index;
}

//add the option to press escape to leave the function without changing anything
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

	if(character == 263)                     //delete character
	    index = HandleDelete(t_win, index, t_text.size());
	else
	  input[index] = character;
      } 
    echo_off();
    
  }catch(InitExcept& catched){
    catched += " InputPrompt()";
    throw catched;
    }
  
  Move(t_win, old_x, old_y);

  return input;
}

char InputPrompt_Char(WINDOW* t_win, const std::string& t_text, const std::string& t_allowed_chars)
{
  std::string format;
  bool allowed{false};

  while(!allowed)
    {
      format = InputPrompt_Str(t_win, t_text, 1);
	
      for(const auto& character : t_allowed_chars)
	if(format.front() == character)
	  {
	    allowed = true;
	    break;
	  }
    }
  return format.front();
}

//using declarations for cleaning up the messy type declerations
using ll  = long long;
using ull = unsigned long long;

//converter function
//Type must always be numeric and Func a converting function lik std::stoi
template<typename Type, typename Func>
Type InputPrompt_Conv(WINDOW* t_win, const std::string& t_text, int t_input_lenght, Type t_min, Type t_max, Func t_function)
{
  std::string value_str;
  Type value {t_min-1};

  //skip if there is an alpha character in it
  bool skip {false};
  
  for(; value < t_min || value > t_max; skip = false)
    {
      try{
	value_str = InputPrompt_Str(t_win, t_text, t_input_lenght);
      }catch(InitExcept& catched){
	catched += " InputPrompt_Conv() ";
	throw catched;
      }
      if(value_str.front() == '\n') return 0;
	
      for(const auto character : value_str)
	{
	  if(!isdigit(character) && character != '\n')
	    skip = true;
	}
      
	if(!skip)
	  value = t_function(value_str, 0, 10);
    }
  return value;
}

ll InputPrompt_LL(WINDOW* t_win, const std::string& t_text, int t_input_lenght, ll t_min, ll t_max)
{
  //function pointer to std::stoll
  ll (*func)(const std::string&, std::size_t*, int) = std::stoll;
  return InputPrompt_Conv(t_win, t_text, t_input_lenght, t_min, t_max, func);
}

//make a InputPrompt_Long() for now i think raw copying it will be the best option
ull InputPrompt_ULL(WINDOW* t_win, const std::string& t_text, int t_input_lenght, ull t_min, ull t_max)
{
  //function pointer to std::stoull
  ull (*func)(const std::string&, std::size_t*, int) = std::stoull;
  return InputPrompt_Conv(t_win, t_text, t_input_lenght, t_min, t_max, func);
}

//this will give an error if it is used outside this file cause it cant template the types
template<typename T> 
std::string RangeToText(const T& t_min, const T& t_max)
{
  endwin();
  
  std::string text;
  text += std::to_string(t_min);
  text += "-";
  text += std::to_string(t_max);
  text += ":";

  return text;
}

//handles the most used use case
ll InputPrompt_LL(WINDOW* t_win, std::string t_text, ll t_min, ll t_max)
{
  int input_length {std::log(t_max)+1};

  RangeToText(t_min, t_max);
  
  return InputPrompt_LL(t_win, t_text, input_length, t_min, t_max);
}

ull InputPrompt_ULL(WINDOW* t_win, std::string t_text, ull t_min, ull t_max)
{
  int input_length {std::log(t_max)+1};

  RangeToText(t_min, t_max);
  
  return InputPrompt_ULL(t_win, t_text, input_length, t_min, t_max);
}
