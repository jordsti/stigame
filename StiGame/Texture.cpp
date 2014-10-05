#include "Texture.h"
#include "MathTK.h"
#include <iostream>
#include "Logger.h"

namespace StiGame
{
    void Texture::initialize(void)
    {
        width = 0;
        height = 0;
        renderer = 0;
        sdlTexture = 0;
        format = SDL_PIXELFORMAT_ABGR8888;
        access = SDL_TEXTUREACCESS_STATIC;
		surface = 0;
    }

    Texture::Texture(void)
    {
        initialize();
    }

    Texture::Texture(SDL_Texture *m_texture)
    {
        initialize();

        sdlTexture = m_texture;
        query();
    }

    Texture::Texture(SDL_Renderer *m_renderer, int m_width, int m_height)
    {
        //ctor
        initialize();
        width = m_width;
        height = m_height;
        renderer = m_renderer;
        sdlTexture = SDL_CreateTexture(renderer, format, access, width, height);
    }

    Texture::Texture(SDL_Renderer *m_renderer, int m_width, int m_height, Uint32 m_format, int m_access)
    {
        //ctor
        initialize();
        width = m_width;
        height = m_height;
        renderer = m_renderer;
        sdlTexture = SDL_CreateTexture(renderer, format, access, width, height);
    }

    Texture::Texture(SDL_Renderer *m_renderer, const char* img_path)
    {
        //ctor
        initialize();

        renderer = m_renderer;
        //SDL_Surface *tmp_sur = IMG_Load(img_path);

		surface = new Surface(img_path);

        width = surface->getWidth();
        height = surface->getHeight();

        sdlTexture = SDL_CreateTextureFromSurface(renderer, surface->getSDLSurface());

        //SDL_FreeSurface(tmp_sur);
    }

    Texture::Texture(SDL_Renderer *m_renderer, SDL_Surface *m_surface)
    {
        initialize();
        renderer = m_renderer;
		surface = new Surface(m_surface);
        width = surface->getWidth();
        height = surface->getHeight();

		surface->setReleaseSurface(true);

        sdlTexture = SDL_CreateTextureFromSurface(renderer, surface->getSDLSurface());
    }

    Texture::Texture(SDL_Renderer *m_renderer, Surface *m_surface)
    {
        initialize();
        renderer = m_renderer;
		surface = m_surface;
        width = surface->getWidth();
        height = surface->getHeight();

        sdlTexture = SDL_CreateTextureFromSurface(renderer, surface->getSDLSurface());
    }

    SDL_Texture* Texture::getSDLTexture(void)
    {
        return sdlTexture;
    }

    Uint32 Texture::getFormat(void)
    {
        return format;
    }

    int Texture::getAccess(void)
    {
        return access;
    }

    void Texture::query(void)
    {
        int m_w,m_h,m_access;
        Uint32 m_format;

        if(SDL_QueryTexture(sdlTexture, &m_format, &m_access, &m_w, &m_h) == 0)
        {
            width = m_w;
            height = m_h;
            format = m_format;
            access = m_access;
        }
		else
		{
			Logger::Error(SDL_GetError());
		}
    }


    void Texture::lock(SDL_Rect *rect, void **pixels, int *pitch)
    {
        SDL_LockTexture(sdlTexture, rect, pixels, pitch);

    }

    void Texture::unlock(void)
    {
        SDL_UnlockTexture(sdlTexture);
    }

    void Texture::setRenderer(SDL_Renderer *m_renderer)
    {
        renderer = m_renderer;
    }

    void Texture::setBlendMode(SDL_BlendMode blendMode)
    {
        if(SDL_SetTextureBlendMode(sdlTexture, blendMode) != 0)
		{
			Logger::Error(SDL_GetError());
		}
    }

    void Texture::setAlphaMod(Uint8 alpha)
    {
        if(SDL_SetTextureAlphaMod(sdlTexture, alpha) != 0)
        {
            std::cout <<"alpha error" << std::endl;
            handleError();
        }
    }

    void Texture::setColorMod(Uint8 r, Uint8 g, Uint8 b)
    {
        if(SDL_SetTextureColorMod(sdlTexture, r, g, b) != 0)
        {
            handleError();
        }
    }

    void Texture::renderCopy(SDL_Rect *src, SDL_Rect *dst)
    {
        if(SDL_RenderCopy(renderer, sdlTexture, src, dst) != 0)
        {
            handleError();
        }
    }

    void Texture::renderCopy(Point *pt)
    {
        SDL_Rect src;
        SDL_Rect dst;

        src.x = 0;
        src.y = 0;
        src.w = width;
        src.h = height;

        dst.x = pt->getX();
        dst.y = pt->getY();
        dst.w = width;
        dst.h = height;

        if(SDL_RenderCopy(renderer, sdlTexture, &src, &dst) != 0)
        {
            handleError();
        }
    }
																// use angle class ? or just use Math:: static method
    void Texture::renderCopyEx(SDL_Rect *src, SDL_Rect *dst, double angle, SDL_Point *center, SDL_RendererFlip flip)
    {
        if(SDL_RenderCopyEx(renderer, sdlTexture, src, dst, Math::TK::rad_to_degree(angle), center, flip) != 0)
        {
            handleError();
        }
    }

    void Texture::handleError(void)
    {
        const char* sdl_error = SDL_GetError();
        //temporary need an error handler
        //std::cout << sdl_error << std::endl;
		Logger::Error(sdl_error);
    }

	Surface* Texture::getSurface(void)
	{
		return surface;
	}

    Texture::~Texture()
    {
        //dtor
		SDL_DestroyTexture(sdlTexture);

        //surface->setReleaseSurface(true);
        //bug here cause SEGFAULT -> fixed
		if(surface != 0)
		{
			delete surface;
		}
    }

}
