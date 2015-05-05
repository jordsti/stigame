#include "Server.h"
#include "UdpSocket.h"
#include <string>
#include <iostream>
#include "PacketStream.h"
Server::Server()
{
}

Server::~Server()
{

}

void Server::execute()
{
    StiGame::Net::UdpSocket socket;
    socket.open(9000);

    while(true)
    {
        StiGame::Net::UdpPacket *packet = socket.recv();

        if(packet != nullptr)
        {
            StiGame::Net::PacketStream stream = packet->stream();
            std::cout << "Message Received : " << stream.readString() << std::endl;
            IPaddress remote;
            remote.host = packet->ipAddress()->host;
            remote.port = packet->ipAddress()->port;

            StiGame::Net::UdpPacket resp;
            StiGame::Net::PacketStream respStream = resp.stream();
            respStream.writeString("Received");

            int channel = socket.bind(-1, &remote);
            if(channel != -1)
            {
                socket.send(resp.packet(), channel);
                socket.unbind(channel);
            }

            delete packet;
        }
        /*else
        {
            std::cout << "No packet received" << std::endl;
        }*/
        SDL_Delay(5);
    }
}
