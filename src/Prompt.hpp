#ifndef PROMPT_H
#define PROMPT_H

#include "Cursor.hpp"
#include "NcursesOptions.hpp"

#include <cmath>
#include <string>
#include <sstream>

extern void ClearPrompt(WINDOW* t_win = stdscr) noexcept;

extern void DrawPrompt(WINDOW* t_win = stdscr, const std::string& t_text = ":") noexcept;
extern void DrawPromptLine(WINDOW* t_win = stdscr) noexcept;
extern void DrawPromptBrush(WINDOW* t_win = stdscr);
extern void DrawDimensions(WINDOW* t_win = stdscr);

extern void DrawPromptMessage(WINDOW* t_win = stdscr, const std::string& t_text = "Press Enter", int t_conformation = 10);

extern std::string InputPrompt_Str(WINDOW* t_win = stdscr, const std::string& t_text = "prompt:", int t_input_length = 4);

extern char InputPrompt_Char(WINDOW* t_win = stdscr, const std::string& t_text="yes or no:", const std::string& t_allowed_chars="yn");

//TODO clean the logn long's up with a using statement and clean up a lot moer of things
//giving them default parameters makes them ambiguos
extern          long long InputPrompt_LL (WINDOW* t_win, const std::string& t_text, int t_input_lenght, long long          t_min, long long          t_max);
extern unsigned long long InputPrompt_ULL(WINDOW* t_win, const std::string& t_text, int t_input_lenght, unsigned long long t_min, unsigned long long t_max);

extern          long long InputPrompt_LL (WINDOW* t_win, std::string t_text, long long          t_min, long long          t_max);
extern unsigned long long InputPrompt_ULL(WINDOW* t_win, std::string t_text, unsigned long long t_min, unsigned long long t_max);

#endif // PROMPT_H
