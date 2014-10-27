#ifndef VECTOR_H
#define VECTOR_H
#include "Angle.h"
#include "Dimension.h"

namespace StiGame
{

namespace Math
{

/// \class Vector
/// \brief Vector for move path
class Vector
{
    public:
		/// \brief Create an empty vector
        Vector();

		/// \brief Create a vector with specified length in x and y
		/// \param m_x length for x (px)
		/// \param m_y length for y (px)
        Vector(int m_x, int m_y);

		/// \brief Create a vector with specified length and angle
		/// \param m_length Length (px)
		/// \param angle Angle (rad)
        Vector(int m_length, Angle* angle);

		/// \brief Vector destructor
        virtual ~Vector();

		/// \brief Vector length
        /// \return Length (px)
		int length(void);

		/// \brief Vector angle
		/// \return Angle (rad)
        Angle* getAngle(void);


		/// \brief Get X length
		/// \return X length (px)
        int getX(void);

		/// \brief Get Y length
		/// \return Y length (px)
        int getY(void);

		/// \brief Set X Length
		/// \param m_x x length (px)
        void setX(int m_x);

		/// \brief Set Y Length
		/// \param m_y y length (px)
        void setY(int m_y);

		/// \brief Get Vector dimension
		/// \return Pointer to Vector Dimension
        Dimension* getDimension(void);

    protected:
		/// \brief x length
        int x;
		/// \brief y length
        int y;
};

}
}
#endif // VECTOR_H
