#include "SGString.h"
namespace sgrc {

SGString::SGString(std::string m_string)
{
    _string = m_string;
}

SGString::~SGString()
{

}

bool SGString::startsWith(std::string prefix)
{
    if(_string.length() >= prefix.length())
    {
        std::string sub = _string.substr(0, prefix.length());
        if(sub == prefix)
            return true;
    }

    return false;
}

SGString SGString::substr(size_t start, size_t length)
{
    if(start + length < _string.length())
    {
        std::string _nstr = _string.substr(start, length);
        return SGString(_nstr);
    }
    else
    {
        //out of range exception ?
    }

    return SGString("");
}


void SGString::removeTrailingSpaces(void)
{
    if(_string.length() > 0)
    {
        while(_string.length() > 0 && _string.at(0) == ' ')
        {
            _string = _string.substr(1, _string.length() - 1);
        }

        while(_string.length() > 0 && _string.at(_string.length() - 1) == ' ')
        {
            _string = _string.substr(0, _string.length() - 1);
        }
    }
}

void SGString::removeEndLine(void)
{
    if(_string.at(_string.length()-1) == '\n')
    {
        _string = _string.substr(0, _string.length()-1);
        //windows eol of course
        if(_string.at(_string.length()-1) == '\r')
        {
            _string = _string.substr(0, _string.length()-1);
        }
    }
}

bool SGString::endsWith(std::string suffix)
{
    if(_string.length() >= suffix.length())
    {
        std::string sub = _string.substr(_string.length() - suffix.length(), suffix.length());
        if(sub == suffix)
            return true;
    }
    return false;
}

const size_t SGString::length(void)
{
    return _string.length();
}


std::string SGString::getStdString(void)
{
    return _string;
}

}


