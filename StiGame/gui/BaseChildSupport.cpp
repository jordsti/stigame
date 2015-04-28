#include "BaseChildSupport.h"
namespace StiGame
{

namespace Gui
{

BaseChildSupport::BaseChildSupport()
{

}

BaseChildSupport::~BaseChildSupport()
{

}


Item* BaseChildSupport::getChildAt(int index)
{
    return container.itemAt(index);
}

void BaseChildSupport::addChild(Item *child)
{
    return container.add(child);
}

void BaseChildSupport::removeChild(Item *to_remove)
{
    container.remove(to_remove);
}

unsigned int BaseChildSupport::childsCount()
{
    return container.size();
}

}

}
