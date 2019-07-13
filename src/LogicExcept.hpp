#ifndef LOGICEXCEPT_H
#define LOGICEXCEPT_H

#include "Except.hpp"

//a mistake was made on the programmers
//behalf so do strong guarentee
class LogicExcept : public Except
{
public:
  LogicExcept(const std::string& t_msg);
};

#endif //LOGICEXCEPT_H
