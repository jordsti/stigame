#include "TextBox.h"
#include "PRect.h"
#include <iostream>
namespace StiGame
{

namespace Gui
{

TextBox::TextBox()
	: HighlightItem("TextBox")
{
	text = "";
	stringBuffer = nullptr;
	font = style->getNormalFont();
	focus = false;
	handleKey = true;
	_tick = 0;
}

TextBox::~TextBox()
{
	if(stringBuffer != nullptr)
	{
		delete stringBuffer;
	}
}

Font* TextBox::getFont(void)
{
	return font;
}

void TextBox::setFont(Font *m_font)
{
	font = m_font;
}

std::string TextBox::getText(void)
{
	return text;
}

void TextBox::setText(std::string m_text)
{
	text = m_text;
	renderString();
}

void TextBox::onClick(Point *relpt)
{
    setFocus(!focus);
}

void TextBox::setFocus(bool m_focus)
{
	focus = m_focus;
	if(focus)
    {
        //SDL_Rect *rect = getSDLRect();
        //possible leak here
        //SDL_SetTextInputRect(rect);
        SDL_StartTextInput();
    }
    else
    {
        SDL_StopTextInput();
    }
}

void TextBox::onTextInput(char *m_text)
{
    text += m_text;
    renderString();
    //debug
    std::cout << m_text << std::endl;
    std::cout << text << std::endl;
}

void TextBox::onKeyUp(SDL_KeyboardEvent *evt)
{
    if(evt->keysym.sym == SDLK_BACKSPACE)
    {
        if(text.length() > 1)
        {
            text = text.substr(0, text.length() - 1);
            renderString();
        }
        else if(text.length() == 1)
        {
            text = "";
        }
    }
    else if (evt->keysym.sym == SDLK_RETURN)
    {
        if(focus)
        {
            setFocus(false);
        }
    }
}

Surface* TextBox::render(void)
{
    _tick++;

    if(stringBuffer == nullptr && text.length() > 0)
    {
        renderString();
    }

	Surface *buffer = new Surface(width, height);

	buffer->fill(background);

	PRect rect = PRect();
	rect.setX(0);
	rect.setY(0);
	rect.setWidth(width - 1);
	rect.setHeight(height - 1);

	buffer->draw(&rect, foreground);

	Surface *text_str = stringBuffer;

    if(text.length() > 0)
    {
        if(focus && _tick % 3 == 0)
        {
            //add a |
            std::string tmp_text = text + "|";

            text_str = font->renderText(tmp_text, foreground);
        }

        SDL_Rect *src = new SDL_Rect();
        SDL_Rect *dst = new SDL_Rect();

        dst->x = 4;
        dst->y = (height - text_str->getHeight()) / 2;
        dst->w = text_str->getWidth();
        dst->h = text_str->getHeight();

        text_str->updateSDLRect(src);

        buffer->blit(text_str, src, dst);

        if(stringBuffer != text_str)
        {
            delete text_str;
        }

        delete src;
        delete dst;
    }

	return buffer;
}

void TextBox::renderString(void)
{
	if(stringBuffer != nullptr)
	{
		delete stringBuffer;
	}

	stringBuffer = font->renderText(text, foreground);
}

}

}

#ifdef C_WRAPPER

extern "C" {

    StiGame::Gui::TextBox* TextBox_new()
    {
        return new StiGame::Gui::TextBox();
    }

    void TextBox_setText(StiGame::Gui::TextBox *textBox, char *text)
    {
        textBox->setText(text);
    }

}

#endif // C_WRAPPER
