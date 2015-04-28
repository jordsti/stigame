#include "TestTabItem.h"
#include <iostream>

using namespace StiGame;
using namespace Gui;

TestTabItem::TestTabItem() :
    TabItem("Test Tab")
{
    //ctor
    initComponents();
}

void TestTabItem::initComponents(void)
{
    btnOk = new Button();
    btnOk->setCaption("Ok");
    btnOk->subscribe(this);

    btnCancel = new Button();
    btnCancel->setCaption("Cancel");
    btnCancel->subscribe(this);

    listOptions = new List();
    listOptions->setWidth(100);
    listOptions->setHeight(70);

    vo_1 = new ValueObject(1, "Option 1");
    vo_2 = new ValueObject(2, "Option 2");
    vo_3 = new ValueObject(3, "Option 3");
    vo_4 = new ValueObject(4, "Option 4");

    listOptions->add(vo_1);
    listOptions->add(vo_2);
    listOptions->add(vo_3);
    listOptions->add(vo_4);

    addChild(btnOk);
    addChild(btnCancel);
    addChild(listOptions);
}

bool TestTabItem::handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args)
{
    if(src == btnOk)
    {
        std::cout << "Btn Ok" << std::endl;
    }
    else if (src == btnCancel)
    {
        std::cout << "Btn Cancel" << std::endl;
    }
}

void TestTabItem::resized(void)
{
    btnOk->setX(10);
    btnOk->setY(height - (btnOk->getHeight() + 2));
    std::cout << btnOk->getY() << std::endl;

    btnCancel->setX(width - btnCancel->getWidth());
    btnCancel->setY(height - btnCancel->getHeight());

    listOptions->setX(10);
    listOptions->setY(25);
}

TestTabItem::~TestTabItem()
{
    //dtor
}
