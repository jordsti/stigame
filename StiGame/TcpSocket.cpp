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

void TcpSocket::Open()
{
    tcpSocket = SDLNet_TCP_Open(&address);
    if(!tcpSocket)
    {
        std::cout << "Error while binding port..." << std::endl;
    }
}

void TcpSocket::Send(char *data, int length)
{
    if(SDLNet_TCP_Send(tcpSocket, data, length) < length)
    {
        std::cout << "Error while transferring..." << std::endl;
    }
}

void TcpSocket::Recv(char *data, int length)
{
    int rs = SDLNet_TCP_Recv(tcpSocket, data, length);
    if(rs == 1 || rs == 0)
    {
        std::cout << "Error while receiving..." << std::endl;
    }
}

TcpSocket::~TcpSocket()
{
    //dtor
    SDLNet_TCP_Close(tcpSocket);
}

}

}
