#include "TcpPacket.h"
#include <iostream>
namespace StiGame
{

namespace Net
{

TcpPacket::TcpPacket()
{
    _maxlen = DEFAULT_MAX_LENGTH;
    _len = 0;
    _data = new char[_maxlen];
}

TcpPacket::TcpPacket(int m_maxlen)
{
    _maxlen = m_maxlen;
    _len = 0;
    _data = new char[_maxlen];
}

TcpPacket::TcpPacket(char * m_data, int m_len)
{
    _maxlen = m_len;
    _len = m_len;
    _data = m_data;
}

TcpPacket::~TcpPacket()
{
    delete _data;
}

int TcpPacket::len(void)
{
    return _len;
}

int TcpPacket::maxlen(void)
{
    return _maxlen;
}

void TcpPacket::setLen(int m_len)
{
    if(m_len < _maxlen)
    {
        _len = m_len;
    }
    else
    {
        std::cout << "[ERROR] TcpPacket data out of range" << std::endl;
    }
}


char * TcpPacket::data(void)
{
    return _data;
}

void TcpPacket::write(char byte, int index)
{
    if(index < _maxlen)
    {
        _data[index] = byte;
    }
    else
    {
        std::cout << "[ERROR] TcpPacket data out of range" << std::endl;
    }
}

void TcpPacket::write(char *bytes, int index, int length)
{
    if(index + length < _maxlen)
    {
        for(int i=0; i<length; i++)
        {
            _data[i+index] = bytes[i];
        }
    }
    else
    {
        std::cout << "[ERROR] TcpPacket data out of range" << std::endl;
    }
}

char TcpPacket::read(int index)
{
    if(index < _maxlen)
    {
        return _data[index];
    }
    else
    {
        std::cout << "[ERROR] TcpPacket data out of range" << std::endl;
        return '\0';
    }
}

char* TcpPacket::read(int index, int length)
{
    //this can LEAK !
    if(index + length < _maxlen)
    {
        char * bytes = new char[length];
        for(int i=0; i<length; i++)
        {
            bytes[i] = _data[i+index];
        }

        return bytes;
    }
    else
    {
        std::cout << "[ERROR] TcpPacket data out of range" << std::endl;
        return nullptr;
    }
}

PacketType TcpPacket::type()
{
    return PT_Tcp;
}

}

}
