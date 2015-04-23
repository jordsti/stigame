#ifndef OVERLAYGAMEACTION_H
#define OVERLAYGAMEACTION_H

#include "BaseGameAction.h"
#include "BaseGameState.h"


namespace StiGame
{


/// \class OverlayGameAction
/// \brief Action that show an overlay menu when the specified key is pressed
class OverlayGameAction :
	public BaseGameAction
{
public:
    /// \brief Constructor
	OverlayGameAction();
    /// \brief Destructor
	virtual ~OverlayGameAction();
    /// \brief Set Affected State
    /// \param m_state State
	void setState(BaseGameState *m_state);
    /// \brief Get Affected State
    /// \return State
    BaseGameState* getState(void);
    /// \brief Get an instance of the Default Game Overlay Action
    /// \param m_state Affected State
    /// \return Overlay Game Action
	static BaseGameAction* GetDefaultOverlayGameAction(BaseGameState *m_state);
protected:
    /// \brief Overrided method that show the menu
	void doAction(void);
    /// \brief Affected State
	BaseGameState *state;

};

}

#endif
