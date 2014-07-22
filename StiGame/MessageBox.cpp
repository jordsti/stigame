#include "MessageBox.h"

namespace StiGame
{

namespace Gui
{

MessageBox::MessageBox()
{
	type = MBT_ERROR;
	window = 0;
	title = "none";
	message = "none";
	buttonId = 0;
}

MessageBox::MessageBox(MessageBoxType m_type, std::string m_title, std::string m_message)
{
	type = m_type;
	title = m_title;
	message = m_message;
	buttonId = 0;
	window = 0;
}

MessageBox::~MessageBox()
{

}

void MessageBox::show(void)
{
	SDL_Window *pwin = NULL;
	
	if(window != 0)
	{
		pwin = window;
	}
	
	Uint32 flag;
	
	switch(type)
	{
		case MBT_ERROR:
			flag = SDL_MESSAGEBOX_ERROR;
			break;
		case MBT_WARNING:
			flag = SDL_MESSAGEBOX_WARNING;
			break;
		case MBT_INFORMATION:
			flag = SDL_MESSAGEBOX_INFORMATION;
			break;
		default:
			flag = SDL_MESSAGEBOX_INFORMATION;
			break;
	}
	//need to use MessageBoxData for button id
	//todo
	SDL_ShowSimpleMessageBox(flag, title.c_str(), message.c_str(), pwin);
}

int MessageBox::getButtonId(void)
{
	return buttonId;
}

MessageBoxType MessageBox::getType(void)
{
	return type;
}

std::string MessageBox::getTitle(void)
{
	return title;
}

std::string MessageBox::getMessage(void)
{
	return message;
}

SDL_Window* MessageBox::getWindow(void)
{
	return window;
}

void MessageBox::setTitle(std::string m_title)
{
	title = m_title;
}

void MessageBox::setMessage(std::string m_message)
{
	message = m_message;
}

void MessageBox::setType(MessageBoxType m_type)
{
	type = m_type;
}

void MessageBox::setWindow(SDL_Window *m_window)
{
	window = m_window;
}

}

}