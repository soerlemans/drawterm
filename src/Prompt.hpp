#ifndef PROMPT_H
#define PROMPT_H

#include "Cursor.hpp"
#include "NcursesOptions.hpp"

#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

extern void ClearPrompt(WINDOW* t_win = stdscr);

extern void DrawPrompt(WINDOW* t_win = stdscr, const std::string& t_text = ":");
extern void DrawPromptLine(WINDOW* t_win = stdscr);
extern void DrawPromptBrush(WINDOW* t_win = stdscr);

extern void DrawPromptMessage(WINDOW* t_win = stdscr, const std::string& t_text = "Press Enter", int t_conformation = 10);

extern std::string InputPrompt_Str(WINDOW* t_win = stdscr, const std::string& t_text = "prompt:", int t_input_length = 4);

extern char InputPrompt_Char(WINDOW* t_win = stdscr, const std::string& t_text="yes or no:", const std::string& t_allowed_chars="yn");

//giving them default parameters makes them ambiguos
extern int InputPrompt_Int(WINDOW* t_win, const std::string& t_text, int t_input_lenght, int t_min, int t_max);
extern int InputPrompt_Int(WINDOW* t_win, std::string t_text, int t_min, int t_max);

#endif // PROMPT_H
