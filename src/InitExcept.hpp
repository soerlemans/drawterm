#ifndef INITEXCEPT_H
#define INITEXCEPT_H

#include "Except.hpp"

//after this exception the program will almost always
//be unable to conitue so just terminate and log it
class InitExcept : public Except
{
public:
  InitExcept(const std::string& t_msg);
};

#endif //INITEXCEPT_H
