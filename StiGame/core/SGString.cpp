#include "SGString.h"

namespace StiGame
{

SGString SGString::parseInt(int m_int)
{
    std::string str = std::to_string(m_int);
    return SGString(str);
}

SGString::SGString()
{
    _string = "";
}

SGString::SGString(std::string m_string)
{
    _string = m_string;
}

SGString::~SGString()
{

}

int SGString::toInt(void)
{
    return atoi(_string.c_str());
}

const char* SGString::c_str()
{
    return _string.c_str();
}

size_t SGString::length(void)
{
    return _string.length();
}

std::string SGString::getStdString(void)
{
    return _string;
}

std::vector<SGString> SGString::split(char separator)
{
    std::string workset = _string;
    std::vector<SGString> splitted;

    size_t pos = workset.find_first_of(separator);

    while(pos != std::string::npos)
    {
        std::string sub = workset.substr(0, pos);

        if(workset.length() >= pos + 1)
        {
            workset = workset.substr(pos+1);
        }

        if(sub.length() > 0)
        {
            splitted.push_back(sub);
        }

        pos = workset.find_first_of(separator);
    }

    if(workset.length() > 0)
    {
        splitted.push_back(workset);
    }
    return splitted;
}


}
