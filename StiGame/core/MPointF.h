#ifndef MPOINTF_H
#define MPOINTF_H

#include "PointF.h"

namespace StiGame
{

class MPointF :
    public PointF
{
public:
    MPointF();
    MPointF(float m_x, float m_y);
    MPointF(PointF *pt);
    virtual ~MPointF();

    virtual void setX(float m_x);
    virtual void setY(float m_y);

    virtual void setPoint(float m_x, float m_y);
    virtual void setPoint(PointF *pt);
};

}

#endif // MPOINTF_H
