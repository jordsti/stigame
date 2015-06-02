#include "Spinner.h"
#include "PRect.h"
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
    //todo get arrow from style
    upArrow = nullptr;
    downArrow = nullptr;
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
    Surface *buffer = new Surface(width, height);
    buffer->fill(background);


    //current selected element
    if(selectedIndex != -1 && selectedItem != nullptr)
    {
        int voId = selectedItem->getId();
        //fetching string buffer
        Surface *strBuffer = itemsBuffer[voId];
        //todo
        //text alignment should be implemented

        //text start at left, like 3 pixels offset, middle the Y
        Point dstPt(3, (height - strBuffer->getHeight())/2);
        buffer->blit(strBuffer, &dstPt);
    }

    Point upPt (width - upArrow->getWidth(), 0);
    Point downPt (width - downArrow->getWidth(), height - downArrow->getHeight());

    buffer->blit(upArrow, &upPt);
    buffer->blit(downArrow, &downPt);

    //border drawing
    PRect border (0, 0, width-1, height-1);
    buffer->draw(&border, foreground);

    return buffer;
}

void Spinner::onClick(Point *relp)
{
    Rectangle upRect (width - upArrow->getWidth(),
                      0,
                      upArrow->getWidth(),
                      upArrow->getHeight());
    Rectangle downRect (width - downArrow->getWidth(),
                        height - downArrow->getHeight(),
                        downArrow->getWidth(),
                        downArrow->getHeight());
    if(upRect.contains(relp))
    {
        if(selectedIndex > 0)
        {
            selectedIndex--;
            onSelectionChanged();
        }
    }
    else if(downRect.contains(relp))
    {
        if(selectedIndex < items.size() - 1)
        {
            selectedIndex++;
            onSelectionChanged();
        }
    }

    if(selectedIndex != -1)
    {
        selectedItem = items[selectedIndex];
    }
    else
    {
        selectedItem = nullptr;
    }
}

void Spinner::onSelectionChanged(void)
{
    SelectionEventArgs args (selectedItem);
    publish(this, &args);
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

Surface* Spinner::getUpArrow(void)
{
    return upArrow;
}

Surface* Spinner::getDownArrow(void)
{
    return downArrow;
}

void Spinner::setUpArrow(Surface *m_upArrow)
{
    upArrow = m_upArrow;
}

void Spinner::setDownArrow(Surface *m_downArrow)
{
    downArrow = m_downArrow;
}

void Spinner::clearItems(void)
{
    //todo clear all items

    clearBuffer();
    items.clear();

    selectedIndex = -1;
    selectedItem = nullptr;
}

void Spinner::setSelectedIndex(int index)
{
    if(index < items.size())
    {
        selectedIndex = index;
        selectedItem = items[index];
    }
}

void Spinner::setSelectedItem(ValueObject *item)
{
    auto vit(items.begin()), vend(items.end());
    int index=0;
    for(;vit!=vend;++vit)
    {
        if((*vit) == item)
        {
            selectedIndex = index;
            selectedItem = (*vit);
            break;
        }

        index++;
    }
}

}

}
