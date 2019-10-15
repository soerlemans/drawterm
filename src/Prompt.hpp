#ifndef PROMPT_H
#define PROMPT_H

#include "Cursor.hpp"
#include "NcursesOptions.hpp"

#include <cmath>
#include <string>
#include <sstream>

extern void ClearPrompt() noexcept;

extern void DrawPrompt(const std::string& t_text = ":") noexcept;
extern void DrawPromptLine() noexcept;
extern void DrawPromptBrush();
extern void DrawDimensions(std::size_t t_x, std::size_t t_y, std::size_t t_p, std::size_t t_w, std::size_t t_h, std::size_t t_l);

extern void DrawPromptMessage(const std::string& t_text = "Press Enter", int t_conformation = 10);

extern std::string InputPrompt_Str(const std::string& t_text = "prompt:", int t_input_length = 4);

extern char InputPrompt_Char(const std::string& t_text="yes or no:", const std::string& t_allowed_chars="yn");

//TODO clean the logn long's up with a using statement and clean up a lot moer of things
//giving them default parameters makes them ambiguos
extern          long long InputPrompt_LL (const std::string& t_text, int t_input_lenght, long long          t_min, long long          t_max);
extern unsigned long long InputPrompt_ULL(const std::string& t_text, int t_input_lenght, unsigned long long t_min, unsigned long long t_max);

extern          long long InputPrompt_LL (std::string t_text, long long          t_min, long long          t_max);
extern unsigned long long InputPrompt_ULL(std::string t_text, unsigned long long t_min, unsigned long long t_max);

#endif // PROMPT_H
