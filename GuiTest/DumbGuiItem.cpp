#include "DumbGuiItem.h"

DumbGuiItem::DumbGuiItem(std::string m_value) :
    StiGame::Gui::Item("DumbGuiItem")
{
    value = m_value;
}

DumbGuiItem::~DumbGuiItem()
{

}

void DumbGuiItem::setValue(std::string m_value)
{
    value = m_value;
}

std::string DumbGuiItem::getValue(void)
{
    return value;
}

StiGame::Surface* DumbGuiItem::render(void)
{
    return new StiGame::Surface(1, 1);
}
