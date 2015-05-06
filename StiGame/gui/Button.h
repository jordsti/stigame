#pragma once
#include "HighlightItem.h"
#include "EventThrower.h"
#include "CaptionSupport.h"
namespace StiGame
{

namespace Gui
{

/// \class Button
/// \brief Classic button that throw an event on clicking
class Button :
    public HighlightItem,
    public EventThrower,
    public CaptionSupport
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
	std::string getCaption(void);
	/// \brief Set Button Text Caption
	/// \param m_caption Text Caption
	void setCaption(std::string m_caption);
	/// \brief Render the Button
	/// \return Rendered Button
	virtual Surface* render(void);

	/// \brief On Click Event
	/// \param relp Relative mouse position
	void onClick(Point *relp);

    void setFont(Font *m_font);

    void setHighlightForeground(Color *m_highlightForeground);
protected:
	/// \brief Auto Size Button Dimension
	void autosize(void);
    StringRenderer highlightRenderer;
	/// \brief Text Caption
	std::string caption;
	/// \brief Offset Width
	int offsetWidth;
	/// \brief Offset Height
	int offsetHeight;
};

}

}
