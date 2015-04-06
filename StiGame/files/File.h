#ifndef FILE_H
#define FILE_H

#include "Entry.h"
namespace StiGame
{

namespace FS
{
/// \class File
/// \brief File Entry
class File :
        public Entry
{
public:
    /// \brief Constructor
    /// \param m_name File name
    /// \param m_parent File Directory
    File(std::string m_name, std::string m_parent);
    virtual ~File();
    EntryType type(void);
private:

};

}

}
#endif // FILE_H
