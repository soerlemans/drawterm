#ifndef SCREENHANDLE_H
#define SCREENHANDLE_H

#include "Prompt.hpp"
#include "Video.hpp"

#include <cmath>
#include <sstream>

extern std::string GetCOLOR_PAIRSRange();
extern std::string GetCOLORSRange();

extern void ChangeColor();
extern void ChangeCharacter();
extern void ChangePair_Pos();
extern void ChangeVideoLength();
extern void ChangeCanvasSize();

extern void ScreenHandle(int t_keypress);

#endif // SCREENHANDLE_H
