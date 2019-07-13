#include "Except.hpp"

Except::Except()
{
  
}

Except::Except(const std::string& t_msg)
:m_msg(t_msg)
{
    //ctor
}

void Except::setwhat(const std::string& t_msg)
{
  m_msg = t_msg;
}

std::string Except::what() const
{
  return m_msg;
}

Except Except::operator=(const Except& t_rhs)
{
  this->m_msg = t_rhs.m_msg;
  return *this;
}

Except Except::operator+=(const std::string& t_msg)
{
  this->m_msg += t_msg;
  return *this;
}

