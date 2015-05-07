#include "MessageDispatcher.h"
#include <iostream>
#include "UdpSocket.h"
#include "PacketStream.h"
#include "DefaultMessageHandler.h"

namespace StiGame
{

namespace Net
{

MessageHandler* MessageDispatcher::DEFAULT_HANDLER = new DefaultMessageHandler();

MessageDispatcher::MessageDispatcher()
{
    running = false;
    delay = DEFAULT_DELAY;
    sendingThread = nullptr;
    receivingThread = nullptr;
    listeningPort = DEFAULT_LISTENING_PORT;
    handler = DEFAULT_HANDLER;
    lockSendQueue = false;
}

MessageDispatcher::MessageDispatcher(unsigned int m_listeningPort)
{
    running = false;
    delay = DEFAULT_DELAY;
    sendingThread = nullptr;
    receivingThread = nullptr;
    listeningPort = m_listeningPort;
    handler = DEFAULT_HANDLER;
    lockSendQueue = false;
}

MessageDispatcher::~MessageDispatcher()
{

}

void MessageDispatcher::setListeningPort(unsigned int m_listeningPort)
{
    listeningPort = m_listeningPort;
}

void MessageDispatcher::start(void)
{
    if(!running)
    {
        running = true;
        createThreads();
    }
}

void MessageDispatcher::stop(void)
{
    if(running)
    {
        running = false;
    }
}

bool MessageDispatcher::isRunning(void)
{
    return running;
}

void MessageDispatcher::setDelay(int m_delay)
{
    delay = m_delay;
}

int MessageDispatcher::getDelay(void)
{
    return delay;
}

unsigned short MessageDispatcher::getListeningPort(void)
{
    return listeningPort;
}

void MessageDispatcher::setHandler(MessageHandler *m_handler)
{
    handler = m_handler;
}

MessageHandler* MessageDispatcher::getHandler(void)
{
    return handler;
}


void MessageDispatcher::sendPacket(UdpPacket *packet)
{
    while(lockSendQueue)
    {
        SDL_Delay(delay);
    }

    lockSendQueue = true;
    toSend.push(packet);
    lockSendQueue = false;
}

void MessageDispatcher::lockSend(void)
{
    while(lockSendQueue)
    {
        SDL_Delay(delay);
    }

    lockSendQueue = true;
}

void MessageDispatcher::unlockSend(void)
{
    lockSendQueue = false;
}

UdpPacket* MessageDispatcher::popToSend(void)
{
    if(toSend.size() > 0)
    {
        UdpPacket *packet = toSend.front();
        toSend.pop();
        return packet;
    }

    return nullptr;
}

void MessageDispatcher::createThreads(void)
{
    receivingThread = new Thread(&StiGame_Net_ReceiveMessage, "receiving thread", this);
    sendingThread = new Thread(&StiGame_Net_SendMessage, "sending thread", this);
}

}

}

int StiGame_Net_SendMessage(void *data_ptr)
{
    StiGame::Net::MessageDispatcher *dispatcher = static_cast<StiGame::Net::MessageDispatcher*>(data_ptr);
    int delay = dispatcher->getDelay();

    StiGame::Net::UdpSocket socket;
    socket.open(0);

    while(dispatcher->isRunning())
    {
        dispatcher->lockSend();

        StiGame::Net::UdpPacket *toSend = dispatcher->popToSend();

        if(toSend != nullptr)
        {
            IPaddress addr;
            toSend->copyAddress(&addr);
            int channel = socket.bind(-1, &addr);
            if(channel != -1)
            {
                socket.send(toSend->packet(), channel);
                socket.unbind(channel);
                delete toSend;
            }
            else
            {
                //repush the packet into to send
                dispatcher->sendPacket(toSend);
            }
        }

        dispatcher->unlockSend();

        SDL_Delay(delay);
    }

    socket.close();

    return 1;
}

int StiGame_Net_ReceiveMessage(void *data_ptr)
{
    StiGame::Net::MessageDispatcher *dispatcher = static_cast<StiGame::Net::MessageDispatcher*>(data_ptr);
    StiGame::Net::MessageHandler *handler = dispatcher->getHandler();
    int delay = dispatcher->getDelay();
    unsigned short port = dispatcher->getListeningPort();

    StiGame::Net::UdpSocket socket;
    socket.open(port);
    while(dispatcher->isRunning())
    {
        StiGame::Net::UdpPacket *packet = socket.recv();

        if(packet != nullptr)
        {
            handler->readPacket(packet);
            delete packet;
        }

        SDL_Delay(delay);
    }

    socket.close();

    return 1;
}
