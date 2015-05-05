#ifndef UDPPACKET_H
#define UDPPACKET_H
#include "SDL_net.h"
#include <string>
#include "IPacket.h"
namespace StiGame
{

namespace Net
{

class UdpPacket :
        public IPacket
{
public:
    UdpPacket();
    UdpPacket(UDPpacket *m_packet);
    UdpPacket(int m_size);
    virtual ~UdpPacket();

    UDPpacket* packet(void);
    void resize(int m_size);
    int getSize(void);
    int len(void);
    Uint8* data(void);
    int channel(void);
    IPaddress* ipAddress(void);
    int maxlen(void);
    int status(void);
    void setString(std::string message);
    std::string getString(void);

    void setLen(int m_len);

    void write(char byte, int index);
    void write(char *bytes, int index, int length);

    char* read(int index, int length);
    char read(int index);



private:
    UDPpacket* _packet;
    int size;
};

}


}

#endif // UDPPACKET_H
