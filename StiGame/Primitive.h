#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "SDL.h"
#include "Color.h"

namespace StiGame
{
/* Note(s)
* Need to examine some alternative
* Maybe do a wrapper of SDL_gfx...
*
*/

class Surface;

/// \class SPrimitive
/// \brief Interface to draw or fill a polygon
class Primitive
{
public:
	/// \brief Empty constructor
	Primitive(void);

	/// \brief Destructor
	~Primitive(void);
	void draw(Surface *surface, Color *color);
	void fill(Surface *surface, Color *color);
	/// \brief Virtual method to override
	/// Draw the primitive, border only
	/// \param surface SDL_Surface to draw on
	/// \param color SColor pointer
	/// \deprecated Using surface gonna be deprecated, but still used in Item rendering...
	virtual void draw(SDL_Surface *surface, Color *color) = 0;
	/// \brief Virtual method to override
	/// Fill the primitive
	/// \param surface SDL_Surface to draw on
	/// \param color SColor pointer
	/// \deprecated Using surface gonna be deprecated, but still used in Item rendering...
	virtual void fill(SDL_Surface *surface, Color *color) = 0;
	/// \brief Virtual method to override, draw to the screen a Primitive
	/// \param renderer SDL_Renderer
	/// \param color Primitive Color
    virtual void draw(SDL_Renderer *renderer, Color *color) = 0;
	/// \brief Virtual method to override, fill to the screen a Primitive
	/// \param renderer SDL_Renderer
	/// \param color Primitive Color
    virtual void fill(SDL_Renderer *renderer, Color *color) = 0;
protected:
	/// \brief Set the pixel color
	/// \param surface SDL_Surface to modify
	/// \param p_x pixel x
	/// \param p_y pixel y
	/// \param color Uint32 SDL mapped color
	/// \depcrecated Surface Pixel modification need to be avoid !
	void setPixel(SDL_Surface *surface,int p_x,int p_y,Uint32 color);
};
}

#endif

