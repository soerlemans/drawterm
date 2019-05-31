#include "NcursesOptions.hpp"

void echo_on()
{
    if(echo() == ERR) throw RT_Error{"echo option failed to initialize"};
}

void echo_off()
{
    if(noecho() == ERR) throw RT_Error{"noecho option failed to initialize"};
}

void cbreak_on()
{
    if(cbreak() == ERR) throw RT_Error{"cbreak option failed to initialize"};
}

void cbreak_off()
{
    if(nocbreak() == ERR) throw RT_Error{"nocbreak option failed to initialize"};
}

void keypad_on()
{
    if(keypad(stdscr, TRUE) == ERR) throw RT_Error{"keypad failed to turn on"};
}

void keypad_off()
{
    if(keypad(stdscr, FALSE) == ERR) throw RT_Error{"keypad failed to turn off"};
}

//maybe if this one fails make it run in black and white?
void color_on(){

    if(has_colors()){

      if(!can_change_color())
	 throw RT_Error{"terminal doesnt support changing of colors"};
      
      if(start_color() == ERR)
	throw RT_Error{"ncurses colors failed to initialize"};

    }else
        throw RT_Error{"terminal doesnt support ncurses color"};
}
