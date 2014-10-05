#include "DimensionF.h"

namespace StiGame
{

DimensionF::DimensionF()
{
    width = 0.0f;
    height = 0.0f;
}

DimensionF::DimensionF(float m_width, float m_height)
{
    width = m_width;
    height = m_height;
}

DimensionF::~DimensionF()
{

}

bool DimensionF::isEmpty(void)
{
    return (width == 0.0f && height == 0.0f);
}

float DimensionF::getWidth(void)
{
    return width;
}

float DimensionF::getHeight(void)
{
    return height;
}

Dimension DimensionF::toDimension(void)
{
    return Dimension(width, height);
}

}
