#include "Label.h"
#include "PLine.h"

namespace StiGame
{

namespace Gui
{

Label::Label(void)  : Item("Label"), CaptionSupport()
{
	transparent = true;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	drawBorder = false;
}



Label::~Label(void)
{
    /*if(stringBuffer != nullptr)
    {
        delete stringBuffer;
    }*/
}

bool Label::getDrawBorder(void)
{
	return drawBorder;
}

void Label::setDrawBorder(bool m_drawBorder)
{
	drawBorder = m_drawBorder;
}

void Label::_drawBorder(Surface *buffer)
{
	PLine line = PLine();

	line.set1(0, 0);
	line.set2(0, height - 1);
	line.draw(buffer->getSDLSurface(), foreground);

	line.set2(width - 1, 0);
	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(width - 1, 0);
	line.set2(width - 1, height - 1);
	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(0, height - 1);
	line.set2(width - 1, height - 1);
	line.draw(buffer->getSDLSurface(), foreground);
}

void Label::doAutosize(void)
{

    width = stringRenderer.getWidth();
    height = stringRenderer.getHeight();

	minimumSize.setDimension(width, height);
}

void Label::setForeground(Color *m_foreground)
{
    foreground = m_foreground;
    stringRenderer.setColor(foreground);
}

void Label::setTransparent(bool m_transparent)
{
	transparent = m_transparent;
}

bool Label::getTransparent(void)
{
	return transparent;
}

Surface* Label::render(void)
{
	if(isEmpty())
	{
		doAutosize();
	}

    Surface *stringBuffer = stringRenderer.getSurface();

    if(width != stringBuffer->getWidth() || height != stringBuffer->getHeight())
    {
        doAutosize();
    }

	Surface *buffer = new Surface(width,height);

	if(!transparent)
	{
		buffer->fill(background);
	}
	else
	{
		buffer->makeTransparent();
	}

	SDL_Rect *src = stringBuffer->getRect();
	SDL_Rect *dst = new SDL_Rect();

	dst->x = (width / 2) - (src->w / 2);
	dst->y = (height / 2) - (src->h / 2);
	dst->w = src->w;
	dst->h = src->h;

	buffer->blit(stringBuffer, src, dst);

	if(drawBorder)
	{
		_drawBorder(buffer);
	}

	delete dst;
	delete src;

	return buffer;
}

}

}

#ifdef C_WRAPPER

extern "C" {
    StiGame::Gui::Label* Label_new()
    {
        return new StiGame::Gui::Label();
    }

    void Label_setCaption(StiGame::Gui::Label *label, char* text)
    {
        std::string text_string (text);

        label->setCaption(text_string);
    }

    const char* Label_getCaption(StiGame::Gui::Label *label)
    {
        return label->getCaption().c_str();
    }

}

#endif // C_WRAPPER
