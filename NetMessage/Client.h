#ifndef CLIENT_H
#define CLIENT_H
#include "NetMessageTask.h"
class Client :
        public NetMessageTask
{
public:
    Client();
    virtual ~Client();

    void execute(void);
};

#endif // CLIENT_H
