#include "HTTPTest.h"
#include "TcpSocket.h"
#include <string>
#include <iostream>
HTTPTest::HTTPTest()
{

}

HTTPTest::~HTTPTest()
{

}

void HTTPTest::execute(void)
{
    StiGame::Net::TcpSocket socket ("ci.sticode.org", 80);
    int bufferSize = 65536;
    char *req = "GET / HTTP/1.1\r\nHost:ci.sticode.org\r\n\r\n";
    int len = strlen(req);
    char buffer[bufferSize];

    StiGame::Net::TcpPacket *packet = new StiGame::Net::TcpPacket(req, len);

    socket.open();

    socket.send(packet);
    SDL_Delay(100);
    StiGame::Net::TcpPacket *recvPacket = socket.recv(14096);

    std::cout << recvPacket->data() << std::endl;

    //recv = socket.recv(buffer, bufferSize);
    //std::cout << buffer << std::endl;


    socket.close();

}
