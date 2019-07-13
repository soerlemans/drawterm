#ifndef NCURSESOPTIONS_H
#define NCURSESOPTIONS_H

#include "InitExcept.hpp"

#include <ncurses.h>
#include <stdexcept>

extern void echo_on();
extern void echo_off();

extern void cbreak_on();
extern void cbreak_off();

extern void keypad_on();
extern void keypad_off();

extern void color_on();

#endif // NCURSESOPTIONS_H
