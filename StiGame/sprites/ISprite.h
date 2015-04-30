#ifndef ISPRITE_H
#define ISPRITE_H
#include <string>
#include "Dimension.h"
#include "MPoint.h"
#include "SDL.h"


namespace StiGame
{
/// \class ISprite
/// \brief Generic class for Sprite
class ISprite :
    public MPoint,
    public Dimension
{
    public:
		/// \brief Create an empty Sprite
        ISprite(void);
		/// \brief Destructor
        virtual ~ISprite();
		/// \brief Render Sprite
        virtual void render(void) = 0;
		/// \brief Move Sprite
		/// \param dx Delta X
		/// \param dy Delta Y
        void move(int dx, int dy);
		/// \brief Get SDL_Rect of the Sprite
		/// \return SDL_Rect
        SDL_Rect* getSDLRect(void);
		/// \brief Convert an Integer to a String
		/// \param i Integer
		/// \return String value
        static std::string toString(int i);
		/// \brief Get the center point of the sprite
		/// \return Center SPoint
		Point* getCenter(void);
        /// \brief Tick the Sprite
        virtual void tick(void) = 0;
    protected:
    private:
};

}

#endif // ISPRITE_H
