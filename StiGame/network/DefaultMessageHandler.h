#ifndef DEFAULTMESSAGEHANDLER_H
#define DEFAULTMESSAGEHANDLER_H

#include "MessageDispatcher.h"
#include "MessageHandler.h"

namespace StiGame
{

namespace Net
{

class DefaultMessageHandler:
        public MessageHandler
{
public:
    DefaultMessageHandler();
    virtual ~DefaultMessageHandler();

    void readPacket(UdpPacket *packet);

    MessageDispatcher *dispatcher;
};

}

}
#endif // DEFAULTMESSAGEHANDLER_H
