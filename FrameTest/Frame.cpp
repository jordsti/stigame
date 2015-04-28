#include "Frame.h"
#include <iostream>
#include "Button.h"
#include "List.h"

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

void Frame::handleEvent(StiGame::Gui::SelectionEventThrower *src, StiGame::Gui::SelectionEventArgs *args)
{
    if(src == getItem<StiGame::Gui::List>("listTest"))
    {
        std::cout << "listTest : " << args->getSelection()->getId() << "; " << args->getSelection()->getText() << std::endl;
    }
}

void Frame::initItems()
{
    StiGame::Gui::Button *btn = getItem<StiGame::Gui::Button>("btn_1");
    btn->subscribe(this);

    StiGame::Gui::List *list = getItem<StiGame::Gui::List>("listTest");
    list->subscribe(this);
}

Frame::~Frame()
{

}
