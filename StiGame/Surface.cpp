
#include "Surface.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Dimension.h"
#include "Primitive.h"
#include <string>
#include <iostream>
#include "Logger.h"

namespace StiGame {

	Surface::Surface(void)
	{
		releaseSurface = true;
		empty = true;
		width = 0;
		height = 0;
		sdlSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	}

	Surface::Surface(int m_width,int m_height)
	{
		releaseSurface = true;
		empty = false;
		width = m_width;
		height = m_height;
		//sdl 2 -> default mask to add as a attribute of surface ?
		sdlSurface = SDL_CreateRGBSurface(0 , width, height, 32, 0, 0, 0, 0);
	}


    void Surface::setAlpha(int n_alpha)
    {
        if(n_alpha > 255 || n_alpha < 0)
        {
            return;
        }

        Uint8 r=0,g=0,b=0,a=0;

        for(int h=0; h<sdlSurface->h; h++)
        {
            for(int w=0; w<sdlSurface->w; w++)
            {
                Uint8 *pc = (Uint8 *)sdlSurface->pixels + h * sdlSurface->pitch + w * 4;
                Uint32 pval = *(Uint32 *)pc;
                SDL_GetRGBA(pval, sdlSurface->format, &r, &g, &b, &a);

                if(a > n_alpha)
                {
                    Uint32 nc = SDL_MapRGBA(sdlSurface->format , r, g, b, n_alpha);
                    *(Uint32 *)pc = nc;
                }
            }
        }
    }

    void Surface::setTransparentColor(Color *color)
    {
        setTransparentColor(color->getRed(), color->getGreen(), color->getBlue());
    }

    void Surface::setTransparentColor(Uint8 r, Uint8 g, Uint8 b)
    {
        if(sdlSurface != 0)
        {
            Uint32 colorkey =  SDL_MapRGBA(sdlSurface->format, r, g, b, 0);
            SDL_SetColorKey(sdlSurface, SDL_TRUE, colorkey);
        }
    }

	void Surface::makeTransparent(void)
	{
		if(sdlSurface != 0)
		{
			Uint32 colorkey = SDL_MapRGBA(sdlSurface->format, 0, 0, 0, 0);
			SDL_Rect *src = getRect();
			SDL_FillRect(sdlSurface, src, colorkey);
			SDL_SetColorKey(sdlSurface, SDL_TRUE, colorkey);
			delete src;
		}
	}

	Surface::Surface(SDL_Surface *sur)
	{
		releaseSurface = false;

		if(sur != 0)
		{
			sdlSurface = sur;
			empty = false;
			width = sur->w;
			height = sur->h;
		}
	}

	Surface::Surface(const char* path)
	{
		releaseSurface = true;
		sdlSurface = IMG_Load(path);

		if(sdlSurface)
		{
			width = sdlSurface->w;
			height = sdlSurface->h;
			empty = false;
		}
		else
		{
			width = 0;
			height = 0;
			empty = true;
		}
	}

	void Surface::loadFromFile(char* path)
	{
		freeSurface();

		sdlSurface = IMG_Load(path);

		if(sdlSurface)
		{
			width = sdlSurface->w;
			height = sdlSurface->h;
			empty = false;
		}
		else
		{
			width = 0;
			height = 0;
			empty = true;
		}
	}

    void Surface::lock(void)
    {
        SDL_LockSurface(sdlSurface);
    }

    void Surface::unlock(void)
    {
        SDL_UnlockSurface(sdlSurface);
    }

    Rectangle *Surface::getRectangle(void)
    {
        return getRectangle(0, 0);
    }

    Rectangle *Surface::getRectangle(int m_x, int m_y)
    {
        Rectangle *rect = new Rectangle();
        rect->setPoint(m_x, m_y);
        rect->setDimension(width, height);
        return rect;
    }

	SDL_Rect *Surface::getRect(void)
	{
		SDL_Rect *rect = new SDL_Rect();
		rect->w = width;
		rect->h = height;

		return rect;
	}

	SDL_Rect *Surface::getRect(int x, int y)
	{
		SDL_Rect *rect = getRect();
		rect->x = x;
		rect->y = y;
		return rect;
	}

	void Surface::freeSurface(void)
	{
		if(releaseSurface && sdlSurface != 0)
		{
			SDL_FreeSurface(sdlSurface);
			width = 0;
			height = 0;
			empty = true;
			sdlSurface = 0;
		}
	}

	void Surface::fill(Uint32 c)
	{
		SDL_Rect region = SDL_Rect();
		region.x = 0;
		region.y = 0;
		region.w = width;
		region.h = height;

		int rs = SDL_FillRect(sdlSurface, &region, c);
	}

