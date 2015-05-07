#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H
#include "Layout.h"
namespace StiGame
{

namespace Gui
{

struct ItemPair
{
    Item *label;
    Item *field;
};

class FormLayout :
        public Layout
{


public:
    static const int DEFAULT_MIDDLE_OFFSET=5;
    FormLayout();
    virtual ~FormLayout();

    int getMiddleOffset(void);
    void setMiddleOffset(int m_middleOffset);

    void addPair(ItemPair pair);
    void makePair(Item *m_label, Item *m_field);
protected:
    void setChildsPosition(void);
private:
    int middleOffset;
    std::vector<ItemPair> pairs;
};

}

}

#endif // FORMLAYOUT_H
