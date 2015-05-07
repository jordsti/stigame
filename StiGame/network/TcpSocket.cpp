#include "TcpSocket.h"
#include <iostream>
namespace StiGame
{

namespace Net
{

TcpSocket::TcpSocket(int port)
{
    //ctor
    if(SDLNet_ResolveHost(&address, NULL, port) == -1)
    {
        std::cout << "SDL_net error : " << SDLNet_GetError() << std::endl;
    }
}

TcpSocket::TcpSocket(char *hostname, int port)
{
    //ctor
    if(SDLNet_ResolveHost(&address, hostname, port) == -1)
    {
        std::cout << "SDL_net error : " << SDLNet_GetError() << std::endl;
    }
}

void TcpSocket::open()
{
    tcpSocket = SDLNet_TCP_Open(&address);
    if(!tcpSocket)
    {
        std::cout << "Error while binding port..." << std::endl;
    }
}

void TcpSocket::send(char *data, int length)
{
    if(SDLNet_TCP_Send(tcpSocket, data, length) < length)
    {
        std::cout << "Error while transferring..." << std::endl;
    }
}

int TcpSocket::recv(char *data, int length)
{
    int rs = SDLNet_TCP_Recv(tcpSocket, data, length);
    if(rs == -1 || rs == 0)
    {
        std::cout << "Error while receiving..." << std::endl;
    }

    return rs;
}

void TcpSocket::send(TcpPacket *packet)
{
    send(packet->data(), packet->len());
}

TcpPacket* TcpSocket::recv(int maxLength)
{
    char * data = new char[maxLength];
    int _recv = recv(data, maxLength);
    TcpPacket *packet = new TcpPacket(data, _recv);
    return packet;
}

void TcpSocket::close()
{
    SDLNet_TCP_Close(tcpSocket);
}

TcpSocket::~TcpSocket()
{
    //dtor
    SDLNet_TCP_Close(tcpSocket);
}

}

}
