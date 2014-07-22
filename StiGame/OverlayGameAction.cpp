#include "OverlayGameAction.h"
#include "KeyActionMap.h"
#include "OverlayMenu.h"

#include <iostream>

namespace StiGame
{

BaseGameAction* OverlayGameAction::GetDefaultOverlayGameAction(BaseGameState *m_state)
{
	OverlayGameAction *action = new OverlayGameAction();
	KeyActionMap *kmap = new KeyActionMap("open_overlay", SDLK_ESCAPE);
	action->setActionMap(kmap);
	action->setState(m_state);

	return action;
}


OverlayGameAction::OverlayGameAction()
{
	initialize();
	name = "open_overlay";
}

OverlayGameAction::~OverlayGameAction()
{

}

void OverlayGameAction::setState(BaseGameState *m_state)
{
	state = m_state;
}

BaseGameState* OverlayGameAction::getState(void)
{
	return state;
}

void OverlayGameAction::doAction(void)
{
    std::cout << "OVERLAY ACTION" << std::endl;

	Gui::OverlayMenu *gameMenu = state->getGameMenu();
	if(gameMenu == 0)
	{
		return;
	}

	if(!gameMenu->isVisible())
	{
		state->openGameMenu();
	}
}


}
