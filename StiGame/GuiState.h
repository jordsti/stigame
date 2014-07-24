#pragma once
#include "Viewport.h"
#include "Runtime.h"
#include "Item.h"
#include <list>
namespace StiGame
{

namespace Gui
{

/// \class GuiState
/// \brief Class that provide a base implementation for Gui item rendering
class GuiState : public BaseGameState
{
public:
    /// \brief Constructor
	GuiState(void);
	/// \brief Destructor
	~GuiState(void);
	/// \brief Add a GuiItem
	/// \param item GuiItem to add
	void add(Item *item);
	/// \brief Starting the state
	void onStart(void);
	/// \brief Paint Event
	/// \param renderer SDL_Renderer
	virtual void onPaint(SDL_Renderer *renderer);
	/// \brief Resize Event
	/// \param m_width New Width
	/// \param m_height New Height
	virtual void onResize(int m_width,int m_height);
	/// \brief Quit Event
	/// \param evt SDL_Event
	virtual void onQuit(SDL_Event *evt);
	/// \brief Event Handling
	/// \param evt SDL_Event
	virtual void onEvent(SDL_Event *evt);
	/// \brief Freeing ressources
	virtual void unload(void);
	/// \brief Get mouse x position
	/// \return mouse x (px)
	int getMouseX(void);
    /// \brief Get mouse y position
	/// \return mouse y (px)
	int getMouseY(void);
protected:
	/// \brief GuiItem list
	std::list<Item*> items;
	/// \brief Is rendering
	bool rendering;
	/// \brief Surface Buffer
	Surface *sBuffer;
	/// \brief Mouse X Position
	int mouse_x;
	/// \brief Mouse Y Position
	int mouse_y;
	/// \brief Gui Style
	Style *style;
};

}
}
