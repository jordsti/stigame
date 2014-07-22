#include "MathTK.h"
#include <cmath>

namespace StiGame
{

    namespace Math
    {

        Constants::Constants()
        {
            //ctor
        }

        Constants::~Constants()
        {
            //dtor
        }

        const double Constants::PI = 3.14159265359;
        const double Constants::HALF_TURN_DEGREE = 180.0000;
        const double Constants::GOLDEN_RATIO = 1.61803398875;

        TK::TK()
        {

        }

        TK::~TK()
        {

        }

        double TK::rad_to_degree(double rad)
        {
            double deg = ( rad * Constants::HALF_TURN_DEGREE ) / Constants::PI;
            return deg;
        }

        double TK::degree_to_rad(double deg)
        {
            double rad = ( deg * Constants::PI ) / Constants::HALF_TURN_DEGREE;
            return rad;
        }

        double TK::Pythagoras(double d_x, double d_y)
        {
            return sqrt( pow(d_x, 2.0) + pow(d_y, 2.0) );
        }

        Angle* TK::CreateAngle(AngleUnit au, double angle)
        {
            Angle *o_angle = 0;

            if(au == AU_DEGREE)
            {
                o_angle = new DegreeAngle(angle);
            }
            else if(au == AU_RADIAN)
            {
                o_angle = new RadianAngle(angle);
            }
            else if(au == AU_NOUNIT)
            {
                o_angle = new NoUnitAngle(angle);
            }

            return o_angle;
        }

        double TK::DistanceBetween(Point *pt1, Point *pt2)
        {
            return DistanceBetween(pt1->getX(),
                                   pt1->getY(),
                                   pt2->getX(),
                                   pt2->getY());
        }

        double TK::DistanceBetween(int x1, int y1, int x2, int y2)
        {
            double d_x1 = (double)x1;
            double d_x2 = (double)x2;
            double d_y1 = (double)y1;
            double d_y2 = (double)y2;

            return Pythagoras(d_x2 - d_x1, d_y2 - d_y1);
        }

        double TK::DistanceBetween(Dimension *dim)
        {
            double d_x = (double)dim->getWidth();
            double d_y = (double)dim->getHeight();

            return Pythagoras(d_x, d_y);
        }
    }
}
