#include "RectangleF.h"
#include "Rectangle.h"

namespace StiGame
{

RectangleF::RectangleF() :
    MPointF(),
    MDimensionF()
{

}

RectangleF::RectangleF(PointF *pt, DimensionF *dim) :
    MPointF(pt),
    MDimensionF(dim)
{

}

RectangleF::RectangleF(float m_x, float m_y, float m_width, float m_height) :
    MPointF(m_x, m_y),
    MDimensionF(m_width, m_height)
{

}

RectangleF::~RectangleF()
{

}

bool RectangleF::contains(PointF *pt)
{
    return contains(pt->getX(), pt->getY());
}

bool RectangleF::contains(float m_x, float m_y)
{
    return ( m_x >= x &&
             m_x <= x + width &&
             m_y >= y &&
             m_y <= y + height );
}

bool RectangleF::equals(RectangleF *rect)
{
    return equals(rect->getX(), rect->getY(), rect->getWidth(), rect->getHeight());
}

bool RectangleF::equals(float m_x, float m_y, float m_width, float m_height)
{
    return ( x == m_x &&
             y == m_y &&
             width == m_width &&
             height == m_height );
}

PointF RectangleF::point(void)
{
    PointF pt (x, y);
    return pt;
}

DimensionF RectangleF::dimension(void)
{
    DimensionF dim (width, height);
    return dim;
}

Rectangle RectangleF::toRectangle(void)
{
    Rectangle rect (x, y, width, height);
    return rect;
}

}
