#include "SGThread.h"
namespace StiGame {

Thread::Thread(SDL_ThreadFunction fn, std::string m_name, void *m_data_ptr)
{
    data_ptr = m_data_ptr;
    _thread = SDL_CreateThread(fn, m_name.c_str(), m_data_ptr);
}

Thread::~Thread()
{
    delete _thread;
}

SDL_Thread* Thread::getSDLThread(void)
{
    return _thread;
}

int Thread::getId(void)
{
    return SDL_GetThreadID(_thread);
}

std::string Thread::getName(void)
{
    return std::string(SDL_GetThreadName(_thread));
}

int Thread::wait(void)
{
    int status = 0;
    SDL_WaitThread(_thread, &status);
    return status;
}

void Thread::detach(void)
{
#ifndef __MINGW32__
    SDL_DetachThread(_thread);
#endif
}

void Thread::setPriority(SDL_ThreadPriority m_priority)
{
    SDL_SetThreadPriority(m_priority);
}

}
