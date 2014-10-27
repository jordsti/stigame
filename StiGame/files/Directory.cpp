#include "Directory.h"
namespace StiGame
{

namespace FS
{

Directory::Directory(std::string m_name, std::string m_parent)
{
    name = m_name;
    parent = m_parent;
}

Directory::~Directory()
{

}

EntryType Directory::type(void)
{
    return ET_Directory;
}

}

}
