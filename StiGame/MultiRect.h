#ifndef MULTIRECT_H
#define MULTIRECT_H
#include "Rectangle.h"
#include <list>
#include "ISprite.h"

namespace StiGame {

/// \class MultiRect
/// \brief Class to test if a point or a rectangle is in one of the rectangles
class MultiRect
{
    public:
		/// \brief Create a new Multi Rect
        MultiRect();
		/// \brief Destructor
        virtual ~MultiRect();
		/// \brief Clear rectangles
        void clear(void);
		/// \brief If the point is in one of the rectangles
		/// \param pt Point to test
		/// \return Contains or not
        bool contains(Point *pt);
		/// \brief If the point is in one of the rectangles
		/// \param p_x X position
		/// \param p_y Y position
		/// \return Contains or not
        bool contains(int p_x, int p_y);
        //test with sprite (ISprite) to be implemented
		/// \brief If the sprite is in one of the rectangles
		/// \param sprite Sprite to test
		/// \return Contains or not
        bool contains(ISprite *sprite);
		/// \brief Add a rectangle to the MultiRect
		/// \param rect Rectangle
        void addRect(Rectangle *rect);
		/// \brief Add a rectangle to the MultiRect
		/// \param r_x X position
		/// \param r_y Y position
		/// \param r_w Width
		/// \param r_h Height
        void addRect(int r_x, int r_y, int r_w, int r_h);
    protected:
		/// \brief Rectangles
        std::list<Rectangle*> rects;
    private:
};

}

#endif // MULTIRECT_H
