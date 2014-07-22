#ifndef BASEGAMEACTION_H
#define BASEGAMEACTION_H

#include <string>
#include "ActionMap.h"

namespace StiGame
{


class BaseGameAction
{
    public:
        BaseGameAction();
        virtual ~BaseGameAction();

        virtual void testKeycode(SDL_Keycode keycode);
        virtual void testMouse(Uint8 button);
        virtual void testMouseButton(MouseButtonEventArgs *mbEvt);
        std::string getName(void);
        ActionMap* getActionMap(void);
        void setActionMap(ActionMap *m_actionMap);
    protected:
        void initialize(void);
        std::string name;
        ActionMap *actionMap;

        virtual void doAction(void) = 0;
    private:
};

}

#endif // BASEGAMEACTION_H
