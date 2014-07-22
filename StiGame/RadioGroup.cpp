#include "RadioGroup.h"

namespace StiGame {

namespace Gui
{

RadioGroup::RadioGroup()
{
    //ctor
    active = 0;
}

void RadioGroup::addItem(RadioButton *radio)
{
    radioButtons.push_back(radio);
    radio->setGroup(this);
}

void RadioGroup::removeItem(RadioButton *radio)
{
    radioButtons.remove(radio);
}

void RadioGroup::setActive(RadioButton *radio)
{
    std::list<RadioButton*>::iterator lit(radioButtons.begin()), lend(radioButtons.end());
    active = radio;
    for(; lit!=lend; ++lit)
    {
        if((*lit)!=radio)
        {
            if((*lit)->isChecked())
            {
                (*lit)->setChecked(false);
            }
        }
        else
        {
            if(!(*lit)->isChecked())
            {
                (*lit)->setChecked(true);
            }
        }
    }
}

RadioButton *RadioGroup::getActive(void)
{
    return active;
}

RadioGroup::~RadioGroup()
{
    //dtor
}

}

}
