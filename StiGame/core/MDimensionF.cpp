#include "MDimensionF.h"

namespace StiGame
{

MDimensionF::MDimensionF() :
    DimensionF()
{

}

MDimensionF::MDimensionF(float m_width, float m_height) :
    DimensionF(m_width, m_height)
{

}

MDimensionF::~MDimensionF()
{

}

void MDimensionF::setWidth(float m_width)
{
    width = m_width;
}

void MDimensionF::setHeight(float m_height)
{
    height = m_height;
}

void MDimensionF::setDimension(float m_width, float m_height)
{
    width = m_width;
    height = m_height;
}

}
