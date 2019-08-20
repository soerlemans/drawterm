#include "Frame.hpp"

//FRAME

Frame::Frame()
{
  m_matrix.resize(1, std::vector<Character>(1, Character{'0', 0}));
}

void Frame::SetPoint(const std::size_t t_x, const std::size_t t_y, const Character& t_color) noexcept
{
  m_matrix[t_x][t_y] = t_color;
}

void Frame::SetPoint(const std::size_t t_x, const std::size_t t_y, char t_character, int t_color_pair) noexcept
{
  m_matrix[t_x][t_y] = Character{t_character, t_color_pair};
}

void Frame::Setwh(std::size_t t_w, std::size_t t_h)
{
  try{
    
    static constexpr std::size_t min_amount {1};
    const std::size_t max_amount_w {m_matrix.at(0).max_size()},
                                    max_amount_h {m_matrix.max_size()};
    
    //size should be atleast 1x1
    if(t_h < min_amount) t_h = min_amount;
    if(t_w < min_amount) t_w = min_amount;

    if(t_h > max_amount_h) t_h = max_amount_h;
    if(t_w > max_amount_w) t_w = max_amount_w;
    
    m_matrix.resize(t_h);
    std::for_each(m_matrix.begin(), m_matrix.end(),
		  [t_width = t_w](auto& t_row){t_row.resize(t_width);}
		  );
  }catch(std::out_of_range& except)
    {
      throw LogicExcept("out of range access int Frame::Setwh() ");
    }
}

//TODO make this so it never throws an out of range exception
auto Frame::Getwh() ->std::tuple<std::size_t, std::size_t>
{
  return {};
}

std::vector<Character>& Frame::operator[](unsigned t_index)
{
    return m_matrix[t_index];
}

void Frame::DrawLine(const std::vector<Character>& t_line, std::size_t t_screen_w, std::size_t t_offset_x)
{
  std::size_t matrix_width {t_offset_x + t_screen_w};
  std::size_t index {(t_offset_x + t_screen_w) > matrix_width};

  if(matrix_width < t_screen_w)
    {
      matrix_width = t_line.size();
      index = 0;
    }
  
  for(int x_pos {0}; index < matrix_width; index++, x_pos++)
    {
      	Movex(stdscr, x_pos);
	const auto& point = t_line[x_pos];
	
      try{

	attribute_on(COLOR_PAIR(point.second));
	addch(point.first);
	attribute_off(COLOR_PAIR(point.second));

      }catch(InitExcept& catched){
	catched += " Frame::DrawLine()";
	throw catched;
      }
    }
}

void Frame::DrawFrame(std::size_t t_screen_w, std::size_t t_screen_h, std::size_t t_offset_x, std::size_t t_offset_y)
{
    std::size_t matrix_height {t_offset_y + t_screen_h};
    std::size_t index{((t_offset_y + t_screen_h) > matrix_height) ? matrix_height - t_screen_h : t_offset_y};
  
  if(matrix_height < t_screen_h)
    {
      matrix_height = m_matrix.size();
      index = 0;
    }
  
  for(int y_pos {0}; index < matrix_height; index++, y_pos++)
    {
      try{
	Movey(stdscr, y_pos);
      
	DrawLine(m_matrix[index], t_screen_w, t_offset_x);
	Movey(stdscr, y_pos); //change this for later allow to specify the DrawFrame window* param TODO
	
      }catch(InitExcept& catched){
	catched += " Frame::DrawFrame()";
	throw catched;
      }
    }
}
