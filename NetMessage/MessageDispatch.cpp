#include "MessageDispatch.h"
#include "MessageDispatcher.h"
#include "DefaultMessageHandler.h"
MessageDispatch::MessageDispatch()
{

}

MessageDispatch::~MessageDispatch()
{

}

void MessageDispatch::execute(void)
{
    StiGame::Net::MessageDispatcher dispatcher;
    StiGame::Net::DefaultMessageHandler *handler = dynamic_cast<StiGame::Net::DefaultMessageHandler*>(dispatcher.getHandler());
    handler->dispatcher = &dispatcher;
    dispatcher.start();

    while(dispatcher.isRunning())
    {
        SDL_Delay(100);
    }
}
