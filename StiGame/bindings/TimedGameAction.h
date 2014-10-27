#ifndef TIMEDGAMEACTION_H
#define TIMEDGAMEACTION_H
#include "BaseGameAction.h"

namespace StiGame
{


class TimedGameAction :
    public BaseGameAction
{
    public:
        virtual ~TimedGameAction();

        void testKeycode(SDL_Keycode keycode);
        void testMouse(Uint8 button);
        void testMouseButton(MouseButtonEventArgs *mbEvt);

        int getCooldown(void);
        long long getLastAction(void);

    protected:
        TimedGameAction();
        //pure virtual!
        virtual void doAction(void) = 0;
        int cooldown;
    private:

        long long lastAction;
};

}

#endif // TIMEDGAMEACTION_H
