#ifndef CLOSEDISPATCHER_H
#define CLOSEDISPATCHER_H

#include "NetMessageTask.h"

class CloseDispatcher :
        public NetMessageTask
{
public:
    CloseDispatcher();
    virtual ~CloseDispatcher();

    void execute(void);
};

#endif // CLOSEDISPATCHER_H
