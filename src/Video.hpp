#ifndef VIDEO_H
#define VIDEO_H

#include "Frame.hpp"

#include <algorithm>

extern void GotoFrame(std::size_t t_pos);

extern void NextFrame(std::size_t t_amount = 1);
extern void Previousrame(std::size_t _amount = 1);

extern void Setwh(std::size_t t_w, std::size_t t_h);
extern auto Getwh() -> std::tuple<std::size_t, std::size_t>;

extern void SetVideoLength(std::size_t t_length);
extern int  GetVideoLength();

extern void DrawCurrentFrame(int t_screen_w, int t_screen_h);

#endif // VIDEO_H
