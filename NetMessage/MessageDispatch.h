#ifndef MESSAGEDISPATCH_H
#define MESSAGEDISPATCH_H
#include "NetMessageTask.h"
class MessageDispatch :
        public NetMessageTask
{
public:
    MessageDispatch();
    virtual ~MessageDispatch();

    void execute(void);
};

#endif // MESSAGEDISPATCH_H
