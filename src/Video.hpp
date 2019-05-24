#ifndef VIDEO_H
#define VIDEO_H

#include "Frame.hpp"

class Video
{
    private:
        std::vector<Frame> m_video;

    public:
        Video();

        Frame& operator[](unsigned t_index) noexcept;

        ~Video();

} extern g_video;

std::ostream& operator<<(std::ostream& t_os, Video t_video);

#endif // VIDEO_H
