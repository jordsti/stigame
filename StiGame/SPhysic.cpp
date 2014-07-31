#include "SPhysic.h"

namespace StiGame
{

const int SPhysic::pixels_per_meter = 100;
const double SPhysic::gravity_acceleration = 9.81;

SPhysic::SPhysic()
{
    //ctor
    startPoint = MPoint();
    endPoint = MPoint();
    weight = 0;
    acceleration = 0;
}

void SPhysic::setEndPoint(int m_x, int m_y)
{
    endPoint.setPoint(m_x, m_y);
}

void SPhysic::setStartPoint(int m_x, int m_y)
{
    startPoint.setPoint(m_x, m_y);
}

Point *SPhysic::getEndPoint(void)
{
    return &endPoint;
}

Point *SPhysic::getStartPoint(void)
{
    return &startPoint;
}

SPhysic::~SPhysic()
{
    //dtor
}

void SPhysic::tick(void)
{

}

}
