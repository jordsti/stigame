#ifndef SURFACE_H
#define SURFACE_H

#include "SDL.h"
#include "Pixel.h"
#include "Primitive.h"
#include "Rectangle.h"
#include <string>
/// \namespace StiGame
/// \brief Namespace that contains all classes to work with SDLEngine
///

namespace StiGame
{
/// \class Surface
/// \brief Wrapper of a SDL_Surface
///
class Surface :
	public Dimension
{
protected:
	/// \brief Pointer to SDL_Surface
	SDL_Surface *sdlSurface;

	/// \brief Call SDL_FreeSurface to release memory
	void freeSurface(void);

	/// \brief Is the surface needs to be released
	bool releaseSurface;

	/// \brief is the Surface is empty
	bool empty;

public:
	/// \brief Constructor
	///	Empty surface constructor
	Surface(void);
	/// \brief Constructor
	///	Create a surface with specified size
	///	\param m_width : width (px)
	///	\param m_height : height (px)
	Surface(int m_width, int m_height);
	/// \brief Constructor
	/// Create a new Surface from a SDL_Surface
	/// \param m_surface parent SDL Surface
	Surface(SDL_Surface *m_surface);
	/// \brief Constructor
	/// Create a new Surface from a file
	/// \param m_path Path to image
    Surface(std::string m_path);
	/// \brief Return the SDL_Surface
	/// \return Encapsulated SDL_Surface
	SDL_Surface *getSDLSurface(void);
	/// \brief Release the surface at destruction
	/// \param m_releaseSurface Release the surface
	void setReleaseSurface(bool m_releaseSurface);
	/// \brief Get the value pf ReleaseSurface
	/// \return ReleaseSurface value
	bool getReleaseSurface(void);
	/// \brief Update the SDL_Surface pointer
	/// and update dimension of the Surface
	/// \param m_surface SDL_Surface pointer
	void updatePointer(SDL_Surface *m_surface);
	/// \brief Fill the entire surface with a specific color
	/// \param color Uint32 mapped color
	void fill(Uint32 color);
	/// \brief Fill the entire surface with a specific color
	/// \param color SColor pointer
	void fill(Color *color);
	/// \brief Fill a region specified by a SDL_Rect
	/// \param rect Pointer to a SDL_Rect
	/// \param color Uint32 mapped color
	void fillRect(SDL_Rect *rect, Uint32 color);
	/// \brief Fill a region specified by a SDL_Rect
	/// \param rect Pointer to a SDL_Rect
	/// \param color Pointer to a SColor
	void fillRect(SDL_Rect *rect, Color *color);

	void fillRect(Rectangle *rect, Color *color);

	/// \brief Blit a SDL_Surface on this Surface
	/// \param m_surface Pointer to the source SDL_Surface
	/// \param src Pointer to source SDL_Rect
	/// \param dst Pointer to destination SDL_Rect
	void blit(SDL_Surface *m_surface, SDL_Rect *src, SDL_Rect *dst);
	/// \brief Blit a SDL_Surface on this Surface
	/// \param m_surface Pointer to the source Surface
	/// \param src Pointer to source SDL_Rect
	/// \param dst Pointer to destination SDL_Rect
	void blit(Surface *m_surface, SDL_Rect *src, SDL_Rect *dst);

	void blit(Surface *m_surface, Rectangle *src, Rectangle *dst);

	void blit(Surface *m_surface, Rectangle *dst);

	void blit(Surface *m_surface, SDL_Rect *dst);

    void blit(Surface *m_surface, Point *pt);

	/// \brief Draw a primitive object to this Surface
	/// \param prim Pointer to primitive to draw
	/// \param color Pointer to a SColor
	void draw(Primitive *prim, Color *color);
	/// \brief Fill a primitive object to this Surface
	/// \param prim Pointer to primitive to draw
	/// \param color Pointer to a SColor
	void fill(Primitive *prim, Color *color);
	/// \brief Make this surface transparent
	void makeTransparent(void);
	/// \brief Change this alpha value of the surface
	/// \param n_aplha New alpha value (0-255)
	void setAlpha(int n_aplha);
	/// \brief Set transparent color key
	/// \param color Pointer to SColor
	void setTransparentColor(Color *color);
	/// \brief Set transparent color key
	/// \param r Red
	/// \param g Green
	/// \param b Blue
	void setTransparentColor(Uint8 r, Uint8 g, Uint8 b);
	/// \brief Get a Pointer to a SDL_Rect who contains surface dimension
	/// IMPORTANT : You must free this SDL_Rect after it has been used.
	SDL_Rect *getRect(void);
	/// \brief Get a Pointer to a SDL_Rect who contains surface dimension
	/// IMPORTANT : You must free this SDL_Rect after it has been used.
	/// /param m_x Value to add to width
	/// /param m_y Value to add to height
	SDL_Rect *getRect(int m_x,int m_y);
    /// \brief Get a Pointer to a SRect who contains surface dimension
	/// IMPORTANT : You must free this SRect after it has been used.
	Rectangle *getRectangle(void);
    /// \brief Get a Pointer to a SRect who contains surface dimension
	/// IMPORTANT : You must free this SRect after it has been used.
	/// /param m_x Value to add to width
	/// /param m_y Value to add to height
	Rectangle *getRectangle(int m_x, int m_y);
	/// \brief Lock the surface
	void lock(void);
	/// \brief Unlock the surface
	void unlock(void);
	/// \brief Destructor
	virtual ~Surface(void);
	/// \brief Load a image file
	/// \param m_path Path to image
    void loadFromFile(const char *m_path);

	Uint32 getPixelInt(int p_x, int p_y);
	Pixel* getPixel(Point *pt);
    Pixel* getPixel(int p_x, int p_y);

	void updateSDLRect(SDL_Rect *rect);
	void updateSDLRect(SDL_Rect *rect, int m_x, int m_y);
	void updateSDLRect(SDL_Rect *rect, Point *pt);

	void setClipRect(SDL_Rect *rect);
	void updateClipRect(SDL_Rect *rect);

	void saveBmp(std::string dest);
};

}

#endif

