#ifndef CURSOR_H
#define CURSOR_H

#include "Surface.h"

namespace StiGame
{
//WIP not added to cbp
class Cursor
{
public:
	Cursor();
	Cursor(SDL_Cursor *m_cursor);
	Cursor(const Uint8* m_data, const Uint8* m_mask, int m_width, int m_height, int m_hot_x, int m_hot_y);
	Cursor(Surface *surface, int m_hot_x, int m_hot_y);
	Cursor(SDL_SystemCursor systemCursor);
	//todo : add a ctor for CreateCursor
	virtual ~Cursor();


	SDL_Cursor* getSDLCursor(void);
    static void Show(bool m_show);
    bool isDefault(void);
protected:
	SDL_Cursor *cursor;
private:
	bool _default;

};

}

#endif
