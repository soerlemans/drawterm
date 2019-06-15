#ifndef VIDEO_H
#define VIDEO_H

#include "Frame.hpp"

extern void GotoFrame(std::size_t t_pos);

extern void NextFrame(std::size_t t_amount = 1);
extern void Previousrame(std::size_t _amount = 1);

extern void SetVideoLength(std::size_t t_length);
extern std::size_t GetVideoLength();
extern std::size_t GetMaxVideoLength();

extern void DrawCurrentFrame(int t_screen_w, int t_screen_h);

#endif // VIDEO_H
