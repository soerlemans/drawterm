#ifndef NCURSESOPTIONS_H
#define NCURSESOPTIONS_H

#include "InitExcept.hpp"

#include <ncurses.h>

extern void echo_on();
extern void echo_off();

extern void cbreak_on();
extern void cbreak_off();

extern void keypad_on();
extern void keypad_off();

//attr_on() is ambigous
extern void attribute_on(int t_attrs);
extern void attribute_off(int t_attrs);

extern void color_on();

#endif // NCURSESOPTIONS_H
