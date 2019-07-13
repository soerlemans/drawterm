#include "RGB.hpp"

RGB::RGB()
  :m_r(0),
   m_g(0),
   m_b(0)
{
}

RGB::RGB(const RGB& t_rhs)
{
  this->m_r = t_rhs.m_r;
  this->m_g = t_rhs.m_g;
  this->m_b = t_rhs.m_b;
}

bool RGB::Set_R(short t_r)
{
   if(t_r > 999 || t_r < 0) return false;
 
   m_r = t_r;
   
   return true;
}

bool RGB::Set_G(short t_g)
{
   if(t_g > 999 || t_g < 0) return false;

   m_g = t_g;
   
   return true;
}

bool RGB::Set_B(short t_b)
{
   if(t_b > 999 || t_b < 0) return false;

   m_b = t_b;

   return true;
}

bool RGB::CheckValues()
{
    if(m_r > 999 || m_r < 0
    || m_g > 999 || m_g < 0
    || m_b > 999 || m_b < 0)
        return false;
    else
        return true;
}

void RGB::ResetValues()
{
  m_r = 0;
  m_g = 0;
  m_b = 0;
}

RGB RGB::operator=(const RGB& t_rhs)
{
  this->m_r = t_rhs.m_r;
  this->m_g = t_rhs.m_g;
  this->m_b = t_rhs.m_b;

  return *this;
}

