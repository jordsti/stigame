#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H
#include "SGThread.h"
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
    MessageDispatcher(unsigned int m_listeningPort);
    MessageDispatcher();
    virtual ~MessageDispatcher();

    virtual void start(void);

    virtual void stop(void);

    bool isRunning(void);

    int getDelay(void);
    void setDelay(int m_delay);

    unsigned short getListeningPort(void);
    void setListeningPort(unsigned int m_listeningPort);

    virtual void setHandler(MessageHandler *m_handler);
    virtual MessageHandler* getHandler(void);

    virtual void sendPacket(UdpPacket *packet);

    virtual void lockSend(void);
    virtual void unlockSend(void);

    virtual UdpPacket* popToSend(void);
private:
    virtual void createThreads(void);

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
