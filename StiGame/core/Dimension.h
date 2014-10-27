#ifndef DIMENSION_H
#define DIMENSION_H

#include "SDL.h"

namespace StiGame
{

    struct DimensionStruct
    {
        int width;
        int height;
    };

	/// \class Dimension
	/// \brief 2-Dimension size
	class Dimension
	{
	public:
		/// \brief Is the dimension empty (0,0)
		///  \return True if empty
		virtual bool isEmpty(void);
		/// \brief Create an empty dimension (0,0)
		Dimension(void);

		Dimension(DimensionStruct *dim);

		/// \brief Create a new dimension with specified size
		Dimension(int m_width,int m_height);
		virtual ~Dimension(void);
		/// \brief Get the width of the dimension
		/// \return width (px)
		int getWidth(void);

		/// \brief Get the height of the dimension
		/// \return height (px)
		int getHeight(void);

		DimensionStruct* getDimensionStruct(void);

	protected:
		/// \brief Width (px)
		int width;

		/// \brief Height (px)
		int height;
	};

}

#endif

