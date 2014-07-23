#include "TestGui.h"
#include <ValueObject.h>
#include <iostream>

using namespace StiGame;
using namespace Gui;

TestGui::TestGui() : GuiState()
{
    //ctor
    initComponents();
}

void TestGui::initComponents()
{
    ValueObject *vo;

    guiList = List();

    vo = new ValueObject(0, "Test 1");
    guiList.add(vo);
    vo = new ValueObject(1, "Test 2");
    guiList.add(vo);
    vo = new ValueObject(2, "Test 3");
    guiList.add(vo);
    vo = new ValueObject(3, "Test 4");
    guiList.add(vo);
    vo = new ValueObject(4, "Test 5");
    guiList.add(vo);

    guiList.setWidth(80);
    guiList.setHeight(60);
    guiList.setX(10);
    guiList.setY(10);

    guiList.subscribe(this);

    cb1 = CheckBox();
    cb1.setCaption("Check box 1");

    cb1.set(10, 500);

    //tab init

    tabPanel = TabPanel();
    tabPanel.setWidth(300);
    tabPanel.setHeight(400);
    tabPanel.set(110, 50);

    tab1 = TabItem("Tab 1");

    tab2 = TabItem("Tab 2");

    tabPanel.addTab(&tab1);
    tabPanel.addTab(&tab2);

    tab1Label = Label();
    tab1Label.setCaption("This is this tab1!");

    tab1Btn = Button();
    tab1Btn.setCaption("Test Button");
    tab1Btn.set(0, 20);

    tab1Btn.subscribe(this);

    tab1.add(&tab1Label);
    tab1.add(&tab1Btn);

    add(&guiList);
    add(&cb1);
    add(&tabPanel);
}

void TestGui::handleEvent(StiGame::Gui::SelectionEventThrower *src, StiGame::Gui::SelectionEventArgs *args)
{
    if(src == &guiList)
    {
        std::cout << "Selected Item : " << args->getSelection()->getText() << " #" << args->getSelection()->getId() << std::endl;
    }


}

void TestGui::handleEvent(EventThrower *src, EventArgs *evt)
{
    if(src == &tab1Btn)
    {
        std::cout << "Tab 1 Button !!" << std::endl;
    }
}

TestGui::~TestGui()
{
    //dtor
}
