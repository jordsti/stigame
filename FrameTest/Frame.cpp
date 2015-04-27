#include "Frame.h"
#include <iostream>
#include "Button.h"

Frame::Frame(std::string path) :
    StiGame::Gui::GuiFrameState(path)
{

}

bool Frame::handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt)
{
    StiGame::Gui::Button *btn1 = getItem<StiGame::Gui::Button>("btn_1");
    if(src == btn1)
    {
        std::cout << "Button 1" << std::endl;
    }

    return true;
}

void Frame::initItems()
{
    StiGame::Gui::Button *btn = getItem<StiGame::Gui::Button>("btn_1");
    btn->subscribe(this);
}

Frame::~Frame()
{

}
