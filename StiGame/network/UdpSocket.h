#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "SDL_net.h"
#include "UdpPacket.h"
namespace StiGame
{

namespace Net
{

class UdpSocket
{
    public:
        static const int DEFAULT_PACKET_SIZE = 1024;
        UdpSocket();
        virtual ~UdpSocket();
        void open(int port);
        IPaddress* getPeerAddress(int channel);
        int bind(int channel, IPaddress *address);
        void unbind(int channel);
        void send(UDPpacket *udpPacket, int channel);
        UdpPacket* recv(void);
        void close(void);

        int getPacketSize(void);
        void setPacketSize(int m_packetSize);
    protected:
    private:
        UDPsocket udpSocket;
        int packetSize;
};

}

}

#endif // UDPSOCKET_H
