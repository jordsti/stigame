#ifndef PELLIPSE_H
#define PELLIPSE_H
#include "Primitive.h"

namespace StiGame
{

class PEllipse :
    public Primitive
{
    public:
        PEllipse();
        PEllipse(int m_x, int m_y, int m_radiusX, int m_radiusY);
        virtual ~PEllipse();
        void setX(int m_x);
        void setY(int m_y);
        void setRadiusX(int m_radiusX);
        void setRadiusY(int m_radiusY);
        void setAA(bool m_aa);
        int getX(void);
        int getY(void);
        int getRadiusX(void);
        int getRadiusY(void);
        bool getAA(void);
        void draw(SDL_Surface *surface, Color *color);
        void fill(SDL_Surface *surface, Color *color);
        void draw(SDL_Renderer *renderer, Color *color);
        void fill(SDL_Renderer *renderer, Color *color);


    protected:

    private:
        bool aa;
        int x;
        int y;
        int radiusX;
        int radiusY;
};

}

#endif // PELLIPSE_H
