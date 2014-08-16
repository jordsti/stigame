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

    cb1.setPoint(10, 500);

    //tab init

    tabPanel = TabPanel();
    tabPanel.setWidth(300);
    tabPanel.setHeight(400);
    tabPanel.setPoint(210, 50);

    tab1 = TabItem("Tab 1");

    tab2 = TabItem("Tab 2");

    tab3 = new TestTabItem();

    tabPanel.addTab(&tab1);
    tabPanel.addTab(&tab2);
    tabPanel.addTab(tab3);

    tab1Label = Label();
    tab1Label.setCaption("This is this tab1!");

    tab1Btn = Button();
    tab1Btn.setCaption("Test Button");
    tab1Btn.setPoint(0, 20);

    tab1Btn.subscribe(this);

    tab1.add(&tab1Label);
    tab1.add(&tab1Btn);

    tbName = TextBox();
    tbName.setPoint(10, 200);
    tbName.setDimension(120, 20);

    //vlayout = VerticalBoxLayout();
    vlayout.setPoint(520, 20);
    vlayout.setDimension(250, 400);

    lbl_vlayout = Label();
    lbl_vlayout.setCaption("test layout");
    lbl_vlayout2.setCaption("layout 2");
    lbl_vlayout3.setCaption("layout 3");
    lbl_vlayout4.setCaption("layout 4");
    lbl_vlayout5.setCaption("layout 5");


    vlayout.addChild(&lbl_vlayout);
    vlayout.addChild(&lbl_vlayout2);
    vlayout.addChild(&lbl_vlayout3);
    vlayout.addChild(&lbl_vlayout4);
    vlayout.addChild(&lbl_vlayout5);

    vlayout.setDrawBorder(false);

    dbtn1.setCaption("Allo BTN");
    dbtn1.setDimension(200, 30);
    dbtn1.setPoint(220, 500);
    dbtn1.subscribe(this);

    add(&guiList);
    add(&cb1);
    add(&tabPanel);
    add(&tbName);
    add(&vlayout);
    add(&dbtn1);
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
    else if(src == &dbtn1)
    {
        std::cout << "Decorated Button !" << std::endl;
    }
}

TestGui::~TestGui()
{
    //dtor
}
