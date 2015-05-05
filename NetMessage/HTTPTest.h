#ifndef HTTPTEST_H
#define HTTPTEST_H
#include "NetMessageTask.h"
class HTTPTest :
        public NetMessageTask
{
public:
    HTTPTest();
    virtual ~HTTPTest();

    void execute(void);
};

#endif // HTTPTEST_H
