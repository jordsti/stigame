#ifndef ENTRY_H
#define ENTRY_H
#include <string>

namespace StiGame
{

namespace FS
{

enum EntryType  {
    ET_File,
    ET_Directory
};

class Entry
{
public:
    std::string getName(void);
    std::string getParent(void);
    std::string getPath(void);
    virtual EntryType type(void) = 0;
    bool endsWith(std::string m_suffix);
    std::string getNameWithoutExtension(void);
    virtual ~Entry();

protected:
    Entry();
    std::string name;
    std::string parent;
};

}

}

#endif // ENTRY_H
