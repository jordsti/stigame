#ifndef RECTANGLEF_H
#define RECTANGLEF_H
#include "MPointF.h"
#include "MDimensionF.h"
namespace StiGame
{

class Rectangle;

class RectangleF :
        MPointF,
        MDimensionF
{
public:
    RectangleF();
    RectangleF(PointF *pt, DimensionF *dim);
    RectangleF(float m_x, float m_y, float m_width, float m_height);
    virtual ~RectangleF();

    bool contains(PointF *pt);
    bool contains(float m_x, float m_y);
    bool equals(RectangleF *rect);
    bool equals(float m_x, float m_y, float m_width, float m_height);


    PointF point(void);
    DimensionF dimension(void);
    Rectangle toRectangle(void);
};

}

#endif // RECTANGLEF_H
