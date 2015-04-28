#ifndef ITEMCREATORCHAIN_H
#define ITEMCREATORCHAIN_H
#include "Item.h"
#include <map>
namespace StiGame
{
namespace Gui
{

class ItemCreatorChain
{
public:
    ItemCreatorChain();
    virtual ~ItemCreatorChain();

    Item *create(std::string type, std::map<std::string, int> variables);

    virtual ItemCreatorChain* next(void);
    virtual bool hasNext(void);
    virtual void setNext(ItemCreatorChain *m_next);

protected:
    virtual Item* createItem(std::string type, std::map<std::string, int> variables) = 0;

private:
    ItemCreatorChain *_next;
};

}
}

#endif // ITEMCREATORCHAIN_H
