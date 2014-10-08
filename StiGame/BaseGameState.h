#pragma once
#include "SDL.h"
#include "KeyEventThrower.h"
#include "MouseButtonEventThrower.h"
#include "MouseMotionEventThrower.h"
#include "MouseWheelEventThrower.h"
#include "ControllerAxisEventThrower.h"
#include "ControllerButtonEventThrower.h"
#include "ControllerDeviceEventThrower.h"
#include "BaseGameAction.h"
#include "ActionBinding.h"
#include "OverlayMenu.h"
#include "OverlayFrame.h"
#include <list>
#include <set>

namespace StiGame
{
class Viewport;

/// \class BaseGameState
/// \brief Base class to inherite when you want to create a custom state
class BaseGameState :
    public KeyEventThrower,
	public MouseButtonEventThrower,
	public MouseMotionEventThrower,
	public MouseWheelEventThrower,
	public ControllerAxisEventThrower,
	public ControllerButtonEventThrower,
	public ControllerDeviceEventThrower
{
public:
	/// \brief Create a new GameState
	BaseGameState(void);
	/// \brief Destructor
	~BaseGameState(void);
	/// \brief Virtual method to override
	/// Called when the state is pushed
	virtual void onStart(void);
	/// \brief Virtual method to override
	/// Called at each tick for drawing
	/// \param screen Screen surface
	virtual void onPaint(SDL_Renderer *renderer);
	/// \brief Virtual method to override
	/// Called when the viewport is resized and called before onStart, to specify the viewport size
	/// \param m_width width (px)
	/// \param m_height height (px)
	virtual void onResize(int m_width,int m_height);
	/// \brief Virtual method to override
	/// Called when the user try to quit by using the X button
	/// \param evt SDL_Event pointer
	virtual void onQuit(SDL_Event *evt);
	/// \brief Virtual method to override
	/// Called for each SDL_Event throwed
	/// \param evt SDL_Event pointer
	virtual void onEvent(SDL_Event *evt);

	/// \brief Virtual method to override
	/// Called when the state is quiting or replacing
	virtual void unload(void);
	/// \brief Get running value
	/// \return running or not
	bool isRunning(void);
	/// \brief Set viewport pointer
	/// \param m_viewport viewport pointer
	void setViewport(Viewport *m_viewport);
	/// \brief Get viewport pointer
	/// \return viewport pointer
	Viewport* getViewport(void);

	bool isHandleQuit(void);

	void openGameMenu(void);
	void closeGameMenu(void);

	void setGameMenu(Gui::OverlayMenu *m_gameMenu);
	Gui::OverlayMenu* getGameMenu(void);

protected:
    void clearActions(void);

    void tickActions(void);

    void renderOverlayFrames(SDL_Renderer *renderer);
    void renderGameMenu(SDL_Renderer *renderer);

	/// \brief width (px)
	int width;
	/// \brief height (px)
	int height;
	/// \brief running
	bool running;
	/// \brief viewport pointer
	Viewport *viewport;

	bool handleQuit;
    std::list<BaseGameAction*> actions;
    ActionBinding bindings;
	Gui::OverlayMenu *gameMenu;

	std::list<Gui::OverlayFrame*> frames;

private:
    std::set<SDL_Keycode> keyDowns;
    std::set<Uint8> mouseButtons;
};

}
