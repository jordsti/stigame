#ifndef SCRIPTCONTEXT_H
#define SCRIPTCONTEXT_H
#include <string>
namespace sgrc {
class ScriptContext
{
public:
    virtual ~ScriptContext();
    virtual void execute(void) = 0;
    virtual void parseInstruction(std::string ins) = 0;

    int getId(void);
    std::string getName(void);

protected:
    ScriptContext(std::string m_name);

    void message(std::string msg);
    void error(std::string msg);

private:
    int _id;
    std::string name;
    static int currentId;
    int CurrentId(void);

};
}
#endif // SCRIPTCONTEXT_H
