#ifndef VIDEO_H
#define VIDEO_H

#include "Frame.hpp"

class Video{

private:
  std::size_t m_video_pos {0};
  std::vector<Frame> m_video;

  std::size_t m_offset_x {0}, m_offset_y {0};
  bool m_screen_changed {false};
  
public:
  void SetVideo_Pos(std::size_t t_pos) noexcept;
  std::size_t GetVideo_Pos() noexcept;

  void NextFrame(std::size_t t_amount = 1) noexcept;
  void PreviousFrame(std::size_t _amount = 1) noexcept;

  void        SetVideoLength(std::size_t t_length = 1);
  std::size_t GetVideoLength() noexcept;
  std::size_t GetMaxVideoLength() noexcept;

  void Setwh(std::size_t t_w = 1, std::size_t t_h = 1);
  auto Getwh()  ->std::tuple<std::size_t, std::size_t>;
  auto Getwhl() ->std::tuple<std::size_t, std::size_t, std::size_t>;
  
  void SetFramePoint(const CursorAttributes& t_attributes);
  void DrawCurrentFrame(int t_screen_w, int t_screen_h);
};
#endif // VIDEO_H
