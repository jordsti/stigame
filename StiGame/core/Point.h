#ifndef POINT_H
#define POINT_H

#include "SDL.h"
#include <string>
#include "Matrix.h"


namespace StiGame
{

class PointF;

struct PointStruct
{
    int x;
    int y;
};

/// \class Point
/// \brief 2-dimension point
class Point
{
protected:
	/// \brief x position (px)
	int x;
	/// \brief y position (px)
	int y;
public:
	/// \brief Create an empty point (0, 0)
	Point(void);

	Point(PointStruct *pt);

	/// \brief Create a point with the specified position
	/// \param m_x x position (px)
	/// \param m_y y position (px)
	Point(int m_x,int m_y);
	/// \brief Destructor
	virtual ~Point(void);
	/// \brief Get the x position
	/// \return x position (px)
	int getX(void);
	/// \brief Get the y position
	/// \return y position (px)
	int getY(void);

	PointStruct* getPointStruct(void);

	SDL_Point* getSDLPoint(void);
	void updateSDLPoint(SDL_Point *sdlPt);

    Point& operator+(Point& pt);

    Point& operator-(Point& pt);

	virtual bool equals(int m_x, int m_y);
	virtual bool equals(Point *pt);
	virtual bool equals(SDL_Point *pt);

    virtual Point diffPoint(Point *pt);
    virtual double distanceWith(Point *pt);

    PointF toPointF(void);
    Math::Matrix homogenousMatrix(void);

};

}


#endif
