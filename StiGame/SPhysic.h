#ifndef SPHYSIC_H
#define SPHYSIC_H

#include "MPoint.h"

namespace StiGame
{
/// \class SPhysic
/// \brief Basic physic class for game object
/// no sure, will be reworked in the future
class SPhysic :
    public MPoint
{
    public:
        SPhysic();
        virtual ~SPhysic();
        virtual void tick(void);
        void setEndPoint(int m_x, int m_y);
        void setStartPoint(int m_x, int m_y);
        Point *getEndPoint(void);
        Point *getStartPoint(void);
    protected:
        MPoint startPoint;
        MPoint endPoint;
        double acceleration;
        int weight;
        static const int pixels_per_meter;
        static const double gravity_acceleration;
    private:
};

}
#endif // SPHYSIC_H
