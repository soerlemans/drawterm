#ifndef VIDEO_H
#define VIDEO_H

#include "Frame.hpp"

extern void SetVideo_Pos(std::size_t t_pos) noexcept;
extern std::size_t GetVideo_Pos() noexcept;

extern void NextFrame(std::size_t t_amount = 1) noexcept;
extern void PreviousFrame(std::size_t _amount = 1) noexcept;

extern void        SetVideoLength(std::size_t t_length = 1);
extern std::size_t GetVideoLength() noexcept;
extern std::size_t GetMaxVideoLength() noexcept;

extern void Setwh(std::size_t t_w = 1, std::size_t t_h = 1);
extern auto Getwh()    ->std::tuple<std::size_t, std::size_t>;
extern auto Getwhl() ->std::tuple<std::size_t, std::size_t, std::size_t>;
  
extern void SetCurrentFramePoint();
extern void DrawCurrentFrame(int t_screen_w, int t_screen_h);

#endif // VIDEO_H
