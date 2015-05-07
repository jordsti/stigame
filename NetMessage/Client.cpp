#include "Client.h"
#include "UdpSocket.h"
#include <iostream>
#include "PacketStream.h"
Client::Client()
{

}

Client::~Client()
{

}

void Client::execute(void)
{
    StiGame::Net::UdpSocket socket;
    IPaddress addr;
    socket.open(0);
    SDLNet_ResolveHost(&addr, "127.0.0.1", 7070);

    int channel = socket.bind(-1, &addr);
    int i=0;
    std::cout << "Opening connection on channel : " << channel << std::endl;

    while(true)
    {
        //bombing with message
        StiGame::Net::UdpPacket packet (128);
        StiGame::Net::PacketStream stream = packet.stream();

        std::string message = "Hello Its me !";
        //packet.setString(message);
        packet.applyAddress(&addr);

        stream.writeString(message);
        stream.writeInt32(i);

        socket.send(packet.packet(), channel);
        std::cout << "Message sended" << std::endl;

        StiGame::Net::UdpPacket *answer = socket.recv();

        if(answer != nullptr)
        {
            StiGame::Net::PacketStream astream = answer->stream();
            std::string resp = astream.readString();
            std::cout << resp << std::endl;
            delete answer;
        }
        i++;
        SDL_Delay(2000);
    }
}
