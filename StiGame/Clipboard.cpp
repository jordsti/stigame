#include "Clipboard.h"

#include "SDL.h"
#include <iostream>
namespace StiGame
{

Clipboard::Clipboard()
{

}

Clipboard::~Clipboard()
{

}

//static
bool Clipboard::HasText(void)
{
	SDL_bool val = SDL_HasClipboardText();
	if(val == SDL_TRUE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Clipboard::GetText(void)
{
	std::string val = "";
	
	val = SDL_GetClipboardText();

	return val;
}

void Clipboard::SetText(std::string text)
{
	if(SDL_SetClipboardText(text.c_str()) != 0)
	{
		std::cout << SDL_GetError();
	}
}

}