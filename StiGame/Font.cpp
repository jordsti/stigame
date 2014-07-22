
#include "Font.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Surface.h"
namespace StiGame
{

Font::Font()
{
	font = 0;
	size = -1;
	path = "";
}

Font::Font(const char *m_path, int m_size)
{
	size = m_size;
	path = m_path;
	font = TTF_OpenFont(m_path, m_size);
}


Font::Font(SDL_RWops *rw, int m_size)
{
	font = 0;
	size = m_size;
	path = "rw_ops";
	font = TTF_OpenFontRW(rw, 1, size);
}


Font::~Font(void)
{
	if(font != 0)
	{
		TTF_CloseFont(font);
	}
}

int Font::getSize(void)
{
	return size;
}
const char *Font::getPath(void)
{
	return path;
}
TTF_Font *Font::getSDLFont(void)
{
	return font;
}

Surface *Font::renderText(std::string caption, Color *color)
{
    return renderText(caption.c_str(), color);
}

Surface *Font::renderText(const char* text, Color *color)
{
	SDL_Surface *txtsur = TTF_RenderText_Solid(font, text, color->getSDLColor());
	Surface *sur = new Surface(txtsur);
	sur->setReleaseSurface(true);
	return sur;
}

Surface *Font::renderTextShaded(std::string caption, Color *color, Color *bg)
{
	SDL_Surface *txtsur = TTF_RenderText_Shaded(font, caption.c_str(), color->getSDLColor(), bg->getSDLColor());
	Surface *sur = new Surface(txtsur);
	sur->setReleaseSurface(true);
	return sur;
}

Surface *Font::renderTextBlended(std::string caption, Color *color)
{
	SDL_Surface *txtsur = TTF_RenderText_Blended(font, caption.c_str(), color->getSDLColor());
	Surface *sur = new Surface(txtsur);
	sur->setReleaseSurface(true);
	return sur;
}

int Font::getFontStyle(void)
{
	return TTF_GetFontStyle(font);
}

void Font::setFontStyle(int style)
{
	TTF_SetFontStyle(font, style);
}

}
