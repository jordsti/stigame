#include "StringRenderer.h"
#include "Runtime.h"
namespace StiGame
{

StringRenderer::StringRenderer()
	: Dimension()
{
    text = " ";
    renderedString = nullptr;
	font = Gui::Runtime::getInstance()->getStyle()->getNormalFont();
	color = Gui::Runtime::getInstance()->getStyle()->getForeground();
    renderSurface();
}

StringRenderer::~StringRenderer()
{
    if(renderedString != nullptr)
    {
        delete renderedString;
    }
}

void StringRenderer::setColor(Color *m_color)
{
	color = m_color;
    renderSurface();
}

Color* StringRenderer::getColor(void)
{
	return color;
}

void StringRenderer::setFont(Font *m_font)
{
	font = m_font;
    renderSurface();
}

Font* StringRenderer::getFont(void)
{
	return font;
}

void StringRenderer::setText(std::string m_text)
{
	std::string old_text = text;
	text = m_text;

	if(text != old_text)
	{
		renderSurface();
	}
}

std::string StringRenderer::getText(void)
{
	return text;
}

Surface* StringRenderer::getSurface(void)
{
    if(renderedString != nullptr)
	{
		return renderedString;
	}
	else
	{
		renderSurface();
		return renderedString;
	}
}


void StringRenderer::renderSurface(void)
{
    if(renderedString != nullptr)
	{
		delete renderedString;
	}

	renderedString = font->renderText(text, color);
	width = renderedString->getWidth();
	height = renderedString->getHeight();
}


}
