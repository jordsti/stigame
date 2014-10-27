#ifndef FILE_H
#define FILE_H

#include "Entry.h"
namespace StiGame
{

namespace FS
{

class File :
        public Entry
{
public:
    File(std::string m_name, std::string m_parent);
    virtual ~File();
    EntryType type(void);
private:

};

}

}
#endif // FILE_H
