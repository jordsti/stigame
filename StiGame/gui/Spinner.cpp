#include "Spinner.h"

namespace StiGame
{

namespace Gui
{

const int Spinner::DEFAULT_WIDTH = 120;
const int Spinner::DEFAULT_HEIGHT = 22;

//todo
//add down & up for value selection

Spinner::Spinner() :
    Item("Spinner"),
    FontSupport()
{
    width = DEFAULT_WIDTH;
    height = DEFAULT_HEIGHT;
    selectedItem = nullptr;
    selectedIndex = -1;
}

Spinner::~Spinner()
{
    clearBuffer();
}

int Spinner::getSelectedIndex(void)
{
    return selectedIndex;
}

ValueObject* Spinner::getSelectedItem(void)
{
    return selectedItem;
}

Surface* Spinner::render(void)
{
    //todo
}

void Spinner::clearBuffer()
{
    //clearing all strings buffer
    auto mit(itemsBuffer.begin()), mend(itemsBuffer.end());
    for(;mit!=mend;++mit)
    {
        delete mit->second;
    }

    itemsBuffer.clear();
}

void Spinner::addItem(ValueObject *m_item)
{
    //ValueObject Id must be unique !
    items.push_back(m_item);
    //generating the string buffer
    Surface *str = font->renderText(m_item->getText(), foreground);

    itemsBuffer.insert(std::make_pair(m_item->getId(), str));

    if(selectedIndex == -1)
    {
        //setting the first item as the selected one
        selectedIndex = 0;
        selectedItem = items[selectedIndex];
    }
}

void Spinner::setFont(Font *m_font)
{
    font = m_font;
    //todo
    //need to rerender all those value objects
    clearBuffer();

    auto lit(items.begin()), lend(items.end());
    for(;lit!=lend;++lit)
    {
        ValueObject *item = (*lit);
        Surface *str = font->renderText(item->getText(), foreground);

        itemsBuffer.insert(std::make_pair(item->getId(), str));
    }

}

void Spinner::clearItems(void)
{
    //todo clear all items
}

}

}
