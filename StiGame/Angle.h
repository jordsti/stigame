#ifndef ANGLE_H
#define ANGLE_H

namespace StiGame
{

    namespace Math
    {
        enum AngleUnit { AU_NOUNIT, AU_DEGREE, AU_RADIAN };

		/// \class Angle
		/// \brief Pure abstract class for angle
        class Angle
        {
            public:
				/// \brief Default constructor
                Angle();
				/// \brief Destructor
                virtual ~Angle();
				/// \brief Get angle in the specified unit
				/// \param au Angle Unit
				/// \return Angle
                virtual double getAngle(AngleUnit au) = 0;
				/// \brief Set angle in the specified unit
				/// \param au Angle Unit
				/// \param m_angle Angle
                virtual void setAngle(AngleUnit au, double m_angle) = 0;

                AngleUnit getUnit(void);
                double getAngle(void);
                void setAngle(double m_angle);

            protected:
                double angle;
                AngleUnit unit;
            private:
        };

        class DegreeAngle :
            public Angle
        {
        public:
            DegreeAngle();
            DegreeAngle(double m_angle);
            virtual ~DegreeAngle();

            double getAngle(AngleUnit au);
            void setAngle(AngleUnit au, double m_angle);

        };

        class RadianAngle :
            public Angle
        {
        public:
            RadianAngle();
            RadianAngle(double m_angle);
            virtual ~RadianAngle();

            double getAngle(AngleUnit au);
            void setAngle(AngleUnit au, double m_angle);
        };

        class NoUnitAngle :
            public Angle
        {
        public:
            NoUnitAngle();
            NoUnitAngle(double m_angle);
            virtual ~NoUnitAngle();

            double getAngle(AngleUnit au);
            void setAngle(AngleUnit au, double m_angle);
        };
    }
}

#endif // ANGLE_H
