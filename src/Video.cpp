#include "Video.hpp"

//the current position in the video
std::size_t g_video_pos {0};

//the offset of the rendering if youre canvas is bigger than the terminal dimensions
std::size_t g_offset_x {0}, g_offset_y {0};

//the video is just a range of frames
std::vector<Frame> g_video;

//if anything is changed then redraw the current frame
bool g_changed {false};

void GotoFrame(std::size_t t_pos)
{ 
  std::size_t video_max_range {g_video.size()-1};

  g_video_pos = (t_pos > video_max_range) ?
    video_max_range :
    t_pos ;

  g_changed = true;
}

void NextFrame(std::size_t t_amount)
{
  g_video_pos += t_amount;

  if(g_video_pos >= g_video.size())
    g_video_pos = 0;

  g_changed = true;
}

void PreviousFrame(std::size_t t_amount)
{
  std::size_t video_max_range {g_video.size()-1};

  g_video_pos -= t_amount;

  if(g_video_pos > video_max_range)
    g_video_pos = video_max_range;
  
  g_changed = true;
}

void SetVideoLength(std::size_t t_length)
{
  g_video.resize(t_length);
}

std::size_t GetVideoLength()
{
  return g_video.size();
}

std::size_t GetMaxVideoLength()
{
  return g_video.max_size();
}

void DrawCurrentFrame(int t_screen_w, int t_screen_h)
{
  if(g_changed)
    g_video[g_video_pos].DrawFrame(t_screen_w, t_screen_h, g_offset_x, g_offset_y);
}
