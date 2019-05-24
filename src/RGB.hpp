#ifndef RGB_H
#define RGB_H

#include <array>

//the colors that reside in there might need its own file for this
class RGB
{
private:
  //for outputing any multiple color options
  char m_character {'0'};
  
  short m_fg_r {0},
    m_fg_g {0},
    m_fg_b {0},
    
    m_bg_r {0},
    m_bg_g {0},
    m_bg_b {0};

public:

  RGB();
  RGB(const RGB& t_rhs);
  
  bool Set_Character(char t_character);
  
  bool Set_R(short t_r);
  bool Set_G(short t_g);
  bool Set_B(short t_b);
      
  bool SetFg_R(short t_r);
  bool SetFg_G(short t_g);
  bool SetFg_B(short t_b);
  
  bool SetBg_R(short t_r);
  bool SetBg_G(short t_g);
  bool SetBg_B(short t_b);
  
  bool CheckValues();
  void ResetValues();

  RGB operator=(const RGB& t_rhs);
};

//stores the color palette 
extern std::array<RGB, 9> g_palette;

#endif // RGB_H
