#ifndef IPACKET_H
#define IPACKET_H
#include "SDL_net.h"
namespace StiGame
{

namespace Net
{
class PacketStream;

enum PacketType {
    PT_Tcp,
    PT_Udp
};

class IPacket
{
public:
    IPacket();
    virtual ~IPacket();

    virtual int len(void) = 0;
    virtual int maxlen(void) = 0;

    virtual void setLen(int m_len) = 0;


    virtual void write(char byte, int index) = 0;
    virtual void write(char *bytes, int index, int length) = 0;

    virtual char read(int index) = 0;
    virtual char* read(int index, int length) = 0;

    virtual PacketStream stream(void);

    virtual PacketType type(void) = 0;

};

}

}

#endif // IPACKET_H
