#ifndef RADIOGROUP_H
#define RADIOGROUP_H

#include <list>
#include "RadioButton.h"

namespace StiGame {

namespace Gui
{

/// \class RadioGroup
/// \brief Radio Group for Radio button
class RadioGroup
{
    public:
	/// \brief Create a new Radio Group
        RadioGroup();
	/// \brief Destructor
        virtual ~RadioGroup();
	/// \brief Add an item to the group
	/// \param radio Radio Button
        void addItem(RadioButton *radio);
	/// \brief Remove an item from the group
	/// \param radio Radio Button
        void removeItem(RadioButton *radio);
	/// \brief Set the specified Radio Button active
	/// \param radio Radio Button to set active
        void setActive(RadioButton *radio);
	/// \brief Get the active Radio Button
	/// \return Radio button
        RadioButton *getActive(void);
    protected:
	/// \brief Radio Button of this group
        std::list<Gui::RadioButton*> radioButtons;
	/// \brief Current active Radio Button
        RadioButton *active;
    private:
};

}

}

#endif // RADIOGROUP_H
