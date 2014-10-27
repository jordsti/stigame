#ifndef CHECKEVENTLISTENER_H
#define CHECKEVENTLISTENER_H

#include "CheckEventArgs.h"

namespace StiGame
{
class CheckEventThrower;

class CheckEventListener
{
    public:
        CheckEventListener();
        virtual ~CheckEventListener();
        virtual void handleEvent(CheckEventThrower *src, CheckEventArgs *args);
    protected:
    private:
};
}
#endif // CHECKEVENTLISTENER_H

