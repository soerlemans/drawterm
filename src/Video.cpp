#include "Video.hpp"

void Video::SetVideo_Pos(std::size_t t_pos) noexcept
{ 
  m_video_pos = (t_pos >= m_video.size()) ?
    m_video.size()-1 :
    t_pos;

  m_screen_changed = true;
}

std::size_t Video::GetVideo_Pos() const noexcept
{
  return m_video_pos;
}

void Video::NextFrame(std::size_t t_amount) noexcept
{
  const std::size_t new_pos {m_video_pos + t_amount};
  
  m_video_pos = (new_pos >= m_video.size()) ? m_video.size()-1 : new_pos;

  m_screen_changed = true;
}

void Video::PreviousFrame(std::size_t t_amount) noexcept
{
  const std::size_t new_pos {m_video_pos - t_amount};

  /*unsigned variable so it would loop to
    2^N-1 (N is the amount of bits in the type)
    credit:
    https://stackoverflow.com/questions/27882579/is-decrementing-an-unsigned-int-below-0-undefined-behavior
    so just let it loop around and only do something against overflow
  */
  m_video_pos = (new_pos >= m_video.size()) ? 0 : new_pos;

  m_screen_changed = true;
}

//Frame& GetFrame()

void Video::SetVideoLength(std::size_t t_length)
{
  static constexpr short min_amount {1};
  auto max_amount {m_video.max_size()};
  
  if(t_length < min_amount) t_length = min_amount;
  if(t_length > max_amount) t_length = max_amount;
  
  m_video.resize(t_length);

  //make the new Frames the same width and height
  auto[w, h] = Getwh();
  Setwh(w, h);
}

std::size_t Video::GetVideoLength() const noexcept
{
  return m_video.size();
}

std::size_t Video::GetMaxVideoLength() const noexcept
{
  return m_video.max_size();
}

void Video::Setwh(std::size_t t_w, std::size_t t_h)
{
  for(Frame& frame : m_video){
    frame.Setwh(t_w, t_h);
  }
  
  m_screen_changed = true;
}

auto Video::Getwh() const -> std::tuple<std::size_t, std::size_t>
{
  return m_video.front().Getwh();
}

auto Video::Getwhl() const -> std::tuple<std::size_t, std::size_t, std::size_t>
{
  auto[w, h] = m_video.front().Getwh();
  return std::tuple(w, h, m_video.size());
}

void Video::SetFramePoint(const CursorAttributes& t_attributes, const Offset& t_offset)
{
  auto[x, y] = GetCurxy();
  m_video[m_video_pos].SetPoint(x + t_offset.GetOffsetx(), y + t_offset.GetOffsety(), t_attributes.GetBrush(), t_attributes.GetPair_Pos());

  m_screen_changed = true;
}

void Video::DrawCurrentFrame(const int t_screen_w, const int t_screen_h, const Offset t_offset) const 
{
  if(m_screen_changed){
    m_video[m_video_pos].DrawFrame(t_screen_w, t_screen_h, t_offset.GetOffsetx(), t_offset.GetOffsety());
    m_screen_changed = false;
  }
}

