#ifndef BASEGAMEACTION_H
#define BASEGAMEACTION_H

#include <string>
#include "ActionMap.h"

namespace StiGame
{

/// \class BaseGameAction
/// \brief Base Class to inherit to add Game Action
class BaseGameAction
{
    public:
        /// \brief Constructor
        BaseGameAction();
        /// \brief Destructor
        virtual ~BaseGameAction();
        /// \brief Test KeyCode
        /// \param keycode Key Code to test
        virtual void testKeycode(SDL_Keycode keycode);
        /// \brief Test Mouse Button with SDL Mouse Button ID
        /// \param button SDL Mouse Button ID
        virtual void testMouse(Uint8 button);
        /// \brief Test Mouse Button Event
        /// \param mbEvt Built-in Mouse Button Event
        virtual void testMouseButton(MouseButtonEventArgs *mbEvt);
        /// \brief Get Game Action Name
        /// \return Name
        std::string getName(void);
        /// \brief Get the Action Map (Key or mouse button)
        /// \return Action Map
        ActionMap* getActionMap(void);
        /// \brief Set the Action Map for this action
        /// \param m_actionMap Action Map
        void setActionMap(ActionMap *m_actionMap);
    protected:
        /// \brief Initialize the class fields
        void initialize(void);
        /// \brief Game Action Name
        std::string name;
        /// \brief Action Map
        ActionMap *actionMap;
        /// \brief Method to override to do the specified event
        virtual void doAction(void) = 0;
    private:
};

}

#endif // BASEGAMEACTION_H
