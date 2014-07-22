#pragma once
#include "Item.h"
#include "EventThrower.h"
namespace StiGame
{

namespace Gui
{

/// \class Button
/// \brief Classic button that throw an event on clicking
class Button :
	public Item,
	public EventThrower
{
public:
	/// \brief Default Text Offset
	static const int DEFAULT_OFFSET = 4;
	/// \brief Create a new Button
	Button(void);
	/// \brief Destructor
	virtual ~Button(void);
	/// \brief Get Button Text Caption
	/// \return String value
	char* getCaption(void);
	/// \brief Set Button Text Caption
	/// \param m_caption Text Caption
	void setCaption(char* m_caption);
	/// \brief Render the Button
	/// \return Rendered Button
	virtual Surface* render(void);
	/// \brief Clear memory
	void clear(void);
	/// \brief On Click Event
	/// \param relp Relative mouse position
	void onClick(Point *relp);
protected:
	/// \brief Auto Size Button Dimension
	void autosize(void);
	/// \brief Render Text Caption
	void renderCaption(void);
	/// \brief Caption Buffer
	Surface *stringBuffer;
	/// \brief Text Caption
	char* caption;
	/// \brief Offset Width
	int offsetWidth;
	/// \brief Offset Height
	int offsetHeight;
	/// \brief Highlight Foreground Color
	Color *highlightForeground;
	/// \brief Highlight Background Color
	Color *highlightBackground;
};

}

}
