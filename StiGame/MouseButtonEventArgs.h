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

class MouseButtonEventArgs
    : public EventArgs
{
    public:
        MouseButtonEventArgs();
        MouseButtonEventArgs(SDL_Event *m_sdlEvent);
        virtual ~MouseButtonEventArgs();

        Sint32 getX(void);
        Sint32 getY(void);

        Uint8 getButton(void);
		MouseButton getMouseButton(void);
        Uint32 getWindowID(void);

        bool isDown(void);

		static MouseButton GetMouseButtonFromSDL(Uint8 mbutton);
		static Uint8 GetSDLButton(MouseButton mbutton);
    protected:
    private:
};

}
#endif // MOUSEBUTTONEVENTARGS_H
