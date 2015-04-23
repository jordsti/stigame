#ifndef TIMEDGAMEACTION_H
#define TIMEDGAMEACTION_H
#include "BaseGameAction.h"

namespace StiGame
{

/// \class TimedGameAction
/// \brief Game Action with a cooldown timer
class TimedGameAction :
    public BaseGameAction
{
    public:
        /// \brief Destructor
        virtual ~TimedGameAction();

        void testKeycode(SDL_Keycode keycode);
        void testMouse(Uint8 button);
        void testMouseButton(MouseButtonEventArgs *mbEvt);

        /// \brief Get the cooldown
        /// \return Cooldown time (ms)
        int getCooldown(void);
        /// \brief Get the Last Timestamp when doAction was called
        /// \return Timestamp
        long long getLastAction(void);

    protected:
        /// \brief Constructor
        TimedGameAction();
        //pure virtual!
        virtual void doAction(void) = 0;
        ///  \brief Action Cooldown (ms)
        int cooldown;
    private:
        /// \brief Last time when doAction was called
        long long lastAction;
};

}

#endif // TIMEDGAMEACTION_H