	void Surface::fill(Color *c)
	{
		if(!c->isMapped())
		{
			c->mapColor(sdlSurface->format);
		}

		fill(c->getMap());
	}

	void Surface::fillRect(SDL_Rect *region, Uint32 color)
	{
		int rs = SDL_FillRect(sdlSurface, region, color);

		if(rs != 0)
		{
			//shit happens
			//error
			Logger::Error(SDL_GetError());
		}
	}

	void Surface::fillRect(SDL_Rect *region, Color *color)
	{
		if(!color->isMapped())
		{
			color->mapColor(sdlSurface->format);
		}

		fillRect(region, color->getMap());
	}

	void Surface::updatePointer(SDL_Surface *surface)
	{
		if((sdlSurface != surface && surface != 0) ||
			(sdlSurface == surface && surface != 0 && (sdlSurface->w != width || sdlSurface->h != height)))
		{
			width = surface->w;
			height = surface->h;

			sdlSurface = surface;
		}
	}

	void Surface::blit(SDL_Surface *src, SDL_Rect *srcRect, SDL_Rect *dstRect)
	{
		int rs = SDL_BlitSurface(src, srcRect, sdlSurface, dstRect);
		if(rs != 0)
		{
			//error
			Logger::Error(SDL_GetError());
		}
	}

	void Surface::blit(Surface *src, SDL_Rect *srcRect, SDL_Rect *dstRect)
	{
		int rs = SDL_BlitSurface( src->getSDLSurface(), srcRect, sdlSurface, dstRect);
		if(rs != 0)
		{
			//error
			//std::cout << "Blit Error" << std::endl;
			//std::cout << SDL_GetError() << std::endl;
			Logger::Error(SDL_GetError());
		}
	}

	SDL_Surface *Surface::getSDLSurface(void)
	{
		return sdlSurface;
	}

	void Surface::draw(Primitive *prim, Color *color)
	{
		prim->draw(sdlSurface, color);
	}

	void Surface::fill(Primitive *prim, Color *color)
	{
		prim->fill(sdlSurface, color);
	}

	bool Surface::getReleaseSurface(void)
	{
		return releaseSurface;
	}

	void Surface::setReleaseSurface(bool m_release)
	{
		releaseSurface = m_release;
	}

    void Surface::updateSDLRect(SDL_Rect *rect)
    {
        rect->w = width;
        rect->h = height;
    }

	void Surface::updateSDLRect(SDL_Rect *rect, int m_x, int m_y)
	{
	    updateSDLRect(rect);
	    rect->x = m_x;
	    rect->y = m_y;
	}

	void Surface::updateSDLRect(SDL_Rect *rect, Point *pt)
	{
	    updateSDLRect(rect);
	    rect->x = pt->getX();
	    rect->y = pt->getY();
	}

	Uint32 Surface::getPixelInt(int p_x, int p_y)
	{
		Uint32 pc = 0;

		Uint8 *target_pixel = (Uint8 *)sdlSurface->pixels + p_y * sdlSurface->pitch + p_x * 4;
		pc = (*(Uint32*)target_pixel);

		return pc;
	}

    Pixel Surface::getPixel(Point *pt)
    {
        return getPixel(pt->getX(), pt->getY());
    }

    Pixel Surface::getPixel(int p_x, int p_y)
    {
        Uint32 px = getPixelInt(p_x, p_y);

        return Pixel(px, sdlSurface->format);
    }

	void Surface::saveBmp(std::string dest)
	{
		if(SDL_SaveBMP(sdlSurface, dest.c_str()) != 0)
		{
			//error handling
			//SDL_GetError();
			Logger::Error(SDL_GetError());
		}
	}

	void Surface::setClipRect(SDL_Rect *rect)
	{
		SDL_SetClipRect(sdlSurface, rect);
	}

	void Surface::updateClipRect(SDL_Rect *rect)
	{
		SDL_GetClipRect(sdlSurface, rect);
	}

	Surface::~Surface(void)
	{
		freeSurface();
	}

}

#ifdef C_WRAPPER

extern "C"
{
    StiGame::Surface* Surface_new()
    {
        return new StiGame::Surface();
    }

    void Surface_saveBmp(StiGame::Surface *surface, char* dest, int length)
    {
        std::string dest_string (dest, length);

        surface->saveBmp(dest_string);
    }

    int Surface_getWidth(StiGame::Surface *surface)
    {
        return surface->getWidth();
    }

    int Surface_getHeight(StiGame::Surface *surface)
    {
        return surface->getHeight();
    }

    char* Surface_getPixels(StiGame::Surface *surface)
    {
        return static_cast<char*>(surface->getSDLSurface()->pixels);
    }
}

#endif // C_WRAPPER
