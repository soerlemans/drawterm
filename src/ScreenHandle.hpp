#ifndef SCREENHANDLE_H
#define SCREENHANDLE_H

#include "Prompt.hpp"
#include "CursorAttributes.hpp"
#include "Video.hpp"

#include <cmath>
#include <sstream>

extern std::string GetCOLOR_PAIRSRange();
extern std::string GetCOLORSRange();

extern void CreatePair();
extern void ChangeColor();
extern void ChangeCharacter();
extern void ChangePair_Pos();
extern void ChangeVideoLength(Video& t_video);
extern void ChangeCanvasSize(Video& t_video);

extern void ScreenHandle(const int t_keypress, Video& t_video, CursorAttributes& t_attributes, Offset t_offset);

#endif // SCREENHANDLE_H
