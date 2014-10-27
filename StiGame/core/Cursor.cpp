#include "Cursor.h"

namespace StiGame
{

Cursor::Cursor()
{
	cursor = SDL_GetDefaultCursor(); //default cursor
	_default = true;
}

Cursor::Cursor(SDL_Cursor *m_cursor)
{
	cursor = m_cursor;

	if(m_cursor == SDL_GetDefaultCursor())
    {
        _default = true;
    }
    else
    {
        _default = false;
    }
}

Cursor::Cursor(const Uint8* m_data, const Uint8* m_mask, int m_width, int m_height, int m_hot_x, int m_hot_y)
{
    cursor = SDL_CreateCursor(m_data, m_mask, m_width, m_height, m_hot_x, m_hot_y);
    _default = false;
}

Cursor::Cursor(Surface *surface, int m_hot_x, int m_hot_y)
{
    cursor = SDL_CreateColorCursor(surface->getSDLSurface(), m_hot_x, m_hot_y);
    _default = false;
}

Cursor::Cursor(SDL_SystemCursor systemCursor)
{
    cursor = SDL_CreateSystemCursor(systemCursor);
    _default = false;
}

void Cursor::Show(bool m_show)
{
    SDL_ShowCursor(m_show);
}

bool Cursor::isDefault(void)
{
    return _default;
}

Cursor::~Cursor()
{
	//free this ?
	SDL_Cursor *d_cursor = SDL_GetDefaultCursor();

	if(cursor != d_cursor)
	{
		SDL_FreeCursor(cursor);
	}
}


SDL_Cursor* Cursor::getSDLCursor(void)
{
	return cursor;
}


}
