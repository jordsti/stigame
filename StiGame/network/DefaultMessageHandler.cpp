#include "DefaultMessageHandler.h"
#include "PacketStream.h"
#include <iostream>
namespace StiGame
{

namespace Net
{

DefaultMessageHandler::DefaultMessageHandler()
{
    dispatcher = nullptr;
}

DefaultMessageHandler::~DefaultMessageHandler()
{

}

void DefaultMessageHandler::readPacket(UdpPacket *packet)
{
    PacketStream stream = packet->stream();

    std::string message = stream.readString();
    std::cout << "Message received : " <<  message << std::endl;

    if(message == "QUIT")
    {
        //closing the dispatcher
        if(dispatcher != nullptr)
        {
            dispatcher->stop();
        }
    }

    if(dispatcher != nullptr)
    {
        UdpPacket *resp = new UdpPacket();
        resp->stream().writeString("Hello ! from the dispatcher");
        resp->applyAddress(packet->ipAddress());
        dispatcher->sendPacket(resp);
    }
}

}

}
