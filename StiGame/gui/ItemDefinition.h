#ifndef ITEMDEFINITION_H
#define ITEMDEFINITION_H

#include "ItemAttribute.h"
#include <vector>
#include "Item.h"
#include "ColorIndex.h"
#include "StartingCreator.h"
#include "HighlightItem.h"
namespace StiGame
{

namespace Gui
{

class ItemDefinition
{
public:
    ItemDefinition(std::string type);
    virtual ~ItemDefinition();

    void setColorIndex(ColorIndex *m_colorIndex);
    ColorIndex* getColorIndex(void);

    void setAttribute(std::string m_name, std::string m_value);
    ItemAttribute* findAttribute(std::string m_name);
    std::string getType(void);
    Item *create(std::map<std::string, int> variables);
    std::string getName(void);

    static ItemCreatorChain* GetExternalCreator(void);
    static void AppendCreator(ItemCreatorChain *chain);

    void applyHighlightColors(HighlightItem *hItem);

private:
    static ItemCreatorChain *externalCreator;

    void applyGenericAttributes(Item *item, std::map<std::string, int> variables);
    ColorIndex *colorIndex;
    std::string name;
    std::vector<ItemAttribute*> attributes;
    std::string type;
};

}

}

#endif // ITEMDEFINITION_H
