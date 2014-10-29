#ifndef SGSTRING_H
#define SGSTRING_H
#include <string>

namespace sgrc {

class SGString
{
public:
    SGString(std::string m_string);
    virtual ~SGString();

    bool startsWith(std::string prefix);
    bool endsWith(std::string suffix);
    void removeEndLine(void);
    void removeTrailingSpaces(void);

    SGString substr(size_t start, size_t length);

    std::string getStdString(void);

    const size_t length(void);

private:
    std::string _string;
};

}
#endif // SGSTRING_H
