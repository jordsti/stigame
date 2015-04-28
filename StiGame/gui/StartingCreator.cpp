#include "StartingCreator.h"

namespace StiGame
{

namespace Gui
{

StartingCreator::StartingCreator() :
    ItemCreatorChain()
{

}

StartingCreator::~StartingCreator()
{
    //when you destroy this starting creator, all the next one are destroyed too
    if(hasNext())
    {
        ItemCreatorChain *current = next();

        while(current->hasNext())
        {
            ItemCreatorChain *nextChain = current->next();
            delete current;
            current = nextChain;
        }
    }
}

Item* StartingCreator::createItem(std::string type, std::map<std::string, int> variables)
{
    return nullptr;
}

}

}
