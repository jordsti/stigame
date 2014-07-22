#ifndef VIEWPORTAREA_H
#define VIEWPORTAREA_H

#include "MDimension.h"
#include "MPoint.h"

namespace StiGame
{

class ViewportArea
{
    public:
        ViewportArea();
        virtual ~ViewportArea();

        Point* getViewPoint(void);
        void setViewPoint(int m_x, int m_y);

        MDimension* getViewDimension(void);
        void setViewDimension(int m_width, int m_height);

        MDimension* getWorldDimension(void);
        void setWorldDimension(int m_width, int m_height);

    protected:
        MPoint viewPoint;
        MDimension viewDimension;
        MDimension worldDimension;
    private:
};

}

#endif // VIEWPORTAREA_H
