#include <Viewport.h>
#include "TestGui.h"
#include "DumbGuiItem.h"
#include "ItemContainer.h"
#include <iostream>
#include "FrameFile.h"
#include "GamePath.h"

using namespace StiGame;

int main(int argc, char ** argv)
{
    Viewport *vpt = new Viewport(900, 600);

    vpt->setTitle("Gui Test");

    vpt->setFps(50);

    StiGame::Gui::FrameFile ff (StiGame::GamePath::getFilepath(StiGame::AssetRoot, "frame_test.gui"));
    ff.createItems(vpt);

    StiGame::Gui::ItemAttribute colorT ("test", "10,0,200");
    colorT.getColor();
    //item container test here
    DumbGuiItem *i1 = new DumbGuiItem("1");
    DumbGuiItem *i2 = new DumbGuiItem("2");
    DumbGuiItem *i3 = new DumbGuiItem("3");
    DumbGuiItem *i4 = new DumbGuiItem("4");
    DumbGuiItem *i5 = new DumbGuiItem("5");
    DumbGuiItem *i6 = new DumbGuiItem("6");
    DumbGuiItem *i7 = new DumbGuiItem("7");

    StiGame::Gui::ItemContainer container;
    std::cout << "Clear Items : " << container.isClearItems() << std::endl;
    container.add(i1);
    container.add(i2);

    container.insert(i3, 1);
    container.add(i4);
    container.add(i5);
    container.add(i6);
    container.add(i7);

    std::cout << "container.itemAt(2) : " << (dynamic_cast<DumbGuiItem*>(container.itemAt(0)))->getValue() << std::endl;

    container.remove(i6);

    for(StiGame::Gui::ItemIterator it = container.iterator(); it.next();)
    {
        std::cout << (dynamic_cast<DumbGuiItem*>(it.item()))->getValue() << std::endl;
    }
    std::cout << "container.size() : " << container.size() << std::endl;
    //end of the test

    TestGui *tg = new TestGui();

    vpt->push(tg);
    vpt->startLoop();

    delete vpt;
    delete tg;

    SDL_Quit();

    return 0;
}
