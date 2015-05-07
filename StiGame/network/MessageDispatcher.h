#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H
#include "Thread.h"
#include "MessageHandler.h"
#include <queue>
namespace StiGame
{

namespace Net
{

class MessageDispatcher
{
public:
    const static int DEFAULT_DELAY = 5;
    const static unsigned short DEFAULT_LISTENING_PORT = 7070;
    static MessageHandler * DEFAULT_HANDLER;
    MessageDispatcher();
    virtual ~MessageDispatcher();

    void start(void);

    void stop(void);

    bool isRunning(void);

    int getDelay(void);

    unsigned short getListeningPort(void);

    void setHandler(MessageHandler *m_handler);
    MessageHandler* getHandler(void);

    void sendPacket(UdpPacket *packet);

    void lockSend(void);
    void unlockSend(void);

    UdpPacket* popToSend(void);
private:
    bool lockSendQueue;
    std::queue<UdpPacket*> toSend;
    MessageHandler *handler;
    unsigned short listeningPort;
    bool running;
    int delay;

    Thread *sendingThread;
    Thread *receivingThread;
};

}

}

int StiGame_Net_ReceiveMessage(void *data_ptr);
int StiGame_Net_SendMessage(void *data_ptr);

#endif // MESSAGEDISPATCHER_H
