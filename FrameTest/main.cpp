
#include "Viewport.h"
#include "Frame.h"
#include "GamePath.h"
#include "ItemDefinition.h"
#include "CustomItem.h"
int main(int argc, char ** argv)
{
    StiGame::Viewport *viewport = new StiGame::Viewport(600, 600);

    viewport->setTitle("Frame Test");
    viewport->setFps(50);
    StiGame::Gui::ItemDefinition::AppendCreator(new CustomItemCreator());
    std::string path = StiGame::GamePath::getFilepath(StiGame::AssetRoot, "frame_test.gui");
    Frame fr (path);


    viewport->push(&fr);

    viewport->startLoop();

	return 0;
}
