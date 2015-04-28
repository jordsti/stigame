#ifndef STARTINGCREATOR_H
#define STARTINGCREATOR_H
#include "ItemCreatorChain.h"

namespace StiGame
{
namespace Gui
{

class StartingCreator :
        public ItemCreatorChain
{
public:
    StartingCreator();
    virtual ~StartingCreator();
protected:
    Item* createItem(std::string type, std::map<std::string, int> variables);
};

}

}

#endif // STARTINGCREATOR_H
