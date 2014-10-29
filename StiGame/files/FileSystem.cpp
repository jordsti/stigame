#include "FileSystem.h"

#ifdef _WIN32
#include "windows.h"
#endif

#ifdef __unix__
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#endif

#include <iostream>

namespace StiGame
{

namespace FS
{
FileSystem::FileSystem()
{
}


#ifdef __unix__
//POSIX implementation
std::vector<Entry*> FileSystem::ListDirectory(std::string m_path)
{
    std::string unix_path;
    if(m_path.length() == 0)
    {
        //current_dir
        unix_path = ".";
    }
    else
    {
        unix_path = m_path;
    }

    std::vector<Entry*> root;
    DIR *dir = opendir(unix_path.c_str());

    if(dir)
    {
        dirent *ent;
        while(ent)
        {
            std::string name (ent->d_name);
            if(name != "." && name != ".." && name.size() > 0)
            {
                if(ent->d_type == DT_DIR)
                {
                    //directory
                    Directory *_dir = new Directory(name, m_path);
                    root.push_back(_dir);
                }
                else
                {
                    //file
                    File *_file = new File(name, m_path);
                    root.push_back(_file);
                }
            }

            ent = readdir(dir);
        }

        closedir(dir);
    }

    return root;
}

void FileSystem::CreateDir(std::string d_path)
{
    struct stat st = {0};

    if (stat(d_path.c_str(), &st) == -1) {
        mkdir(d_path.c_str(), 0755);
    }
}

#endif

#ifdef _WIN32
//windows implementation
std::vector<Entry*> FileSystem::ListDirectory(std::string m_path)
{
    std::string win32_path;
    if(m_path.length() == 0)
    {
        //current_dir
        win32_path = "./*";
    }
    else
    {
        //need to add a wildcard for win32
        win32_path = m_path + "*";
    }

    std::vector<Entry*> root;
    WIN32_FIND_DATA f;
    HANDLE h = FindFirstFile(win32_path.c_str(), &f);
    if(h != INVALID_HANDLE_VALUE)
    {
        do
        {
            if(f.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                //dir
                std::string name(f.cFileName);
                if(name != "." && name != "..")
                {
                    Directory *dir = new Directory(name, m_path);
                    root.push_back(dir);
                }
            }
            else
            {
                //file
                File *file = new File(f.cFileName, m_path);
                root.push_back(file);
            }


        }
        while(FindNextFile(h, &f));
    }

    return root;
}

void FileSystem::CreateDir(std::string d_path)
{
    if (CreateDirectory(d_path.c_str(), NULL))
    {

    }
    else if (ERROR_ALREADY_EXISTS == GetLastError())
    {

    }
    else
    {
        //todo
        //error message
    }
}

#endif

}

}
