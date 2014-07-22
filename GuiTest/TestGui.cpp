#include "TestGui.h"
#include <ValueObject.h>

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
    guiList.setHeight(360);
    guiList.setX(10);
    guiList.setY(10);

    cb1 = CheckBox();
    cb1.setCaption("Check box 1");

    cb1.set(10, 500);

    add(&guiList);
    add(&cb1);
}

TestGui::~TestGui()
{
    //dtor
}
