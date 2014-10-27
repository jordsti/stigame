#include "Angle.h"
#include "MathTK.h"

namespace StiGame
{
    namespace Math
    {
        Angle::Angle()
        {
            //ctor
            angle = 0;
            unit = AU_NOUNIT;
        }

        AngleUnit Angle::getUnit(void)
        {
            return unit;
        }

        double Angle::getAngle(void)
        {
            return angle;
        }

        void Angle::setAngle(double m_angle)
        {
            angle = m_angle;
        }

        Angle::~Angle()
        {
            //dtor
        }

        DegreeAngle::DegreeAngle()
        {
            angle = 0;
            unit = AU_DEGREE;
        }

        DegreeAngle::DegreeAngle(double m_angle)
        {
            angle = m_angle;
            unit = AU_DEGREE;
        }

        double DegreeAngle::getAngle(AngleUnit au)
        {
            if(au == AU_RADIAN)
            {
                return TK::degree_to_rad(angle);
            }
            else
            {
                return angle;
            }
        }

        void DegreeAngle::setAngle(AngleUnit au, double m_angle)
        {
            if(au == AU_RADIAN)
            {
                angle = TK::rad_to_degree(m_angle);
            }
            else
            {
                angle = m_angle;
            }
        }

        DegreeAngle::~DegreeAngle()
        {

        }

        RadianAngle::RadianAngle()
        {
            angle = 0;
            unit = AU_RADIAN;
        }

        RadianAngle::RadianAngle(double m_angle)
        {
            angle = m_angle;
            unit = AU_RADIAN;
        }

        double RadianAngle::getAngle(AngleUnit au)
        {
            if(au == AU_DEGREE)
            {
                return TK::rad_to_degree(angle);
            }
            else
            {
                return angle;
            }
        }

        void RadianAngle::setAngle(AngleUnit au, double m_angle)
        {
            if(au == AU_DEGREE)
            {
                angle = TK::degree_to_rad(m_angle);
            }
            else
            {
                angle = m_angle;
            }
        }

        RadianAngle::~RadianAngle()
        {

        }

        NoUnitAngle::NoUnitAngle()
        {
            angle = 0;
            unit = AU_NOUNIT;
        }

        NoUnitAngle::NoUnitAngle(double m_angle)
        {
            angle = m_angle;
            unit = AU_NOUNIT;
        }

        double NoUnitAngle::getAngle(AngleUnit au)
        {
            return angle;
        }

        void NoUnitAngle::setAngle(AngleUnit au, double m_angle)
        {
            angle = m_angle;
        }

        NoUnitAngle::~NoUnitAngle()
        {

        }
    }
}

