#ifndef ITEMEQUATION_H
#define ITEMEQUATION_H
#include <string>
#include <map>
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

}

}
#endif // ITEMEQUATION_H
