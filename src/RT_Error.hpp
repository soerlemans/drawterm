#ifndef RT_ERROR_H
#define RT_ERROR_H

#include <string>

//replaces std::runtime_error in this program for syntactical reasons
class RT_Error
{
    private:
        std::string m_msg;

    public:

        RT_Error(const std::string& t_msg);

        std::string what();

        RT_Error operator=(const RT_Error& t_rhs);
        RT_Error operator+=(const std::string& t_msg);

        ~RT_Error();
};

#endif // RT_ERROR_H
