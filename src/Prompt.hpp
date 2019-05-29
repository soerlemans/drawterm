#ifndef PROMPT_H
#define PROMPT_H

#include "Cursor.hpp"
#include "NcursesOptions.hpp"

#include <algorithm>
#include <stdexcept>
#include <string>

extern void ClearPrompt(WINDOW* t_win = stdscr);

extern void DrawPrompt(WINDOW* t_win = stdscr, const std::string& t_text = ":");
extern void DrawPromptLine(WINDOW* t_win = stdscr);
extern void DrawPromptPalette(WINDOW* t_win=stdscr);

extern void DrawPromptMessage(WINDOW* t_win = stdscr, const std::string& t_text = "Press Enter", int t_conformation = 10);


extern std::string InputPrompt_Str(WINDOW* t_win = stdscr, const std::string& t_text = "prompt:", int t_input_length = 4);
extern int InputPrompt_Int(WINDOW* t_win = stdscr, const std::string& t_text = "Insert 0-1000:", int t_input_lenght = 4, int t_min = 0, int t_max = 1000);


#endif // PROMPT_H
