#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "SDL_net.h"

namespace StiGame
{

namespace Net
{

class UdpSocket
{
    public:
        UdpSocket();
        virtual ~UdpSocket();
        void Open(int port);
        IPaddress* getPeerAddress(void);
        void Send(UDPpacket *udpPacket);
        UDPpacket* Recv(void);
    protected:
    private:
        UDPsocket udpSocket;
};

}

}

#endif // UDPSOCKET_H
