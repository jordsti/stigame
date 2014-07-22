#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "HighlightItem.h"

//BIG WIP
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
	
	bool isFocus(void);
	void setFocus(bool m_focus);
	
protected:
	void renderString(void);
	Surface *stringBuffer;
	std::string text;
	Font *font;
	bool focus;
};

}

}


#endif