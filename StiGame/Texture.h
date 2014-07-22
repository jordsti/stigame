#ifndef TEXTURE_H
#define TEXTURE_H
#include "Dimension.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Surface.h"


namespace StiGame {

/// \class Texture
/// \brief Wrapper of SDL_Texture, represent a pixel data handled by the GPU
class Texture :
    public Dimension
{
    public:
		/// \brief Create a new empty texture
        Texture(void);

		/// \brief Create a new texture from a SDL_Texture
		/// \param m_texture SDL_Texture
        Texture(SDL_Texture *m_texture); //renderer passed or not ?!

		/// \brief Create a new empty texture
		/// \param m_renderer SDL_Renderer
		/// \param m_width Texture width (px)
		/// \param m_height Texture height (px)
		/// \param m_format Texture format
		/// \param m_access Texture access
        Texture(SDL_Renderer *m_renderer, int m_width, int m_height, Uint32 m_format, int m_access);

		/// \brief Create a new empty texture
		/// \param m_renderer SDL_Renderer
		/// \param m_width Texture width (px)
		/// \param m_height Texture height (px)
        Texture(SDL_Renderer *m_renderer, int m_width, int m_height);

		/// \brief Create a new texture from image
		/// \param m_renderer SDL_Renderer
		/// \param img_path Path to the image file
        Texture(SDL_Renderer *m_renderer, const char* img_path);

		/// \brief Create a new texture from a surface
		/// \param m_renderer SDL_Renderer
		/// \param surface SDL_Surface
        Texture(SDL_Renderer *m_renderer, SDL_Surface *surface);

        Texture(SDL_Renderer *m_renderer, Surface *surface);

		/// \brief Texture destructor
        virtual ~Texture();

		/// \brief Get the SDL_Texture
		/// \return SDL_Texture pointer
        SDL_Texture* getSDLTexture(void);

		/// \brief Get Texture format
		/// \return Texture Format
        Uint32 getFormat(void);

		/// \brief Get Texture access
		/// \return Texture access
        int getAccess(void);

		/// \brief Query the texture, to update information
        void query(void);

		/// \brief Lock a rectangle on the Texture
		/// \param rect zone to lock
		/// \param pixels Pixels to lock
		/// \param pitch Pitch
        void lock(SDL_Rect *rect, void **pixels, int *pitch);

		/// \brief Unlock Texture
        void unlock(void);

		/// \brief Set the SDL_Renderer
		/// \param m_renderer SDL_Renderer
        void setRenderer(SDL_Renderer *m_renderer);

		/// \brief Set Renderer Blend Mode
		/// \param blendMode Blend Mode
        void setBlendMode(SDL_BlendMode blendMode);

		/// \brief Set Renderer Alpha Mod
		/// \param alpha Alpha mod
        void setAlphaMod(Uint8 alpha);

		/// \brief Set Renderer Color Mod
		/// \param r Red
		/// \param g Green
		/// \param b Blue
        void setColorMod(Uint8 r, Uint8 g, Uint8 b);

		/// \brief Render the Texture
		/// \param src Source rectangle
		/// \param dst Destination rectangle
        void renderCopy(SDL_Rect *src, SDL_Rect *dst);

		/// \brief Render the Texture with an angle
		/// \param src Source rectangle
		/// \param dst Destination rectangle
		/// \param angle Texture angle
		/// \param center Center of rotation
		/// \param flip Desired Flip
        void renderCopyEx(SDL_Rect *src, SDL_Rect *dst, double angle, SDL_Point *center, SDL_RendererFlip flip);
		
		
		Surface* getSurface(void);
		
    protected:
		/// \brief Pointer to SDL_Texture
        SDL_Texture *sdlTexture;
		/// \brief Pointer to SDL_Renderer
        SDL_Renderer *renderer;
		/// \brief Texture access
        int access;
		/// \brief Texture format
        Uint32 format;

		/// \brief Error handling method
        void handleError(void);
		
		Surface *surface;
		
    private:

		/// \brief Texture initializer
        void initialize(void);
};

}
#endif // TEXTURE_H
