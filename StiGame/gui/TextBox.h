#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "HighlightItem.h"

//todo
//-cursor emplacement
//
namespace StiGame
{

namespace Gui
{
/// \class TextBox
/// \brief GuiItem that show text and permit the user to change the value by clicking on it. Multi-line text is not supported by this item
class TextBox :
	public HighlightItem
{
public:
	/// \brief Constructor
	TextBox();
	/// \brief Destructor
	virtual ~TextBox();
	/// \brief Get the current text value of the textbox.
	/// \return Current Value
	std::string getText(void);
	/// \brief Set the text value of the textbox
	/// \param m_text Text value
	void setText(std::string m_text);

	/// \brief Get the current Rendering Font of the textbox
	/// \return Current Font Pointer
	Font* getFont(void);
	
	/// \brief Set the rendering Font of the textbox
	/// \param m_font Font Pointer
	void setFont(Font *m_font);

	/// \brief Render the textbox surface
	/// \return Rendered Surface Pointer
	Surface* render(void);

	/// \brief On Click event handling
	/// \param relpt Relative Click position
	void onClick(Point *relpt);

	/// \brief Set the focus value of the textbox
	/// \param m_focus Focus value
	void setFocus(bool m_focus);

	/// \brief Text Input Event handling
	/// \param m_text New Character to append
	void onTextInput(char *m_text);

	/// \brief Keyboard Up Event handling
	/// \param evt SDL_KeyboardEvent Pointer
	void onKeyUp(SDL_KeyboardEvent *evt);

protected:
	/// \brief Render the Current Text Value into the String Buffer
	void renderString(void);
	/// \brief String Surface Buffer
	Surface *stringBuffer;
	/// \brief Current Text value
	std::string text;
	/// \brief Rendering Font
	Font *font;

private:
    /// \brief Frame Tick, for | 
    unsigned int _tick;
};

}

}


#endif
