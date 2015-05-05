#include <iostream>
#include <string>
#include "Server.h"
#include "Client.h"
#include "SDL_net.h"
#include "HTTPTest.h"
int main(int argc, char ** argv)
{
    SDL_Init(0);
    if(SDLNet_Init() == -1)
    {
        std::cout << SDLNet_GetError() << std::endl;
    }
    NetMessageTask *task = nullptr;
    std::cout << "NetMessage StiGame " << std::endl;
    int ia = 0;

    while(ia < argc)
    {
        if(ia > 0)
        {
            std::string arg (argv[ia]);

            if(arg == "server")
            {
                task = new Server();
            }
            else if(arg == "client")
            {
                task = new Client();
            }
            else if(arg == "http")
            {
                task = new HTTPTest();
            }
        }

        ia++;
    }

    if(task != nullptr)
    {
        task->execute();
    }
    else
    {
        std::cout << "No Task specified" << std::endl;
    }

	return 0;
}
