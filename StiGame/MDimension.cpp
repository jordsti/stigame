#include "MDimension.h"

namespace StiGame
{


MDimension::MDimension()
{
    //ctor
}

MDimension::MDimension(int m_width, int m_height) :
    Dimension(m_width, m_height)
{

}

MDimension::MDimension(DimensionStruct *dim) :
    Dimension(dim)
{

}

void MDimension::setWidth(int m_width)
{
    width = m_width;
}

void MDimension::setHeight(int m_height)
{
    height = m_height;
}

void MDimension::setDimension(int m_width, int m_height)
{
    width = m_width;
    height = m_height;
}

MDimension::~MDimension()
{
    //dtor
}

}
