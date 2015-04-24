#pragma once
#include "Primitive.h"
#include "Rectangle.h"
namespace StiGame
{
/// \class PRect
/// \biref Primitive Rectangle, used to draw a Rectangle on a Surface or a Texture
class PRect :
	public Primitive,
	public Rectangle
{
public:
    /// \brief Empty Constructor
	PRect(void);
    /// \brief Create a new rectangle with the specified attributes
    /// \param m_x X (px)
    /// \param m_y Y (px)
    /// \param m_width Width (px)
    /// \param m_height Height (px)
    PRect(int m_x, int m_y, int m_width, int m_height);
    /// \brief Create a new rectangle from an existing rectangle
    /// \param rect Rectangle
    PRect(Rectangle *rect);
    /// \brief Destructor
	~PRect(void);

	void draw(SDL_Surface *surface, Color *color);
	void fill(SDL_Surface *surface, Color *color);
	void draw(SDL_Renderer *renderer, Color *color);
    void fill(SDL_Renderer *renderer, Color *color);
};
}

