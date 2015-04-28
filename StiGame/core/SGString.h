#ifndef SGSTRING_H
#define SGSTRING_H

#include <string>
#include <vector>

namespace StiGame
{

class SGString
{
public:
    SGString();
    SGString(std::string m_string);
    virtual ~SGString();

    int toInt(void);
    static SGString parseInt(int m_int);

    const char* c_str();
    size_t length(void);

    std::string getStdString(void);
    std::vector<SGString> split(char separator);

private:
    std::string _string;


};


}
#endif // SGSTRING_H
