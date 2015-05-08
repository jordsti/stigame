#ifndef THREAD_H
#define THREAD_H
#include "SDL.h"
#include <string>

namespace StiGame {

class Thread
{
public:
    Thread(SDL_ThreadFunction fn, std::string m_name, void *m_data_ptr);
    virtual ~Thread();

    SDL_Thread* getSDLThread(void);

    int getId(void);
    std::string getName(void);
    int wait(void);
    void detach(void);
    void setPriority(SDL_ThreadPriority m_priority);
private:
    void *data_ptr;
    SDL_Thread *_thread;
};

}

#endif // THREAD_H
