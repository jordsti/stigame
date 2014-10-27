#pragma once
#include "Item.h"
#include "EventThrower.h"

namespace StiGame
{

namespace Gui
{

/// \class ImageButton
/// \brief A Gui Button that use Image for rendering
class ImageButton :
	public Item,
	public EventThrower
{
public:
	/// \brief Default Offset
	static const int DEFAULT_OFFSET = 4;
	/// \brief Create a new Image Button
	ImageButton(void);
	/// \brief Destructor
	~ImageButton(void);
	/// \brief Autosize the button
	void autosize(void);
	/// \brief Get Button Image
	/// \return Surface
	Surface *getImage(void);
	/// \brief Get Hover Button Image
	/// \return Surface
	Surface *getImageHover(void);
	/// \brief Set the Button Image
	/// \param m_image Image
	void setImage(Surface *m_image);
	/// \brief Set the Hover Button Image
	/// \param m_imageHover Image
	void setImageHover(Surface *m_imageHover);
	/// \brief Render the Image Button
	/// \return Rendered Item
	virtual Surface *render(void);
	/// \brief Clear the item
	void clear(void);
	/// \brief On Click event
	/// \param relp Relative mouse position
	void onClick(Point *relp);

protected:
	/// \brief Highlight Foreground Color
	Color *highlightForeground;
	/// \brief Highlight Background Color
	Color *highlightBackground;
	/// \brief Button Image
	Surface *image;
	/// \brief Hover Button Image
	Surface *imageHover;
	/// \brief Offset Width
	int offsetWidth;
	/// \brief Offset Height
	int offsetHeight;
};

}

}

