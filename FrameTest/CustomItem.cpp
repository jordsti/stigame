#include "CustomItem.h"

CustomItem::CustomItem() :
    StiGame::Gui::Item("CustomItem")
{

}

CustomItem::~CustomItem()
{

}

StiGame::Surface* CustomItem::render(void)
{
    StiGame::Surface *buffer = new StiGame::Surface(width, height);
    buffer->fill(background);
    return buffer;
}



CustomItemCreator::CustomItemCreator() :
    StiGame::Gui::ItemCreatorChain()
{

}

CustomItemCreator::~CustomItemCreator()
{

}

StiGame::Gui::Item* CustomItemCreator::createItem(std::string type, std::map<std::string, int> variables)
{
    StiGame::Gui::Item *item = nullptr;
    if(type == "CustomItem")
    {
        CustomItem *custom = new CustomItem();
        item = custom;
    }
    return item;
}
