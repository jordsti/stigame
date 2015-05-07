#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H
#include "UdpPacket.h"
namespace StiGame
{

namespace Net
{

class MessageDispatcher;

class MessageHandler
{
public:
    MessageHandler();
    virtual ~MessageHandler();
    virtual void readPacket(UdpPacket *packet) = 0;
};

}

}

#endif // MESSAGEHANDLER_H
