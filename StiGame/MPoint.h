#ifndef MPOINT_H
#define MPOINT_H

#include "Point.h"

namespace StiGame
{

class MPoint :
    public Point
{
    public:
        /// \brief Create an empty point (0, 0)
        MPoint();

        /// \brief Create a point with the specified position
        /// \param m_x x position (px)
        /// \param m_y y position (px)
        MPoint(int m_x, int m_y);
        MPoint(PointStruct *pt);

        virtual ~MPoint();

        /// \brief Set the position
        /// \param m_x x position (px)
        /// \param m_y y position (px)
        // this method will probably be deprecated
        //void set(int m_x,int m_y);

        virtual void setPoint(int m_x, int m_y);

        /// \brief Set the x position
        /// \param m_x x position (px)
        virtual void setX(int m_x);

        /// \brief Set the y position
        /// \param m_y y position (px)
        virtual void setY(int m_y);
    protected:
    private:
};

}
#endif // MPOINT_H
