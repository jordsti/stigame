#include "FormLayout.h"

namespace StiGame
{

namespace Gui
{

/*
 * How to implement this Layout ?
 *  - Item should be added as a pair
 *      - Do we define the pair at the insert time ?
 *      - We make a map for which item is paired with this item ?
 *      - Using another container ?
 */

FormLayout::FormLayout() :
    Layout("FormLayout")
{
    middleOffset = DEFAULT_MIDDLE_OFFSET;
}

FormLayout::~FormLayout()
{

}

int FormLayout::getMiddleOffset(void)
{
    return middleOffset;
}

void FormLayout::setMiddleOffset(int m_middleOffset)
{
    middleOffset = m_middleOffset;
    childsChanged = true;
}

void FormLayout::addPair(ItemPair pair)
{
    addChild(pair.label);
    addChild(pair.field);
    pairs.push_back(pair);
}


void FormLayout::makePair(Item *m_label, Item *m_field)
{
    if(!container.contains(m_label))
    {
        addChild(m_label);
    }

    if(!container.contains(m_field))
    {
        addChild(m_field);
    }

    ItemPair p;
    p.label = m_label;
    p.field = m_field;
    pairs.push_back(p);
}

void FormLayout::setChildsPosition(void)
{
    ItemIterator it = container.iterator();

    int current_y = 0;
    int label_sep = 0;

    //first iteration is to calculate the label_sep
    auto lit(pairs.begin()), lend(pairs.end());
    for(;lit!=lend;++lit)
    {
        ItemPair pair = (*lit);
        if(pair.label->getWidth() > label_sep)
        {
            label_sep = pair.label->getWidth();
        }
    }

    int field_x = label_sep + middleOffset;
    int field_width = width - label_sep - middleOffset;

    //placing the item
    MPoint labelPt, fieldPt;
    auto pit(pairs.begin()), pend(pairs.end());
    for(;pit!=pend;++pit)
    {
        int i_height = 0;
        ItemPair pair = (*lit);
        if(pair.label->getHeight() > pair.field->getHeight())
        {
            //using label height
            i_height = pair.label->getHeight();
        }
        else
        {
            //using field height
            i_height = pair.field->getHeight();
        }

        //Y Position
        if(verticalAlign == LVA_Middle)
        {
            labelPt.setY(current_y +
                        ((i_height - pair.label->getHeight())/2));
            fieldPt.setY(current_y +
                        ((i_height - pair.field->getHeight())/2));
        }
        else if(verticalAlign == LVA_Bottom)
        {
            labelPt.setY(current_y +
                         (i_height - pair.label->getHeight()));
            fieldPt.setY(current_y +
                         (i_height - pair.field->getHeight()));
        }
        else if(verticalAlign == LVA_Top)
        {
            labelPt.setY(current_y);
            fieldPt.setY(current_y);
        }

        //X Position
        if(horizontalAlign == LHA_Center)
        {
            labelPt.setX((label_sep - pair.label->getWidth())/2);
            fieldPt.setX(field_x +
                        ((field_width - pair.field->getWidth())/2));
        }
        else if(horizontalAlign == LHA_Left)
        {
            labelPt.setX(0);
            fieldPt.setX(field_x);
        }
        else if(horizontalAlign == LHA_Right)
        {
            labelPt.setX(label_sep - pair.label->getWidth());
            fieldPt.setX(field_x +
                         (field_width - pair.field->getWidth()));
        }

        //applying point to the Item
        pair.label->setPoint(&labelPt);
        pair.field->setPoint(&fieldPt);

        current_y += i_height;

        //clearing points value (remove some bugs idk)
        labelPt.setPoint(0, 0);
        fieldPt.setPoint(0, 0);
    }

}

}

}
