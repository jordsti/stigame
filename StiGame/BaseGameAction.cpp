#include "BaseGameAction.h"
namespace StiGame
{

BaseGameAction::BaseGameAction()
{
    //ctor
    initialize();

}

void BaseGameAction::initialize(void)
{
    name = "none";
    actionMap = 0;
}

std::string BaseGameAction::getName(void)
{
    return name;
}

ActionMap* BaseGameAction::getActionMap(void)
{
    return actionMap;
}

void BaseGameAction::setActionMap(ActionMap *m_actionMap)
{
    actionMap = m_actionMap;
}

void BaseGameAction::testMouseButton(MouseButtonEventArgs *mbEvt)
{
    if(actionMap->isPositionChecked())
    {
        if(actionMap->inputMouseEquals(mbEvt))
        {
            doAction();
        }
    }
    else
    {
        if(actionMap->inputEquals(IT_MOUSE, mbEvt->getButton()))
        {
            doAction();
        }
    }
}

void BaseGameAction::testMouse(Uint8 button)
{
    if(actionMap->isInput(IT_MOUSE))
    {
        if(actionMap->inputEquals(IT_MOUSE, button))
        {
            doAction();
        }
    }
}

void BaseGameAction::testKeycode(SDL_Keycode keycode)
{
    if(actionMap->isInput(IT_KEYBOARD))
    {
        if(actionMap->inputEquals(IT_KEYBOARD, keycode))
        {
            doAction();
        }
    }

}

BaseGameAction::~BaseGameAction()
{
    //dtor
}

}
