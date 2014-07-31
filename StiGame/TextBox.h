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

class TextBox :
	public HighlightItem
{
public:
	TextBox();
	virtual ~TextBox();

	std::string getText(void);
	void setText(std::string m_text);

	Font* getFont(void);
	void setFont(Font *m_font);

	Surface* render(void);

	void onClick(Point *relpt);

	void setFocus(bool m_focus);

	void onTextInput(char *m_text);

    void onKeyUp(SDL_KeyboardEvent *evt);

protected:
	void renderString(void);
	Surface *stringBuffer;
	std::string text;
	Font *font;

private:
    unsigned int _tick;
};

}

}


#endif
