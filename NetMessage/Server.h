#ifndef SERVER_H
#define SERVER_H
#include "NetMessageTask.h"
class Server :
        public NetMessageTask
{
public:
    Server();
    virtual ~Server();


    void execute(void);
};

#endif // SERVER_H
