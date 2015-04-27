#ifndef MOVINGITEM_H
#define MOVINGITEM_H
#include "ItemEffect.h"

namespace StiGame {

namespace Gui {

namespace Effects {
class MovingItem :
        public ItemEffect
{
public:
    MovingItem(Item *m_item, BaseGameState *m_state, int m_speed, Point m_startPoint, Point m_endPoint);
    virtual ~MovingItem();

    Point* getStartPoint(void);
    Point* getEndPoint(void);
    int getSpeed(void);

    void setSpeed(int m_speed);
    void setStartPoint(int x, int y);
    void setEndPoint(int x, int y);
protected:
    virtual Surface *renderWithEffect(void);
    virtual void tickEffect(void);
private:
    Point startPoint;
    Point endPoint;
    int speed;
};

}
}
}
#endif // MOVINGITEM_H
