#pragma once
#include "SDL.h"
#include "Primitive.h"
namespace StiGame
{
/// \class PCircle
/// \brief Circle primitive class
class PCircle : public Primitive
{
private:
    /// \brief Center X (px)
    int x;
    /// \brief Center Y (px)
    int y;
    /// \brief Radius (px)
	double radius;

public:
	/// \brief Empty circle
	PCircle(void);
	/// \brief Create a circle with specified middle
	/// \param m_x middle x
	/// \param m_y middle y
	PCircle(int m_x,int m_y);
	/// \brief Create a circle with specified middle and radius
	/// \param m_x middle x
	/// \param m_y middle y
	/// \param m_radius radius (px)
	PCircle(int m_x,int m_y, double m_radius);
	/// \brief Destructor
	~PCircle(void);


	void fill(SDL_Surface *surface, Color *color);
	void draw(SDL_Surface *surface, Color *color);

    void draw(SDL_Renderer *renderer, Color *color);
    void fill(SDL_Renderer *renderer, Color *color);

    /// \brief Get Center X
    /// \return X (px)
	int getX(void);
    /// \brief Set Center C
    /// \param m_x X (px)
	void setX(int m_x);
    /// \brief Get Center Y
    /// \return Y (px)
	int getY(void);
    /// \brief Set Center Y
    /// \param m_y Y (px)
    void setY(int m_y);
    /// \brief Set Center Point
    /// \param m_x X (px)
    /// \param m_y Y (px)
    void setMiddle(int m_x, int m_y);
    /// \brief Get Radius
    /// \return Radius (px)
	double getRadius(void);
    /// \brief Set Radius
    /// \param m_radius Radius (px)
    void setRadius(double m_radius);
};
}

