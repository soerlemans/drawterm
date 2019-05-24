#ifndef FRAME_H
#define FRAME_H

#include "Cursor.hpp"

#include <vector>
#include <iostream>

template<typename Type>
using Matrix = std::vector<std::vector<Type>>;

//1 screenstate/frame from the animation
class Frame
{
private:
    Matrix<RGB> m_matrix;

public:

    void SetPoint(int t_x, int t_y, const RGB& t_color) noexcept;

    std::vector<RGB>& operator[](unsigned t_index) noexcept;
};

#endif // FRAME_H

