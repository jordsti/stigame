#include "UdpSocket.h"
#include <iostream>
namespace StiGame
{

namespace Net
{
//todo is open handle
UdpSocket::UdpSocket()
{
    //ctor
    packetSize = DEFAULT_PACKET_SIZE;
}

UdpSocket::~UdpSocket()
{
    //dtor

}

void UdpSocket::open(int port)
{
    udpSocket = SDLNet_UDP_Open(static_cast<Uint16>(port));
    if(!udpSocket)
    {
        std::cout << "[ERROR] " << SDL_GetError() << std::endl;
    }
}

void UdpSocket::send(UDPpacket *udpPacket, int channel)
{
    int sent = SDLNet_UDP_Send(udpSocket, channel, udpPacket);
    //todo sent error
}

UdpPacket* UdpSocket::recv(void)
{
    UdpPacket *packet = new UdpPacket(packetSize);
    int recv = SDLNet_UDP_Recv(udpSocket, packet->packet());

    if(recv == 1)
    {
        return packet;
    }
    else
    {
        delete packet;
        return nullptr;
    }
}

IPaddress* UdpSocket::getPeerAddress(int channel)
{
    IPaddress *addr;
    SDLNet_UDP_GetPeerAddress(udpSocket, channel);
}

int UdpSocket::bind(int channel, IPaddress *address)
{
    channel = SDLNet_UDP_Bind(udpSocket, channel, address);
    if(channel == -1)
    {
        std::cout << "[ERROR] Unable to bind UDP Socket : " << SDL_GetError() << std::endl;
    }

    return channel;
}

void UdpSocket::unbind(int channel)
{
    SDLNet_UDP_Unbind(udpSocket, channel);
}


void UdpSocket::close(void)
{
    SDLNet_UDP_Close(udpSocket);
}

int UdpSocket::getPacketSize(void)
{
    return packetSize;
}

void UdpSocket::setPacketSize(int m_packetSize)
{
    packetSize = m_packetSize;
}

}

}
