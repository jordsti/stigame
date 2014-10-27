#include "File.h"
namespace StiGame
{

namespace FS
{

File::File(std::string m_name, std::string m_parent)
{
    name = m_name;
    parent = m_parent;
}

File::~File()
{

}

EntryType File::type(void)
{
    return ET_File;
}

}

}
