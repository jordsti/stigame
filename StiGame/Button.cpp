
#include "Button.h"
#include "PLine.h"

#include <iostream>
namespace StiGame
{

namespace Gui
{

Button::Button(void) : Item("button")
{
	offsetWidth = DEFAULT_OFFSET;
	offsetHeight = DEFAULT_OFFSET;
	caption = " ";
	stringBuffer = nullptr;
	highlightForeground = style->getHighlightForeground();
	highlightBackground = style->getHighlightBackground();
}

void Button::setCaption(char* m_caption)
{
	caption = m_caption;
	renderCaption();
}

char* Button::getCaption(void)
{
	return caption;
}

Surface* Button::render(void)
{
	if(width == 0 || height == 0)
	{
		autosize();
	}

	if(stringBuffer == 0)
	{
		renderCaption();
	}

	Surface *buffer = new Surface(width, height);
	Color *bg;
	Color *fg;

	Surface *_str = nullptr;
	bool clean_str = false;

	PLine l1 = PLine();
	l1.set1(0,0);
	l1.set2(width,0);

	PLine l2 = PLine();
	l2.set1(0,0);
	l2.set2(0,height);

	PLine l3 = PLine();
	l3.set1(width - 1,0);
	l3.set2(width - 1,height);

	PLine l4 = PLine();
	l4.set1(0,height - 1);
	l4.set2(width - 1,height - 1);

	if(mouseOver)
	{
		bg = highlightBackground;
		fg = highlightForeground;
		//need to use another caption
		clean_str = true;
		_str = style->getNormalFont()->renderText(caption, highlightForeground);
		//_str->setTransparentColor(0, 0, 0);
		//_str->makeTransparent();

	}
	else
	{
		bg = background;
		fg = foreground;
		_str = stringBuffer;
	}

	buffer->fill(bg);

	SDL_Rect *src = _str->getRect();
	SDL_Rect *dst = _str->getRect((width - _str->getWidth())/2, (height - _str->getHeight())/2);
    //middle maybe todo
	buffer->blit(_str, src, dst);

	//drawing lines

	buffer->draw(&l1, fg);
	buffer->draw(&l2, fg);
	buffer->draw(&l3, fg);
	buffer->draw(&l4, fg);

	delete src;
	delete dst;

	if(clean_str)
    {
        delete _str;
    }

	return buffer;
}

void Button::onClick(Point *relp)
{
	//create a button event, but now
	EventArgs se = EventArgs();
	publish(this, &se);
}

void Button::clear(void)
{
	if(stringBuffer != nullptr)
	{
		delete stringBuffer;
		stringBuffer = nullptr;
	}
}

void Button::autosize(void)
{
	if(stringBuffer == nullptr)
	{
		renderCaption();
	}

	width = offsetWidth*2 + stringBuffer->getSDLSurface()->w;
	height = offsetHeight*2 + stringBuffer->getSDLSurface()->h;
}

void Button::renderCaption(void)
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
	}

	stringBuffer = style->getNormalFont()->renderText(caption, foreground);

	if(width == 0 && height == 0)
    {
        autosize();
    }
}


Button::~Button(void)
{
	clear();
}

}

}


#ifdef C_WRAPPER
extern "C"
{
    StiGame::Gui::Button* Button_new()
    {
        return new StiGame::Gui::Button();
    }

    void Button_setCaption(StiGame::Gui::Button *button, char *text)
    {
        button->setCaption(text);
    }

    char* Button_getCaption(StiGame::Gui::Button *button)
    {
        return button->getCaption();
    }
}
#endif // C_WRAPPER
