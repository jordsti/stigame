#ifndef SCRIPTREADER_H
#define SCRIPTREADER_H
#include "ScriptContext.h"
#include <vector>
namespace sgrc {

class ScriptReader
{
public:
    ScriptReader(std::string m_filepath);

    void read(void);

    virtual ~ScriptReader();

    int getSize(void);
    ScriptContext* getContext(int i);

protected:
    std::string filepath;
    std::vector<ScriptContext*> contexts;

};

}

#endif // SCRIPTREADER_H
