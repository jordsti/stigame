#include "PEllipse.h"
#include "SDL2_gfxPrimitives.h"
namespace StiGame
{


PEllipse::PEllipse()
{
    //ctor
    x = 0;
    y = 0;
    radiusX = 0;
    radiusY = 0;
    aa = false;
}

PEllipse::PEllipse(int m_x, int m_y, int m_radiusX, int m_radiusY)
{
    x = m_x;
    y = m_y;
    radiusX = m_radiusX;
    radiusY = m_radiusY;
    aa = false;
}

void PEllipse::setX(int m_x)
{
    x = m_x;
}

void PEllipse::setY(int m_y)
{
    y = m_y;
}

void PEllipse::setRadiusX(int m_radiusX)
{
    radiusX = m_radiusX;
}

void PEllipse::setRadiusY(int m_radiusY)
{
    radiusY = m_radiusY;
}

void PEllipse::setAA(bool m_aa)
{
    aa = m_aa;
}

int PEllipse::getX(void)
{
    return x;
}

int PEllipse::getY(void)
{
    return y;
}

int PEllipse::getRadiusX(void)
{
    return radiusX;
}

int PEllipse::getRadiusY(void)
{
    return radiusY;
}

bool PEllipse::getAA(void)
{
    return aa;
}

void PEllipse::draw(SDL_Surface *surface, Color *color)
{
    //not implemented
}

void PEllipse::fill(SDL_Surface *surface, Color *color)
{
    //not implemented
}

void PEllipse::draw(SDL_Renderer *renderer, Color *color)
{
    if(aa)
    {
        aaellipseRGBA(renderer, x, y, radiusX, radiusY, color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
    }
    else
    {
        ellipseRGBA(renderer, x, y, radiusX, radiusY, color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
    }
}

void PEllipse::fill(SDL_Renderer *renderer, Color *color)
{
    filledEllipseRGBA(renderer, x, y, radiusX, radiusY, color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
}

PEllipse::~PEllipse()
{
    //dtor
}

}
