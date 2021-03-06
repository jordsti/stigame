#include "List.h"
#include "PRect.h"

namespace StiGame
{

namespace Gui
{

const int List::DEFAULT_LINE_HEIGHT = 20;

List::List()
    : HighlightItem("List")
{
	selectedIndex = -1;
	viewIndex = 0;
	upArrow = style->getUpArrow();
	downArrow = style->getDownArrow();
	font = style->getNormalFont();
	lineHeight = DEFAULT_LINE_HEIGHT;
	mouseOverIndex = -1;
    drawBorder = false;
	_showScrollButtons = false;
}

List::~List()
{
    auto mit(strBuffers.begin()), mend(strBuffers.end());

    for(;mit!=mend;++mit)
    {
        delete mit->second;
    }

    strBuffers.clear();
    values.clear();
}

void List::setDrawBorder(bool m_drawBorder)
{
    drawBorder = m_drawBorder;
}

bool List::isDrawBorder(void)
{
    return drawBorder;
}


void List::onClick(Point *relpt)
{
	Rectangle rectUp = Rectangle(width - upArrow->getWidth(), 0, upArrow->getWidth(), upArrow->getHeight());
	Rectangle rectDown = Rectangle(width - downArrow->getWidth(), height - downArrow->getHeight(), downArrow->getWidth(), downArrow->getHeight());

    if((rectUp.contains(relpt) || rectDown.contains(relpt)) && _showScrollButtons)
    {
        if(rectUp.contains(relpt))
        {
            //list drawing start --
            if(viewIndex > 0)
            {
                viewIndex--;
            }
        }
        else if(rectDown.contains(relpt))
        {
            //list drawing start ++
            if(viewIndex < values.size() - height / lineHeight)
            {
                viewIndex++;
            }
        }
    }
    else
    {
        //item selection click
        int i = relpt->getY() / lineHeight;

        i += viewIndex;

        if(i < values.size())
        {
            selectedIndex = i;
            //todo event throwing!!
            if(containListeners())
            {

                ValueObject *vo;

                std::vector<ValueObject*>::iterator lit(values.begin()), lend(values.end());
                int vo_i=0;
                for(;lit!=lend;++lit)
                {
                    if(vo_i == i)
                    {
                        vo = (*lit);
                        break;
                    }
                    vo_i++;
                }

                SelectionEventArgs *args = new SelectionEventArgs(vo);
                publish(this, args);
                delete args;

            }

        }
    }
}

int List::getLineHeight(void)
{
	return lineHeight;
}

void List::setLineHeight(int m_lineHeight)
{
	lineHeight = m_lineHeight;
}

Surface* List::render(void)
{
	Surface *buffer = new Surface(width, height);
	buffer->fill(background);

    std::vector<ValueObject*>::iterator lit(values.begin()), lend(values.end());
	int i=0;
	int cy = 0;
	SDL_Rect *src = new SDL_Rect();
	SDL_Rect *dst = new SDL_Rect();
    PRect rect = PRect();
    rect.setX(0);
    rect.setWidth(width);
    rect.setHeight(lineHeight);

    if(_showScrollButtons)
    {
        rect.setWidth(width - upArrow->getWidth());
    }

	for(;lit!=lend;++lit)
	{
	    if(i >= viewIndex)
        {
            Surface *str_sur;
            ValueObject *vo = (*lit);
            bool free_str = false;
            if(i == selectedIndex)
            {
                free_str = true;
                str_sur = font->renderText(vo->getText(), highlightForeground);

                rect.setY(cy);

                rect.fill(buffer->getSDLSurface(), highlightBackground);

            }
            else
            {
                str_sur = strBuffers[vo->getId()];
            }

            str_sur->updateSDLRect(src);
            str_sur->updateSDLRect(dst, 0, cy);

            buffer->blit(str_sur, src, dst);

            if(free_str)
            {
                delete str_sur;
            }

            cy += lineHeight;
        }

		i++;

		if(cy > height - lineHeight && viewIndex == 0)
        {
            _showScrollButtons = true;
            break;
        }
	}

	if(cy < height && viewIndex == 0)
    {
        _showScrollButtons = false;
    }

	if(_showScrollButtons)
    {

        upArrow->updateSDLRect(src);
        upArrow->updateSDLRect(dst, width - upArrow->getWidth(), 0);

        buffer->blit(upArrow, src, dst);

        downArrow->updateSDLRect(src);
        downArrow->updateSDLRect(dst, width - downArrow->getWidth(), height - downArrow->getHeight());

        buffer->blit(downArrow, src, dst);

    }

    if(drawBorder)
    {
        PRect border = PRect(0, 0, width, height);
        buffer->draw(&border, foreground);
    }

	delete src;
	delete dst;

	return buffer;
}

void List::add(ValueObject *vo)
{
	int id = vo->getId();
	Surface *str = font->renderText(vo->getText(), foreground);

	strBuffers.insert(std::make_pair(id, str));
    values.push_back(vo);
}

void List::remove(ValueObject *vo)
{
    int id = vo->getId();
    //todo memory handling need to destroy surface!!
    strBuffers.erase(id);
    //values.erase(vo);
    auto vit(values.begin()), vend(values.end());
    for(;vit!=vend;++vit)
    {
        if((*vit)->getId() == id || vo == (*vit))
        {
            values.erase(vit);
            break;
        }

    }
}

int List::getSelectedIndex(void)
{
	return selectedIndex;
}

ValueObject* List::getSelectedItem(void)
{
    if(selectedIndex != -1)
        return values[selectedIndex];

    return nullptr;
}

void List::setSelectedIndex(int index)
{
	selectedIndex = index % values.size();
}

int List::getNbItems(void)
{
	return values.size();
}

void List::setFont(Font *m_font)
{
	font = m_font;
}

Font* List::getFont(void)
{
	return font;
}

}

}

#ifdef C_WRAPPER

extern "C" {

    StiGame::Gui::List* List_new()
    {
        return new StiGame::Gui::List();
    }

    void List_add(StiGame::Gui::List *list, StiGame::Gui::ValueObject *vo)
    {
        list->add(vo);
    }

}

#endif // C_WRAPPER
