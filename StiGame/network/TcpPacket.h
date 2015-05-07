#ifndef TCPPACKET_H
#define TCPPACKET_H
#include "IPacket.h"

namespace StiGame
{

namespace Net
{

class TcpPacket :
        public IPacket
{
public:
    static const int DEFAULT_MAX_LENGTH = 1024;

    TcpPacket();
    TcpPacket(int m_maxlen);
    TcpPacket(char * m_data, int m_len);
    virtual ~TcpPacket();

    int len(void);
    int maxlen(void);

    void setLen(int m_len);


    void write(char byte, int index);
    void write(char *bytes, int index, int length);

    char read(int index);
    char* read(int index, int length);

    PacketType type(void);

    char * data(void);

private:
    int _maxlen;
    int _len;
    char * _data;
};

}

}

#endif // TCPPACKET_H
