#ifndef MOUSEBUTTONEVENTARGS_H
#define MOUSEBUTTONEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

enum MouseButton {
	MB_LEFT = 1,
	MB_MIDDLE = 2,
	MB_RIGHT = 3,
	MB_X1 = 4,
	MB_X2 = 5
};

/// \class MouseButtonEventArgs
/// \brief Mouse Button Event
class MouseButtonEventArgs
    : public EventArgs
{
    public:
        /// \brief New Empty Mouse Button Event
        MouseButtonEventArgs();
        /// \brief New Mouse Button Event based on SDL Event
        /// \param m_sdlEvent Underlying SDL Event
        MouseButtonEventArgs(SDL_Event *m_sdlEvent);
        /// \brief Destructor
        virtual ~MouseButtonEventArgs();
        /// \brief Get Mouse X Position
        /// \return X (px)
        Sint32 getX(void);
        /// \brief Get Mouse Y Position
        /// \return Y (px)
        Sint32 getY(void);
        /// \brief Get the Mouse Button pressed
        /// \return Mouse Button ID (SDL2)
        Uint8 getButton(void);
        /// \brief Get the mouse button pressed
        /// \return Mouse Button Enum Value
		MouseButton getMouseButton(void);
        /// \brief Get Window ID
        /// \return SDL Window ID
        Uint32 getWindowID(void);
        /// \brief Is the button down
        /// \return is down or not
        bool isDown(void);
        /// \brief Convert SDL Mouse Button ID to Mouse Button Enum
        /// \param mbutton SDL Mouse Button ID
        /// \return Mouse Button Enum Value
		static MouseButton GetMouseButtonFromSDL(Uint8 mbutton);
        /// \brief Convert a Mouse Button Enum Value to SDL Mouse Button ID
        /// \param mbutton Mouse Button Enum Value
        /// \return SDL Mouse Button ID
		static Uint8 GetSDLButton(MouseButton mbutton);
    protected:
    private:
};

}
#endif // MOUSEBUTTONEVENTARGS_H
