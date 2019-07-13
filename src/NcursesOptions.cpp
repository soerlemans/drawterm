#include "NcursesOptions.hpp"

void echo_on()
{
    if(echo() == ERR) throw InitExcept{"echo option failed to initialize"};
}

void echo_off()
{
    if(noecho() == ERR) throw InitExcept{"noecho option failed to initialize"};
}

void cbreak_on()
{
    if(cbreak() == ERR) throw InitExcept{"cbreak option failed to initialize"};
}

void cbreak_off()
{
    if(nocbreak() == ERR) throw InitExcept{"nocbreak option failed to initialize"};
}

void keypad_on()
{
    if(keypad(stdscr, TRUE) == ERR) throw InitExcept{"keypad failed to turn on"};
}

void keypad_off()
{
    if(keypad(stdscr, FALSE) == ERR) throw InitExcept{"keypad failed to turn off"};
}

//maybe if this one fails make it run in black and white?
void color_on(){

    if(has_colors()){

      if(!can_change_color())
	 throw InitExcept{"terminal doesnt support changing of colors"};
      
      if(start_color() == ERR)
	throw InitExcept{"ncurses colors failed to initialize"};

    }else
        throw InitExcept{"terminal doesnt support ncurses color"};
}
