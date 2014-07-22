#ifndef KEYEVENTARGS_H
#define KEYEVENTARGS_H
#include "EventArgs.h"
#include <string>
namespace StiGame
{

enum KeyState {KS_UP, KS_DOWN};

/// \class KeyEventArgs
/// \brief Key Event Arguments
class KeyEventArgs  :
    public EventArgs
{
    public:
		/// \brief Create a new Key Event Arguments
		/// \param evt SDL_Event
        KeyEventArgs(SDL_Event *evt);
		/// \brief Destructor
        virtual ~KeyEventArgs();
		/// \brief Get Key State
		/// \return State
        KeyState getState(void);
		/// \brief Get Unicode Character
		/// \return Character
        char getUnicode(void);
		/// \brief Get SDL Keyboard Event
		/// \return SDL_KeyboardEvent
        SDL_KeyboardEvent *getKeyboardEvent(void);
		/// \brief Get Key Name
		/// \return String Key Value
        std::string getKeyName(void);
    protected:
		/// \brief Key State
        KeyState state;
    private:
};

}

#endif // KEYEVENTARGS_H
