
#include "Dimension.h"
namespace StiGame
{
	bool Dimension::isEmpty(void)
	{
		return (width == 0 && height == 0);
	}

    Dimension::Dimension(DimensionStruct *dim)
    {
        width = dim->width;
        height = dim->height;
    }

	Dimension::Dimension(void)
	{
		width = 0;
		height = 0;
	}

	Dimension::Dimension(int w, int h)
	{
		width = w;
		height = h;
	}


	int Dimension::getWidth(void)
	{
		return width;
	}

	int Dimension::getHeight(void)
	{
		return height;
	}

	DimensionStruct* Dimension::getDimensionStruct(void)
	{
	    DimensionStruct *dim = new DimensionStruct();
	    dim->width = width;
	    dim->height = height;

	    return dim;
	}

    Dimension::~Dimension()
	{

	}

}
