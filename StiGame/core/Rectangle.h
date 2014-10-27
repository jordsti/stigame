#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "MDimension.h"
#include "MPoint.h"
#include "SDL.h"

namespace StiGame
{
/// \class Rectangle
/// \brief Rectangle
class Rectangle :
	public MDimension, public MPoint
{
public:
	/// \brief Empty rectangle
	Rectangle(void);
	/// \brief Rectangle with specified parameters
	/// \param m_x x position (px)
	/// \param m_y y position (px)
	/// \param m_width width (px)
	/// \param m_height height (px)
	Rectangle(int m_x, int m_y, int m_width, int m_height);
	/// \brief Destructor
	virtual ~Rectangle(void);

	/// \brief Get a new SDL_Rect with the parameter of this rectangle
	/// \return Pointer to a new SDL_Rect
	SDL_Rect *getSDLRect(void);

	void updateSDLRect(SDL_Rect *rect);

	/// \brief Update members from a SDL_Rect
	/// \param rect SDL_Rect pointer
	void fromSDLRect(SDL_Rect *rect);

	/// \brief Is the point is in this rectangle
	/// \param pt Point pointer
	bool contains(Point *pt);

	/// \brief Is the point is in this rectangle
	/// \param p_x x position (px)
	/// \param p_y y position (px)
	bool contains(int p_x, int p_y);

	/// \brief If this rectangle intersect with another rectangle
	/// \param rect Rectangle
	/// \return intersect or not
    bool intersect(Rectangle *rect);

	/// \brief If the value is in the range
	/// \param value value to test
	/// \param min Minimum
	/// \param max Maximum
	/// \return in range or not
    static bool valueInRange(int value, int min, int max);

	/// \brief Get Left Top point
	/// \return Point
	Point *getLeftTop(void);

	/// \brief Get Left Bottom point
	/// \return Point
	Point *getLeftBottom(void);

	/// \brief Get Right Top point
	/// \return Point
	Point *getRightTop(void);

	/// \brief Get Right Bottom point
	/// \return Point
	Point *getRightBottom(void);

	virtual bool equals(int r_x, int r_y, int r_w, int r_h);
	virtual bool equals(Rectangle *rect);
	virtual bool equals(SDL_Rect *rect);

	virtual void setRectangle(int m_x, int m_y, int m_width, int m_height);

	//Utils

	static void Copy(SDL_Rect *src, SDL_Rect *copy);
	static void Copy(Rectangle *src, Rectangle *copy);
	static void Copy(Rectangle *src, SDL_Rect *copy);
	static void Copy(SDL_Rect *src, Rectangle *copy);
};
}

#endif

