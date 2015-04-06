#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Entry.h"
namespace StiGame
{

namespace FS
{
/// \class Directory
/// \brief Directory Entry
class Directory :
        public Entry
{
public:
    /// \brief Constructor
    /// \param m_name Dir name
    /// \param m_parent Parent Dir Path
    Directory(std::string m_name, std::string m_parent);
    
    virtual ~Directory();
    
    EntryType type(void);
};

}

}

#endif // DIRECTORY_H
