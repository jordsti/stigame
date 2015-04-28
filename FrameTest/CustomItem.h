#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include "Item.h"
#include "ItemCreatorChain.h"

class CustomItem :
        public StiGame::Gui::Item
{
public:
    CustomItem();
    virtual ~CustomItem();

    StiGame::Surface *render(void);
};


class CustomItemCreator :
        public StiGame::Gui::ItemCreatorChain
{
public:
    CustomItemCreator();
    virtual ~CustomItemCreator();

protected:
    StiGame::Gui::Item *createItem(std::string type, std::map<std::string, int> variables);
};

#endif // CUSTOMITEM_H
