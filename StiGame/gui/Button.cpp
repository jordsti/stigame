
#include "Button.h"
#include "PLine.h"

#include <iostream>
namespace StiGame
{

namespace Gui
{

Button::Button(void) : HighlightItem("Button"), CaptionSupport()
{
	offsetWidth = DEFAULT_OFFSET;
	offsetHeight = DEFAULT_OFFSET;
	caption = " ";

    stringRenderer.setText(caption);

    highlightRenderer.setColor(highlightForeground);
    highlightRenderer.setFont(font);
    highlightRenderer.setText(caption);

}

void Button::setCaption(std::string m_caption)
{
	caption = m_caption;
    stringRenderer.setText(caption);
    highlightRenderer.setText(caption);
}

std::string Button::getCaption(void)
{
	return caption;
}

void Button::setHighlightForeground(Color *m_highlightForeground)
{
    highlightForeground = m_highlightForeground;
    highlightRenderer.setColor(m_highlightForeground);
}

Surface* Button::render(void)
{
	if(width == 0 || height == 0)
	{
		autosize();
	}

	Surface *buffer = new Surface(width, height);
	Color *bg;
	Color *fg;

	Surface *_str = nullptr;

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

        _str = highlightRenderer.getSurface();
		//_str->setTransparentColor(0, 0, 0);
		//_str->makeTransparent();

	}
	else
	{
		bg = background;
		fg = foreground;
        _str = stringRenderer.getSurface();
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

	return buffer;
}

void Button::onClick(Point *relp)
{
	//create a button event, but now
	EventArgs se = EventArgs();
	publish(this, &se);
}

void Button::setFont(Font *m_font)
{
    font = m_font;
    stringRenderer.setFont(font);
    highlightRenderer.setFont(font);
}


void Button::autosize(void)
{

    width = offsetWidth*2 + stringRenderer.getWidth();
    height = offsetHeight*2 + stringRenderer.getHeight();
}

Button::~Button(void)
{

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
        std::string text_string (text);
        button->setCaption(text_string);
    }

    const char* Button_getCaption(StiGame::Gui::Button *button)
    {
        return button->getCaption().c_str();
    }
}
#endif // C_WRAPPER
