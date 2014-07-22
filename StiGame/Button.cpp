
#include "Button.h"
#include "PLine.h"
namespace StiGame
{

namespace Gui
{

Button::Button(void) : Item("button")
{
	offsetWidth = DEFAULT_OFFSET;
	offsetHeight = DEFAULT_OFFSET;
	caption = " ";
	stringBuffer = 0;
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
	}
	else
	{
		bg = background;
		fg = foreground;
	}

	buffer->fill(bg);

	SDL_Rect *src = stringBuffer->getRect();
	SDL_Rect *dst = stringBuffer->getRect(offsetWidth, offsetHeight);

	buffer->blit(stringBuffer, src, dst);

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

void Button::clear(void)
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
		stringBuffer = 0;
	}
}

void Button::autosize(void)
{
	if(stringBuffer == 0)
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
}


Button::~Button(void)
{
	clear();
}

}

}
