#ifndef EXCEPT_H
#define EXCEPT_H

#include <string>

//replaces std::runtime_error in this program for syntactical reasons
class Except
{
private:
  std::string m_msg;

public:
  Except();
  Except(const Except& t_rhs) = default;
  Except(const std::string& t_msg);

  void setwhat(const std::string& t_msg);
  std::string what() const;

  Except operator=(const Except& t_rhs);
  Except operator+=(const std::string& t_msg);
};

#endif // EXCEPT_H
