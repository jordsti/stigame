#include "TimedGameAction.h"
#include "TimeTools.h"
namespace StiGame
{

TimedGameAction::TimedGameAction()
{
    //ctor
    initialize();
    cooldown = 0;
    lastAction = 0;
}

int TimedGameAction::getCooldown(void)
{
    return cooldown;
}

long long TimedGameAction::getLastAction(void)
{
    return lastAction;
}

void TimedGameAction::testKeycode(SDL_Keycode keycode)
{
    if(actionMap->inputEquals(IT_KEYBOARD, keycode))
    {
        long long nextAction = lastAction + cooldown;
        long long timestamp = Time::GetMsTimestamp();

        if(nextAction <= timestamp)
        {
            //we can do the action
            lastAction = timestamp;
            doAction();
        }
    }
}


void TimedGameAction::testMouseButton(MouseButtonEventArgs *mbEvt)
{
    if(actionMap->isPositionChecked())
    {
        if(actionMap->inputMouseEquals(mbEvt))
        {
            unsigned long long nextAction = lastAction + cooldown;
            unsigned long long timestamp = Time::GetMsTimestamp();

            if(nextAction <= timestamp)
            {
            //we can do the action
                lastAction = timestamp;
                doAction();
            }
        }
    }
    else
    {
        if(actionMap->inputEquals(IT_MOUSE, mbEvt->getButton()))
        {
            unsigned long long nextAction = lastAction + cooldown;
            unsigned long long timestamp = Time::GetMsTimestamp();

            if(nextAction <= timestamp)
            {
            //we can do the action
                lastAction = timestamp;
                doAction();
            }
        }
    }
}

void TimedGameAction::testMouse(Uint8 mbutton)
{
    if(actionMap->inputEquals(IT_MOUSE, mbutton))
    {
        unsigned long long nextAction = lastAction + cooldown;
        unsigned long long timestamp = Time::GetMsTimestamp();

        if(nextAction <= timestamp)
        {
            //we can do the action
            lastAction = timestamp;
            doAction();
        }
    }
}

TimedGameAction::~TimedGameAction()
{
    //dtor
}

}
