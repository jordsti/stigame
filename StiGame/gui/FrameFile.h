#ifndef FRAMEFILE_H
#define FRAMEFILE_H

#include <string>
#include <map>
#include <vector>
#include "Item.h"
#include "Viewport.h"
namespace StiGame
{

namespace Gui
{

class ItemEquation
{
public:
    ItemEquation(std::string m_equation, std::map <std::string, int> m_variables);
    virtual ~ItemEquation();

    void evaluate(void);
    int getResult(void);
    std::string getEquation(void);
protected:
    void replaceVars(void);

private:
    std::map <std::string, int> variables;
    std::string equation;
    int result;
};

class ItemAttribute
{
public:
    ItemAttribute(std::string m_name, std::string m_value);
    virtual ~ItemAttribute();

    std::string getName(void);
    std::string getValue(void);
    int getInt(void);
    int getInt(std::map<std::string, int> variables);
    bool isEquation(void);

    void setName(std::string m_name);
    void setValue(std::string m_value);
private:
    std::string name;
    std::string value;
};

class ItemDefinition
{
public:
    ItemDefinition(std::string type);
    virtual ~ItemDefinition();

    void setAttribute(std::string m_name, std::string m_value);
    ItemAttribute* findAttribute(std::string m_name);
    std::string getType(void);
    Item *create(std::map<std::string, int> variables);
    std::string getName(void);
private:
    void applyGenericAttributes(Item *item, std::map<std::string, int> variables);

    std::string name;
    std::vector<ItemAttribute*> attributes;
    std::string type;
};

class FrameFile
{
public:
    FrameFile(std::string m_path);
    virtual ~FrameFile();

    void createItems(Viewport *viewport);

    Item* operator[](const std::string key);
    std::vector<std::string>& getItemNames(void);

protected:
    std::string path;
    void readFile(void);

    std::map<std::string, Item*> items;
    std::vector<ItemDefinition*> definitions;
};

}

}

#endif // FRAMEFILE_H
