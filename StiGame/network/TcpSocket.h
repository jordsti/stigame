#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "SDL_net.h"

namespace StiGame
{

namespace Net
{

class TcpSocket
{
    public:
        TcpSocket(int port);
        TcpSocket(char *hostname, int port);
        void send(char *data, int length);
        int recv(char *data, int length);
        void open(void);
        void close(void);
        virtual ~TcpSocket();
    protected:
    private:
        TCPsocket tcpSocket;
        IPaddress address;
};

}

}
#endif // SOCKET_H
