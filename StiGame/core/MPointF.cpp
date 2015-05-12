#include "MPointF.h"

namespace StiGame
{

MPointF::MPointF() :
    PointF()
{

}

MPointF::MPointF(float m_x, float m_y) :
    PointF(m_x, m_y)
{

}

MPointF::MPointF(PointF *pt) :
    PointF(pt)
{

}

MPointF::~MPointF()
{

}

void MPointF::setX(float m_x)
{
    x = m_x;
}

void MPointF::setY(float m_y)
{
    y = m_y;
}

void MPointF::setPoint(float m_x, float m_y)
{
    x = m_x;
    y = m_y;
}

void MPointF::setPoint(PointF *pt)
{
    x = pt->getX();
    y = pt->getY();
}

}
