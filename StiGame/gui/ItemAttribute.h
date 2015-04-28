#ifndef ITEMATTRIBUTE_H
#define ITEMATTRIBUTE_H
#include <string>
#include <map>
#include "Color.h"
#include <vector>
namespace StiGame
{

namespace Gui
{

class ItemAttribute
{
public:
    ItemAttribute(std::string m_name, std::string m_value);
    virtual ~ItemAttribute();

    std::string getName(void);
    std::string getValue(void);
    int getInt(void);
    int getInt(std::map<std::string, int> variables);

    std::vector<std::string> splitValues(std::string separator);

    bool isEquation(void);
    Color* getColor(void);
    void setName(std::string m_name);
    void setValue(std::string m_value);
private:
    std::string name;
    std::string value;
};

}

}
#endif // ITEMATTRIBUTE_H
