#include "UdpSocket.h"

namespace StiGame
{

namespace Net
{
//todo is open handle
UdpSocket::UdpSocket()
{
    //ctor
}

UdpSocket::~UdpSocket()
{
    //dtor

}

void UdpSocket::Open(int port)
{
    udpSocket = SDLNet_UDP_Open(static_cast<Uint16>(port));
}

void UdpSocket::Send(UDPpacket *udpPacket)
{
    int sent = SDLNet_UDP_Send(udpSocket, udpPacket->channel, udpPacket);
    //todo sent error
}

UDPpacket* UdpSocket::Recv(void)
{
    UDPpacket *packet = new UDPpacket();
    int recv = SDLNet_UDP_Recv(udpSocket, packet);
    return packet;
}

IPaddress* UdpSocket::getPeerAddress(void)
{
    IPaddress *addr;
    SDLNet_UDP_GetPeerAddress(udpSocket, 0);
}


}

}
