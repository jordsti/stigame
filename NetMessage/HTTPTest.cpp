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

    socket.open();

    socket.send(req, len);
    SDL_Delay(50);
    int recv = socket.recv(buffer, bufferSize);

    //recv = socket.recv(buffer, bufferSize);
    //std::cout << buffer << std::endl;

    std::string body;
    for(int i=0; i<recv; i++)
    {
        if(buffer[i] == '\0')
        {
            break;
        }

        body += buffer[i];
    }
    std::cout << body << std::endl;
    //socket.close();

}
