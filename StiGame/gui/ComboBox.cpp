#include "ComboBox.h"
#include "PLine.h"

#include <iostream>

namespace StiGame {

namespace Gui
{
//refactor those constants to UPPER CHAR
const int ComboBox::DefaultNbItems = 4;
const int ComboBox::DefaultTextOffset = 4;

ComboBox::ComboBox() : HighlightItem("ComboBox")
{
    itemHover = -1;
    currentItem = 0;
    itemSize = 20;
    drawDroplist = false;
    nbItemsToShow = DefaultNbItems;
    selectedId = -1;
    textOffset = DefaultTextOffset;
    font = style->getNormalFont();
    dropArrow = style->getDropListArrow();

    upArrow = style->getUpArrow();
    downArrow = style->getDownArrow();

    height = dropArrow->getHeight();
    closedHeight = height;
}

void ComboBox::setSelectedItem(ValueObject *selectedItem)
{
    auto vit(items.begin()), vend(items.end());
    int i=0;
    for(;vit!=vend;++vit)
    {
        if((*vit) == selectedItem)
        {
            selectedId = (*vit)->getId();
            currentItem = i;
        }
        i++;
    }
}

void ComboBox::clearItems(void)
{
    auto vit(items.begin()), vend(items.end());
    for(;vit!=vend;++vit)
    {
        delete (*vit);
    }

    items.clear();

    currentItem = 0;
    selectedId = -1;
    itemHover = -1;

    auto mit(stringsBuffer.begin()), mend(stringsBuffer.end());
    for(;mit!=mend;++mit)
    {
        delete mit->second;
    }

    stringsBuffer.clear();
}

void ComboBox::setSelectedIndex(int m_selectedIndex)
{
    selectedId = m_selectedIndex;
}

void ComboBox::add(ValueObject *vo)
{
    items.push_back(vo);

    Surface *txt = font->renderText(vo->getText(), foreground);

    if(txt->getWidth() + textOffset * 2 + dropArrow->getWidth() > width)
    {
        width = txt->getWidth() + textOffset * 2 + dropArrow->getWidth();
    }

    stringsBuffer[vo->getId()] = txt;

    if(selectedId == -1)
    {
        selectedId = vo->getId();
    }
}

void ComboBox::showDroplist(void)
{
    currentItem = 0;
    drawDroplist = true;
    int ic = items.size();
    if(ic >= nbItemsToShow)
    {
        height = closedHeight + nbItemsToShow * itemSize;
    }
    else
    {
        height = closedHeight + ic * itemSize;
    }

}

void ComboBox::onMouseMotion(Point *relp)
{
    if(drawDroplist)
    {
        itemHover = currentItem + (relp->getY() - closedHeight) / itemSize;
    }
}

void ComboBox::onClick(Point *relp)
{
    //drop list close
    //need to determine if the click is for drop arrow
    Rectangle *upRect,*downRect;
    upRect = upArrow->getRectangle(width - upArrow->getWidth(), closedHeight);
    downRect = downArrow->getRectangle(width - downArrow->getWidth(), closedHeight + itemSize*nbItemsToShow - downArrow->getHeight());

    if(!drawDroplist)
    {
        Rectangle *arrow = dropArrow->getRectangle(width - dropArrow->getWidth(), 0);
        if(arrow->contains(relp))
        {
            //drop list method
            showDroplist();
        }
    }
    else if(upRect->contains(relp))
    {
        //up arrow
        if(currentItem > 0)
        {
            currentItem--;
        }
    }
    else if(downRect->contains(relp))
    {
        //down arrow
        if(currentItem < items.size() - nbItemsToShow)
        {
            currentItem++;
        }
    }
    else
    {
    //drop list open
    //need to determine the clicked item
        Rectangle closeRect = Rectangle(0, 0, width, closedHeight);

        if(closeRect.contains(relp))
        {
            //closing the droplist, keeping the same selection
            closeDroplist();
        }
        else
        {

            //to consider the case when the user click on the arrow, to view the other object
            //int nbitem = (height - closedHeight)/itemSize;
            //int ic = items.size();
            int i = 0;
            std::list<ValueObject*>::iterator lit (items.begin()), lend(items.end());

            for(; lit!=lend; ++lit)
            {
                if(i >= currentItem)
                {
                    int rely = i - currentItem;
                    Rectangle irect = Rectangle(0, closedHeight + rely*itemSize, width - dropArrow->getWidth(), itemSize);
                    if(irect.contains(relp))
                    {
                        //this object is clicked
                        int id = (*lit)->getId();
                        selectedId = id;
                        //closing the droplist
                        closeDroplist();
                        SelectionEventArgs *args = new SelectionEventArgs((*lit));
                        //throwing the event
                        publish(this, args);

                        delete args;
                    }
                }

                i++;
            }

        }

        delete upRect;
        delete downRect;
    }
}

void ComboBox::closeDroplist(void)
{
    height = closedHeight;
    drawDroplist = false;
}

Surface *ComboBox::render(void)
{
    Surface *buffer = new Surface(width, height);

    buffer->fill(background);


        //drawing selected item
    Surface *sitem = stringsBuffer[selectedId];

    if(sitem != 0)
    {
        SDL_Rect *src = sitem->getRect();
        SDL_Rect *dst = sitem->getRect( ( ( width - dropArrow->getWidth() ) / 2 ) - ( sitem->getWidth() / 2 ),
                                         (closedHeight / 2 ) - ( sitem->getHeight() / 2 ) );

        buffer->blit(sitem, src, dst);

        delete src;
        delete dst;
    }

    //drawing arrow

    SDL_Rect *asrc = dropArrow->getRect();
    SDL_Rect *adst = dropArrow->getRect(width - dropArrow->getWidth(), 0);

    buffer->blit(dropArrow, asrc, adst);

    delete asrc;
    delete adst;


    //drawing border

    PLine l1 = PLine();
    PLine l2 = PLine();
    PLine l3 = PLine();
    PLine l4 = PLine();

    l1.set1(0,0);
    l1.set2(width - 1, 0);

    l2.set1(0,0);
    l2.set2(0, closedHeight - 1);

    l3.set1(width - 1, 0);
    l3.set2(width - 1, closedHeight - 1);

    l4.set1(0, closedHeight - 1);
    l4.set2(width - 1, closedHeight - 1);

    buffer->draw(&l1, foreground);
    buffer->draw(&l2, foreground);
    buffer->draw(&l3, foreground);
    buffer->draw(&l4, foreground);

    if(drawDroplist)
    {
        renderDroplist(buffer);
    }

    return buffer;
}

void ComboBox::renderDroplist(Surface *buffer)
{
    int nbtodraw = nbItemsToShow;
    int ic = items.size();
    if(currentItem + nbItemsToShow >= ic)
    {
        nbtodraw = ic - currentItem;
    }

    std::list<ValueObject*>::iterator lit (items.begin()), lend(items.end());
    int i=0;

    //fill droplist background
    SDL_Rect bgRect;
    bgRect.y = closedHeight;
    bgRect.x = 0;
    bgRect.h = height - closedHeight;
    bgRect.w = width;
    buffer->fillRect(&bgRect, background);

    for(;lit!=lend;++lit)
    {
        SDL_Rect *src,*dst,*bgfill;
        if(i >= currentItem)
        {
            int rely = i - currentItem;
            Surface *txt = stringsBuffer[(*lit)->getId()];
            src = txt->getRect();
            dst = txt->getRect(textOffset, rely*itemSize + closedHeight);

            if(i == itemHover)
            {
                bgfill = new SDL_Rect();
                bgfill->x = dst->x;
                bgfill->y = dst->y;
                bgfill->h = itemSize;
                bgfill->w = width - dropArrow->getWidth();
                buffer->fillRect(bgfill, highlightBackground);

                delete bgfill;
            }

            buffer->blit(txt, src, dst);

            delete src;
            delete dst;
        }

        i++;
    }

    //drawing the arrow

    SDL_Rect *src,*dst;
    src = upArrow->getRect();
    dst = upArrow->getRect(width - upArrow->getWidth(), closedHeight);

    buffer->blit(upArrow, src, dst);

    delete src;
    delete dst;

    src = upArrow->getRect();
    dst = upArrow->getRect(width - downArrow->getWidth(), closedHeight + itemSize*nbItemsToShow - downArrow->getHeight());

    buffer->blit(downArrow, src, dst);

    delete src;
    delete dst;

    //render droplist border
    PLine l1 = PLine();
    PLine l2 = PLine();
    PLine l3 = PLine();
    PLine l4 = PLine();

    l1.set1(0, height - 1);
    l1.set2(width - 1, height - 1);

    l2.set1(0,0);
    l2.set2(0, height - 1);

    l3.set1(width - 1, 0);
    l3.set2(width - 1, height - 1);

    buffer->draw(&l1, foreground);
    buffer->draw(&l2, foreground);
    buffer->draw(&l3, foreground);
}

void ComboBox::remove(ValueObject *vo)
{
    items.remove(vo);

    Surface *buffer = stringsBuffer[vo->getId()];

    stringsBuffer.erase(vo->getId());

    delete buffer;

}

void ComboBox::setFont(Font *m_font)
{
    font = m_font;
}

ComboBox::~ComboBox()
{
    //dtor
    auto vit(items.begin()), vend(items.end());
    for(;vit!=vend;++vit)
    {
        delete (*vit);
    }

    auto bit(stringsBuffer.begin()), bend(stringsBuffer.end());
    for(;bit!=bend;++bit)
    {
        delete bit->second;
    }
}

}

}

#ifdef C_WRAPPER

extern "C" {

    StiGame::Gui::ComboBox* ComboBox_new()
    {
        return new StiGame::Gui::ComboBox();
    }

    void ComboBox_add(StiGame::Gui::ComboBox *comboBox, StiGame::Gui::ValueObject *vo)
    {
        comboBox->add(vo);
    }

}

#endif // C_WRAPPER
