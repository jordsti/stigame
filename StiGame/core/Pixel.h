#ifndef PIXEL_H
#define PIXEL_H

#include "Color.h"

namespace StiGame
{

class Pixel
{
public:
	Pixel();
	Pixel(Uint32 m_pixel, SDL_PixelFormat *m_format);
	virtual ~Pixel();
	
	Uint8 getRed(void);
	Uint8 getGreen(void);
	Uint8 getBlue(void);
	Uint8 getAlpha(void);
	SDL_PixelFormat* getFormat(void);
	Uint32 getPixel(void);
	SDL_Color getSDLColor(void);
	Color getColor(void);
protected:
	void init(void);
	void getRGBA(void);
	Uint32 pixel;
	Uint8 red;
	Uint8 green;
	Uint8 blue;
	Uint8 alpha;
	SDL_PixelFormat *format;
};

}

#endif