#include "ItemEquation.h"
//this is included for std::cout only
#include <iostream>


namespace StiGame
{

namespace Gui
{


ItemEquation::ItemEquation(std::string m_equation, std::map<std::string, int> m_variables)
{
    equation = m_equation;
    variables = m_variables;
    result = 0;
}

ItemEquation::~ItemEquation()
{

}

std::string ItemEquation::getEquation(void)
{
    return equation;
}

void ItemEquation::replaceVars(void)
{
    //vars must not have the same prefix
    //vars char is '$' so looking for that chars
    auto lit(variables.begin()), lend(variables.end());
    for(;lit!=lend;++lit)
    {
        std::string var_name = lit->first;
        std::string value = std::to_string(lit->second);

        size_t pos = equation.find('$');
        while(pos != std::string::npos)
        {
            if(pos + var_name.length() <= equation.length())
            {
                //finding the end with the op_symbol
                size_t end_var = equation.find_first_of("-+*/", pos);

                if(end_var == std::string::npos)
                {
                    end_var = equation.size();
                }

                std::string eq_var_name = equation.substr(pos + 1, end_var - (pos+1));
                if(eq_var_name == var_name)
                {
                    if(pos == 0)
                    {
                        equation = value + equation.substr(pos + 1 + var_name.length());
                    }
                    else
                    {
                        //replacing
                        equation = equation.substr(0, pos) + value + equation.substr(pos + 1 + var_name.length());
                    }
                }
            }

            pos = equation.find('$', pos + 1);
        }
    }

}

void ItemEquation::evaluate(void)
{
    //replace the var by their value
    replaceVars();
    //do the equation
    //only -,+,*,/ supported
    int _result = 0;
    std::string _equation = equation;
    size_t index = _equation.find_first_of("-+*/");
    int i = 0;
    while(index != std::string::npos)
    {
        if(i == 0)
        {
            //getting the first value
            std::string init_int = _equation.substr(0, index);
            _result = atoi(init_int.c_str());
        }

        char op_symbol = _equation[index];
        _equation = _equation.substr(0, index) + '!' + _equation.substr(index + 1);
        size_t end_value = _equation.find_first_of("-+*/");
        if(end_value == std::string::npos)
        {
            end_value = _equation.size();
        }

        std::string str_int = _equation.substr(index+1, end_value - (index + 1));

        if(op_symbol == '+')
        {
            _result += atoi(str_int.c_str());
        }
        else if(op_symbol == '-')
        {
            _result -= atoi(str_int.c_str());
        }
        else if(op_symbol == '*')
        {
            _result *= atoi(str_int.c_str());
        }
        else if(op_symbol == '/')
        {
            _result /= atoi(str_int.c_str());
        }

        //replacing the symbol
        index = _equation.find_first_of("-+*/");
        i++;
    }
    result = _result;
    //store the result
}

int ItemEquation::getResult(void)
{
    return result;
}

}

}
