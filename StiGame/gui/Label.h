#pragma once
#include "Item.h"
#include <string>
#include "CaptionSupport.h"
namespace StiGame
{

namespace Gui
{

/// \class Label
/// \brief Text Label
class Label :
    public Item,
    public CaptionSupport
{
public:
	/// \brief Create a new Label
	Label(void);
	/// \brief Destructor
	~Label(void);
	/// \brief Render the Label
	/// \return Rendered Label
	Surface* render(void);
    /*/// \brief Set the caption text
	/// \param m_caption Text
    void setCaption(std::string m_caption);
	/// \brief Get the current caption text
	/// \return Caption text
    std::string getCaption(void);
	/// \brief Set the Label Font
	/// \param m_font Font
    void setFont(Font *m_font);*/
	/// \brief Autosize the label with caption text
	void doAutosize(void);
	/// \brief Set the label transparent
	/// \param m_transparent Transparency
	void setTransparent(bool m_transparent);
	/// \brief Get the label transparency value
	/// \return Transparency
	bool getTransparent(void);
	/// \brief Get Draw Border value
	/// \return Border drawed or not
	bool getDrawBorder(void);
	/// \brief Set Draw Border value
	/// \param m_drawBorder Draw Border
	void setDrawBorder(bool m_drawBorder);

	virtual void setForeground(Color *m_foreground);

protected:
    /*/// \brief Render the caption text
    void renderCaption(void);*/
	
	/// \brief Drawing Border to the buffer Surface
	void _drawBorder(Surface *buffer);
	
	/// \brief Transparency
	bool transparent;
	/// \brief Caption text buffer
    /*Surface *stringBuffer;
	/// \brief Caption font
	Font *font;
	/// \brief Caption Text
    std::string caption;*/
	/// \brief Draw Border
	bool drawBorder;
};

}

}

