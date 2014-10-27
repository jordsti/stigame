#include "ViewportArea.h"


namespace StiGame
{

ViewportArea::ViewportArea()
{
    viewPoint = MPoint();
    viewDimension = MDimension();
    worldDimension = MDimension();
}

ViewportArea::~ViewportArea()
{
    //dtor
}

Point* ViewportArea::getViewPoint(void)
{
    return &viewPoint;
}

void ViewportArea::setViewPoint(int m_x, int m_y)
{
    viewPoint.setX(m_x);
    viewPoint.setY(m_y);
}

MDimension* ViewportArea::getViewDimension(void)
{
    return &viewDimension;
}

void ViewportArea::setViewDimension(int m_width, int m_height)
{
    viewDimension.setWidth(m_width);
    viewDimension.setHeight(m_height);
}

MDimension* ViewportArea::getWorldDimension(void)
{
    return &worldDimension;
}

void ViewportArea::setWorldDimension(int m_width, int m_height)
{
    worldDimension.setWidth(m_width);
    worldDimension.setHeight(m_height);
}


}
