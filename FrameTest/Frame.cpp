#include "Frame.h"
#include <iostream>

Frame::Frame(std::string path) :
    StiGame::Gui::GuiFrameState(path)
{

}

bool Frame::handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt)
{
    if(src == btn1)
    {
        std::cout << "Button 1" << std::endl;
    }

    return true;
}

void Frame::handleEvent(StiGame::Gui::SelectionEventThrower *src, StiGame::Gui::SelectionEventArgs *args)
{
    if(src == list)
    {
        std::cout << "listTest : " << args->getSelection()->getId() << "; " << args->getSelection()->getText() << std::endl;
    }
    else if(src == cb)
    {
        std::cout << "comboTest : " << args->getSelection()->getId() << "; " << args->getSelection()->getText() << std::endl;
    }
}

void Frame::initItems()
{
    btn1 = getItem<StiGame::Gui::Button>("btn_1");
    btn1->subscribe(this);

    list = getItem<StiGame::Gui::List>("listTest");
    list->subscribe(this);

    cb = getItem<StiGame::Gui::ComboBox>("zcomboTest");
    cb->subscribe(this);

    tab1 = getItem<StiGame::Gui::TabItem>("tab1");
    std::cout << tab1->childsCount() << std::endl;
}

Frame::~Frame()
{

}
