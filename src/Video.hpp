#ifndef VIDEO_H
#define VIDEO_H

#include "Frame.hpp"

extern void GotoFrame(std::size_t t_pos) noexcept;

extern void NextFrame(std::size_t t_amount = 1) noexcept;
extern void PreviousFrame(std::size_t _amount = 1) noexcept;

extern void        SetVideoLength(std::size_t t_length = 1);
extern std::size_t GetVideoLength() noexcept;
extern std::size_t GetMaxVideoLength() noexcept;

extern void Setwh(std::size_t t_w = 1, std::size_t t_h = 1);

extern void SetCurrentFramePoint(const std::size_t t_x, const std::size_t t_y, char t_character, int t_color_pair);
extern void DrawCurrentFrame(int t_screen_w, int t_screen_h);

#endif // VIDEO_H
