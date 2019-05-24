#include "RT_Error.hpp"

RT_Error::RT_Error(const std::string& t_msg)
:m_msg(t_msg)
{
    //ctor
}

std::string RT_Error::what()
{
    return m_msg;
}

RT_Error RT_Error::operator=(const RT_Error& t_rhs)
{
    this->m_msg = t_rhs.m_msg;
    return *this;
}

RT_Error RT_Error::operator+=(const std::string& t_msg)
{
    m_msg += t_msg;

    return *this;
}

RT_Error::~RT_Error()
{
    //dtor
}
