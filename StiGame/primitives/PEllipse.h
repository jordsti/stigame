#ifndef PELLIPSE_H
#define PELLIPSE_H
#include "Primitive.h"

namespace StiGame
{
/// \class PEllipse
/// \brief Draw an Ellipse
class PEllipse :
    public Primitive
{
    public:
        /// \brief Empty Constructor
        PEllipse();
        /// \brief Create a new Ellipse with the specified attributes
        /// \param m_x Center X (px)
        /// \param m_y Center Y (px)
        /// \param m_radiusX X Radius
        /// \param m_radiusY Y Radius
        PEllipse(int m_x, int m_y, int m_radiusX, int m_radiusY);
        /// \brief Destructor
        virtual ~PEllipse();
        /// \brief Set Center X
        /// \param m_x Center X (px)
        void setX(int m_x);
        /// \brief Set Center Y
        /// \param m_y Center Y (px)
        void setY(int m_y);
        /// \brief Set X Radius
        /// \param m_radiusX X Radius (px)
        void setRadiusX(int m_radiusX);
        /// \brief Set Y Radius
        /// \param m_radiusY Y Radius (px)
        void setRadiusY(int m_radiusY);
        /// \brief Set Anti-Aliasing value
        /// \param m_aa Anti-Aliasing
        void setAA(bool m_aa);
        /// \brief Get Center X
        /// \return Center X (px)
        int getX(void);
        /// \brief Get Center Y
        /// \return Center Y (px)
        int getY(void);
        /// \brief Get X Radius
        /// \return X Radius (px)
        int getRadiusX(void);
        /// \brief Get Y Radius
        /// \return Y Radius (px)
        int getRadiusY(void);
        /// \brief Get Anti-Aliasing value
        /// \return Anti-Aliasing
        bool getAA(void);


        void draw(SDL_Surface *surface, Color *color);
        void fill(SDL_Surface *surface, Color *color);
        void draw(SDL_Renderer *renderer, Color *color);
        void fill(SDL_Renderer *renderer, Color *color);


    protected:

    private:
        /// \brief Anti-Aliasing
        bool aa;
        /// \brief Center X
        int x;
        /// \brief Center Y
        int y;
        /// \brief Radius X
        int radiusX;
        /// \brief Radius Y
        int radiusY;
};

}

#endif // PELLIPSE_H
