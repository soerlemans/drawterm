#include "Video.hpp"

Video::Video()
{
    //ctor
}


Frame& Video::operator[](unsigned t_index) noexcept
{
    return m_video[t_index];
}


Video::~Video()
{
    //dtor
}

Video g_video;
