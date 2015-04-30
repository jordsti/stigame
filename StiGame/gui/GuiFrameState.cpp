#include "GuiFrameState.h"

namespace StiGame
{

namespace Gui
{

GuiFrameState::GuiFrameState(std::string frameFilePath) :
    GuiState(),
    FrameFile(frameFilePath)
{

}

GuiFrameState::~GuiFrameState()
{

}

void GuiFrameState::onStart(void)
{
    running = true;
    //creating items
    createItems(viewport);

    //adding all items
    auto lit(items.begin()), lend(items.end());
    for(;lit!=lend;++lit)
    {
        Item *item = lit->second;
        if(item->getName() != "TabItem")
        {
            add(lit->second);
        }
    }

    initItems();
}

}

}
