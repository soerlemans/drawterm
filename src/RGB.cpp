#include "RGB.hpp"

RGB::RGB()
  :m_character('0'),
   m_fg_r(0),
   m_fg_g(0),
   m_fg_b(0),
   m_bg_r(0),
   m_bg_g(0),
   m_bg_b(0)
{
}

RGB::RGB(const RGB& t_rhs)
{
  this->m_character = t_rhs.m_character;
  
  this->m_fg_r = t_rhs.m_fg_r;
  this->m_fg_g = t_rhs.m_fg_g;
  this->m_fg_b = t_rhs.m_fg_b;

  this->m_bg_r = t_rhs.m_bg_r;
  this->m_bg_g = t_rhs.m_bg_g;
  this->m_bg_b = t_rhs.m_bg_b;
}

bool RGB::Set_Character(char t_character)
{
  if(t_character > 127 || t_character < 0) return false;

  m_character = t_character;

  return true;
}

bool RGB::Set_R(short t_r)
{
   if(t_r > 1000 || t_r < 0) return false;

   m_fg_r = t_r;
   m_bg_r = t_r;
   
   return true;
}

bool RGB::Set_G(short t_g)
{
   if(t_g > 1000 || t_g < 0) return false;

   m_fg_g = t_g;
   m_bg_g = t_g;
   
   return true;
}

bool RGB::Set_B(short t_b)
{
   if(t_b > 1000 || t_b < 0) return false;

   m_fg_b = t_b;
   m_bg_b = t_b;

   return true;
}

bool RGB::SetFg_R(short t_r)
{
    if(t_r > 1000 || t_r < 0) return false;

    m_fg_r = t_r;

    return true;
}

bool RGB::SetFg_G(short t_g)
{
    if(t_g > 1000 || t_g < 0) return false;

    m_fg_g = t_g;

    return true;
}

bool RGB::SetFg_B(short t_b)
{
    if(t_b > 1000 || t_b < 0) return false;

    m_fg_b = t_b;

    return true;
}

bool RGB::SetBg_R(short t_r)
{
    if(t_r > 1000 || t_r < 0) return false;

    m_bg_r = t_r;

    return true;
}

bool RGB::SetBg_G(short t_g)
{
    if(t_g > 1000 || t_g < 0) return false;

    m_bg_g = t_g;

    return true;
}

bool RGB::SetBg_B(short t_b)
{
    if(t_b > 1000 || t_b < 0) return false;

    m_bg_b = t_b;

    return true;
}

bool RGB::CheckValues()
{
    if(m_character > 127  || m_character < 0
    || m_fg_r > 1000 || m_fg_r < 0
    || m_fg_g > 1000 || m_fg_g < 0
    || m_fg_b > 1000 || m_fg_b < 0
       
    || m_bg_r > 1000 || m_bg_r < 0
    || m_bg_g > 1000 || m_bg_g < 0
    || m_bg_b > 1000 || m_bg_b < 0)
        return false;
    else
        return true;
}

void RGB::ResetValues()
{
  m_character = '0';
  
  m_fg_r = 0;
  m_fg_g = 0;
  m_fg_b = 0;
  
  m_bg_r = 0;
  m_bg_g = 0;
  m_bg_b = 0;
}

RGB RGB::operator=(const RGB& t_rhs)
{
  this->m_character = t_rhs.m_character;
  
  this->m_fg_r = t_rhs.m_fg_r;
  this->m_fg_g = t_rhs.m_fg_g;
  this->m_fg_b = t_rhs.m_fg_b;

  this->m_bg_r = t_rhs.m_bg_r;
  this->m_bg_g = t_rhs.m_bg_g;
  this->m_bg_b = t_rhs.m_bg_b;

  return *this;
}
//color palette
std::array<RGB, 9> g_palette;
