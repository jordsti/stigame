#ifndef MATHTK_H
#define MATHTK_H

#include "Angle.h"
#include "Point.h"
#include "Dimension.h"

namespace StiGame
{

    namespace Math
    {

        class Constants
        {
            public:
                Constants();
                virtual ~Constants();
                static const double PI;
                static const double HALF_TURN_DEGREE;
                static const double GOLDEN_RATIO;
            protected:
            private:
        };

        class TK
        {
        public:
            TK();
            virtual ~TK();
            static double rad_to_degree(double rad);
            static double degree_to_rad(double deg);
            static Angle* CreateAngle(AngleUnit au, double angle);
            static double Pythagoras(double d_x, double d_y);
            static double DistanceBetween(Point *pt1, Point *pt2);
            static double DistanceBetween(int x1, int y1, int x2, int y2);
            static double DistanceBetween(Dimension *dim);
            static double round(double nb);
        };

    }

}

#endif // MATHTK_H
