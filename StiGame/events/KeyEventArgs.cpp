#include "KeyEventArgs.h"
#include <iostream>

namespace StiGame
{

KeyEventArgs::KeyEventArgs(SDL_Event *evt) : EventArgs(evt)
{
    //ctor
    //todo
    if(evt->key.type == SDL_KEYUP)
    {
        state = KS_UP;
    }
    else if(evt->key.type == SDL_KEYDOWN)
    {
        state = KS_DOWN;
    }

}

SDL_KeyboardEvent *KeyEventArgs::getKeyboardEvent(void)
{
    return &sdlEvent->key;
}

char KeyEventArgs::getUnicode(void)
{
    return (char)sdlEvent->key.keysym.sym;
}

KeyState KeyEventArgs::getState(void)
{
    return state;
}

std::string KeyEventArgs::getKeyName(void)
{
    const char *keyname = SDL_GetKeyName(sdlEvent->key.keysym.sym);

    return std::string(keyname);
}

KeyEventArgs::~KeyEventArgs()
{
    //dtor
}

}
