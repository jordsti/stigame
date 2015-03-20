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
	/// \brief Create a point from a PointStruct
	/// \param pt Point Struct pointer
	Point(PointStruct *pt);
	/// \brief Create a point from another point
	/// \param pt Point
	Point(Point *pt);

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

	/// \brief Return a new PointStruct with the current coord
	/// \return Point Struct Pointer
	PointStruct* getPointStruct(void);
	/// \brief Return a new SDL_Point with the current coord
	/// \return SDL_Point Pointer
	SDL_Point* getSDLPoint(void);
	/// \brief Update the SDL_Point with the current coord
	/// \param sdlPt Point to update
	void updateSDLPoint(SDL_Point *sdlPt);

	/// \brief Point addition
	Point& operator+(Point& pt);
	/// \brief Point substract
	Point& operator-(Point& pt);
	
	/// \brief Point equals coord
	/// \param m_x X coord
	/// \param m_y Y coord
	/// \return Equals or not
	virtual bool equals(int m_x, int m_y);
	/// \brief Point equals another point
	/// \param pt Point to compare
	/// \return Equals or not
	virtual bool equals(Point *pt);
	/// \brief Point equals another point
	/// \param pt Point to compare
	/// \return Equals or not
	virtual bool equals(SDL_Point *pt);
	
	/// \brief Difference with another point
	/// \param pt Point
	/// \return Difference Point
	virtual Point diffPoint(Point *pt);
	/// \brief Distance with another point
	/// \param pt Point
	/// \return Distance
	virtual double distanceWith(Point *pt);
	
	/// \brief Convert to PointF
	/// \return PointF
	PointF toPointF(void);
	/// \brief Convert to a Matrix
	/// \return Matrix Point
	Math::Matrix homogenousMatrix(void);

};

}


#endif
