#include "MovingItem.h"

namespace StiGame {

namespace Gui {

namespace Effects {

MovingItem::MovingItem(Item *m_item, BaseGameState *m_state, int m_speed, Point m_startPoint) :
    ItemEffect(m_item, m_state)
{
    speed = m_speed;
    startPoint.setPoint(&m_startPoint);
    endPoint.setPoint(m_item);
}

MovingItem::~MovingItem()
{

}

Point* MovingItem::getStartPoint(void)
{
    return &startPoint;
}

Point* MovingItem::getEndPoint(void)
{
    return &endPoint;
}

int MovingItem::getSpeed(void)
{
    return speed;
}

void MovingItem::setSpeed(int m_speed)
{
    speed = m_speed;
}

void MovingItem::setStartPoint(int x, int y)
{
    startPoint.setPoint(x, y);
}

void MovingItem::setEndPoint(int x, int y)
{
    endPoint.setPoint(x, y);
}

Surface* MovingItem::renderWithEffect(void)
{
    return new Surface(effectBuffer->getSDLSurface());
}

void MovingItem::tickEffect(void)
{
    if(!MPoint::equals(&endPoint))
    {
        setPoint(x + speed, y + speed);

        if(x > endPoint.getX())
        {
            x = endPoint.getX();
        }

        if(y > endPoint.getY())
        {
            y = endPoint.getY();
        }
    }
    else
    {
        setTerminated(true);
    }
}

}

}

}

