#include "Video.hpp"

//the current position in the video
std::size_t g_video_pos {0};

//the offset of the rendering if youre canvas is bigger than the terminal dimensions
std::size_t g_offset_x {0}, g_offset_y {0};

//the video is just a range of frames
std::vector<Frame> g_video;

//if anything is changed then redraw the current frame else dont change the drawing
bool g_changed {false};

void SetVideo_Pos(std::size_t t_pos) noexcept
{ 
  g_video_pos = (t_pos >= g_video.size()) ?
    g_video.size()-1 :
    t_pos;

  g_changed = true;
}

std::size_t GetVideo_Pos() noexcept
{
  return g_video_pos;
}

void NextFrame(std::size_t t_amount) noexcept
{
  const std::size_t new_pos {g_video_pos + t_amount};
  
  g_video_pos = (new_pos >= g_video.size()) ? g_video.size()-1 : new_pos;

  g_changed = true;
}

void PreviousFrame(std::size_t t_amount) noexcept
{
  const std::size_t new_pos {g_video_pos - t_amount};

  /*unsigned variable so it would loop to
    2^N-1 (N is the amount of bits in the type)
    credit:
    https://stackoverflow.com/questions/27882579/is-decrementing-an-unsigned-int-below-0-undefined-behavior
    so just let it loop around and only do something against overflow
  */
  g_video_pos = (new_pos >= g_video.size()) ? 0 : new_pos;

  g_changed = true;
}

//Frame& GetFrame()

void SetVideoLength(std::size_t t_length)
{
  static constexpr short min_amount {1};
  auto max_amount {g_video.max_size()};
  
  if(t_length < min_amount) t_length = min_amount;
  if(t_length > max_amount) t_length = max_amount;
  
  g_video.resize(t_length);

  //make the new Frames the same width and height
  auto[w, h] = Getwh();
  Setwh(w, h);
}

std::size_t GetVideoLength() noexcept
{
  return g_video.size();
}

std::size_t GetMaxVideoLength() noexcept
{
  return g_video.max_size();
}

void Setwh(std::size_t t_w, std::size_t t_h)
{
  std::for_each(begin(g_video), end(g_video),
		[&](Frame& t_frame)
		{
		  t_frame.Setwh(t_w, t_h);
		});
}

auto Getwh() -> std::tuple<std::size_t, std::size_t>
{
  return g_video.front().Getwh();
}

auto Getwhl() -> std::tuple<std::size_t, std::size_t, std::size_t>
{
  auto[w, h] = g_video.front().Getwh();
  return std::tuple(w, h, g_video.size());
}

void SetCurrentFramePoint()
{
  auto[x, y] = GetCurxy();
  g_video[g_video_pos].SetPoint(x, y, GetCharacter(), GetPair_Pos());

  g_changed = true;
}

void DrawCurrentFrame(int t_screen_w, int t_screen_h)
{
  if(g_changed)
    {
      g_video[g_video_pos].DrawFrame(t_screen_w, t_screen_h, g_offset_x, g_offset_y);
      g_changed = false;
    }
}

