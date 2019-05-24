#include "Frame.hpp"

//FRAME
void Frame::SetPoint(int t_x, int t_y, const RGB& t_color) noexcept
{
        m_matrix[t_x][t_y] = t_color;
}

std::vector<RGB>& Frame::operator[](unsigned t_index) noexcept
{
    return m_matrix[t_index];
}

