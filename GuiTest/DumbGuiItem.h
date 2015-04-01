#ifndef DUMBGUIITEM_H
#define DUMBGUIITEM_H
#include "Item.h"
class DumbGuiItem :
        public StiGame::Gui::Item
{
public:
    DumbGuiItem(std::string m_value);
    virtual ~DumbGuiItem();

    void setValue(std::string m_value);
    std::string getValue(void);
    StiGame::Surface* render(void);

private:
    std::string value;
};

#endif // DUMBGUIITEM_H
