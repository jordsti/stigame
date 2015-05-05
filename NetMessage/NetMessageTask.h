#ifndef NETMESSAGETASK_H
#define NETMESSAGETASK_H

class NetMessageTask
{
public:
    NetMessageTask();
    virtual ~NetMessageTask();

    virtual void execute(void) = 0;
};

#endif // NETMESSAGETASK_H
