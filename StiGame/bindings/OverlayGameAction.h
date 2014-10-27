#ifndef OVERLAYGAMEACTION_H
#define OVERLAYGAMEACTION_H

#include "BaseGameAction.h"
#include "BaseGameState.h"


namespace StiGame
{



class OverlayGameAction :
	public BaseGameAction
{
public:
	OverlayGameAction();
	virtual ~OverlayGameAction();

	void setState(BaseGameState *m_state);
	BaseGameState* getState(void);

	static BaseGameAction* GetDefaultOverlayGameAction(BaseGameState *m_state);
protected:
	void doAction(void);
	BaseGameState *state;

};

}

#endif
