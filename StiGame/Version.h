#ifndef VERSION_H
#define VERSION_H
#include <string>

namespace StiGame
{

class Version
{
public:
    Version();
    int getMajor(void);
    int getMinor(void);
    int getRelease(void);
    int getBuild(void);
    std::string getVersion(void);

    virtual ~Version();

private:
    int major;
    int minor;
    int release;
    int build;
};

}

#endif // VERSION_H
