#include "ScreenHandle.hpp"

//handles all the keybinds that change the state of the screen

//these only exist in this cpp

void ChangeCursorColor()
{
    DrawPromptMessage(stdscr, "Insert the RGB values between 0-1000: PRESS ENTER");

    short color_r = InputPrompt_Int(stdscr, "Insert R:", 4, 0, 1000);
    short color_g = InputPrompt_Int(stdscr, "Insert G:", 4, 0, 1000);
    short color_b = InputPrompt_Int(stdscr, "Insert B:", 4, 0, 1000);

    RGB color;
    
    color.Set_R(color_r);
    color.Set_G(color_g);
    color.Set_B(color_b);
    
    g_palette[g_cursor.GetPalette_Pos()] = color;
}

void ChangePalette_Pos(int t_palette_pos)
{
  if(t_palette_pos >= 0 && t_palette_pos <= 9)
    g_cursor.SetPalette_Pos(t_palette_pos);

  DrawPrompt(stdscr, "Changed Palette_Pos");
  wrefresh(stdscr);
}

void ScreenHandle(int t_keypress)
{
    switch(t_keypress)
    {
      //reset selected color palette
    case '0':
      break;

    case 99:
        ChangeCursorColor();
        break;

    case 10:
      break;

    default:
      ChangePalette_Pos(int{t_keypress - '0'});
      break;
    }
    
    
}
