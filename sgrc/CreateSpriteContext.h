#ifndef CREATESPRITECONTEXT_H
#define CREATESPRITECONTEXT_H
#include "ScriptContext.h"
#include <vector>
namespace sgrc
{
class CreateSpriteContext :
        public ScriptContext
{
public:
    CreateSpriteContext();
    virtual ~CreateSpriteContext();

    void execute(void);
    void parseInstruction(std::string ins);

private:
    std::string spriteName;
    std::vector<std::string> frames;
    std::string fileOutput;
    int width;
    int height;
    bool useAssetsPath;
};
}

#endif // CREATESPRITECONTEXT_H
