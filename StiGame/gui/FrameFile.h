#ifndef FRAMEFILE_H
#define FRAMEFILE_H

#include <string>
#include <map>
#include <vector>
#include "Item.h"
#include "Viewport.h"
#include "ItemDefinition.h"

namespace StiGame
{

namespace Gui
{

class FrameFile
{
public:
    FrameFile(std::string m_path);
    virtual ~FrameFile();

    void createItems(Viewport *viewport);

    Item* operator[](std::string key);
    Item* operator[](const char* key);
    Item* getItemByKey(std::string key);
    std::vector<std::string>& getItemNames(void);

    template <typename T>
    T* getItem(std::string name)
    {
        Item *item = getItemByKey(name);
        if(item != nullptr)
        {
            return dynamic_cast<T*>(item);
        }

        return nullptr;
    }

protected:
    ColorIndex colorIndex;
    std::string path;
    void readFile(void);

    std::map<std::string, Item*> items;
    std::vector<ItemDefinition*> definitions;
};

}

}

#endif // FRAMEFILE_H
