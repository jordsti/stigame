#include "MPoint.h"
namespace StiGame
{

MPoint::MPoint() :
    Point()
{
    //ctor
}

MPoint::MPoint(int m_x, int m_y) :
    Point(m_x, m_y)
{

}

MPoint::MPoint(PointStruct *pt) :
    Point(pt)
{

}

void MPoint::setX(int m_x)
{
    x = m_x;
}

void MPoint::setY(int m_y)
{
    y = m_y;
}

void MPoint::set(int m_x, int m_y)
{
    x = m_x;
    y = m_y;
}

MPoint::~MPoint()
{
    //dtor
}

}
