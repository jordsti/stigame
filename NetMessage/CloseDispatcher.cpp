#include "CloseDispatcher.h"
#include "UdpSocket.h"
#include "PacketStream.h"
#include <iostream>
CloseDispatcher::CloseDispatcher()
{

}

CloseDispatcher::~CloseDispatcher()
{

}

void CloseDispatcher::execute(void)
{
    StiGame::Net::UdpSocket socket;
    IPaddress addr;
    socket.open(0);
    SDLNet_ResolveHost(&addr, "127.0.0.1", 7070);

    int channel = socket.bind(-1, &addr);
    int i=0;
    std::cout << "Opening connection on channel : " << channel << std::endl;
    std::cout << "Sending a QUIT message" << std::endl;
    //sending a QUIT message

    StiGame::Net::UdpPacket packet (64);
    packet.stream().writeString("QUIT");

    packet.applyAddress(&addr);

    socket.send(packet.packet(), channel);
    socket.unbind(channel);
    socket.close();
}
