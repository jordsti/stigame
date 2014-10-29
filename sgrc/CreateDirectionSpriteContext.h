#ifndef CREATEDIRECTIONSPRITECONTEXT_H
#define CREATEDIRECTIONSPRITECONTEXT_H

#include "ScriptContext.h"
#include <vector>

namespace sgrc
{

class CreateDirectionSpriteContext :
        public ScriptContext
{
public:
    CreateDirectionSpriteContext();
    virtual ~CreateDirectionSpriteContext();

    void execute(void);
    void parseInstruction(std::string ins);

private:
    bool useAssetsPath;
    std::string spriteName;
    std::vector < std::string > framesUp;
    std::vector < std::string > framesDown;
    std::vector < std::string > framesLeft;
    std::vector < std::string > framesRight;
    std::vector < std::string > framesIdle;
    int width;
    int height;
    std::string fileOutput;
};

}

#endif // CREATEDIRECTIONSPRITECONTEXT_H
