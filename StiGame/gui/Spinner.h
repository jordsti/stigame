#ifndef SPINNER_H
#define SPINNER_H

#include "Item.h"
#include "FontSupport.h"
#include "ValueObject.h"
#include <vector>
#include <map>
namespace StiGame
{

namespace Gui
{

class Spinner :
        Item,
        FontSupport
{
public:
    const static int DEFAULT_WIDTH;
    const static int DEFAULT_HEIGHT;

    Spinner();
    virtual ~Spinner();
    Surface* render(void);

    void addItem(ValueObject *m_item);

    virtual void setFont(Font *m_font);

    void clearItems(void);

    int getSelectedIndex(void);
    ValueObject* getSelectedItem(void);

private:
    void clearBuffer();

    int selectedIndex;
    ValueObject *selectedItem;
    std::vector<ValueObject*> items;
    std::map<int, Surface*> itemsBuffer;
};

}

}

#endif // SPINNER_H
