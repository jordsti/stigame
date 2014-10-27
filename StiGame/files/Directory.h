#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Entry.h"
namespace StiGame
{

namespace FS
{
class Directory :
        public Entry
{
public:
    Directory(std::string m_name, std::string m_parent);
    virtual ~Directory();
    EntryType type(void);
};

}

}

#endif // DIRECTORY_H
