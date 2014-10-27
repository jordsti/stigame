#ifndef ACTIONBIND_H
#define ACTIONBIND_H

#include "Font.h"
#include "HighlightItem.h"
#include "KeyEventListener.h"
#include "MouseButtonEventListener.h"
#include "CompActionMap.h"
namespace StiGame
{

namespace Gui
{

/// \class ActionBind
/// \brief Gui Item to catch an action like a Key Down or Mouse Button Down
class ActionBind :
	public HighlightItem,
	public KeyEventListener,
	public MouseButtonEventListener
{
public:
	/// \brief Default Width (px)
	static const int DefaultWidth;
	/// \brief Default Height (px)
	static const int DefaultHeight;
	/// \brief Constructor
	ActionBind();
	/// \brief Destructor
	virtual ~ActionBind();
	/// \brief Render the Item
	/// \return Rendered Surface
	Surface* render(void);
	/// \brief Handle Key event
	/// \param src Source
	/// \param args Key Event Argument
	void handleEvent(KeyEventThrower *src, KeyEventArgs *args);
	/// \brief Handle Mouse Button event
	/// \param src Source
	/// \param args Mouse Button Event Argument
	void handleEvent(MouseButtonEventThrower *src, MouseButtonEventArgs *args);
	//void onClick(Point *relpt);
	/// \brief Get current Keycode
	/// \return Keycode
	SDL_Keycode getKey(void);
	/// \brief Set current Keycode
	/// \param m_keycode Keycode
	void setKey(SDL_Keycode m_keycode);
	/// \brief Get current Mouse Button
	/// \return Mouse Button
	MouseButton getMouseButton(void);
	/// \brief Set current Mouse Button
	/// \param m_mbutton Mouse Button
	void setMouseButton(MouseButton m_mbutton);
	/// \brief Is the action is a Mouse Button
	/// \return Is Mouse Button
	bool isMouseButton(void);
	/// \brief Is the Item is handling Mouse Button
	/// \return Is Mouse Handled
	bool isHandleMouse(void);
	/// \brief Set if the item should catch Mouse Button Event
	/// \param m_handleMouse Handle Mouse
	void setHandleMouse(bool m_handleMouse);
	/// \brief Get the drawing Text Font
	/// \return Text Font
	Font* getFont(void);
	/// \brief Set the Item Text Font
	/// \param m_font Text Font
	void setFont(Font *m_font);
	/// \brief Define the Action Bind from an ActionMap
	/// \param amap Action Map
	void fromActionMap(ActionMap *amap);
	/// \brief Define the Action Bind from a Composite Action Map
	/// \param cmap Composite Action Map
	/// \param index Index
	void fromActionMap(CompActionMap *cmap, int index);
	/// \brief Create an Action Map fron this Item
	/// \return Action Map
	ActionMap* createActionMap(std::string a_name);
	/// \brief Get string value of a Mouse Button
	/// \param mbutton Mouse Button
	/// \return String value
	static std::string GetMouseString(MouseButton mbutton);
protected:
	/// \brief Keycode
	SDL_Keycode keycode;
	/// \brief Mouse Button
	MouseButton mbutton;
	/// \brief Is the action a Mouse Button
	bool mouseButton;
	/// \brief Is the item handle Mouse Button Event
	bool handleMouse;
	/// \brief Is the Item is focused
	bool focus;
	/// \brief Text Font
	Font *font;
	/// \brief String Surface Buffer
	Surface *stringBuffer;
	/// \brief Render Text Caption
	void renderCaption(void);

};

}

}

#endif
