#ifndef TIMEDGAMEACTION_H
#define TIMEDGAMEACTION_H
#include "BaseGameAction.h"

namespace StiGame
{


class TimedGameAction :
    public BaseGameAction
{
    public:
        TimedGameAction();
        virtual ~TimedGameAction();

        void testKeycode(SDL_Keycode keycode);
        void testMouse(Uint8 button);
        void testMouseButton(MouseButtonEventArgs *mbEvt);

        int getCooldown(void);
        unsigned long long getLastAction(void);

    protected:
        //pure virtual!
        virtual void doAction(void) = 0;

    private:
        int cooldown;
        unsigned long long lastAction;
};

}

#endif // TIMEDGAMEACTION_H
