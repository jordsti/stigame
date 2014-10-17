#ifndef STIGAMEVERSION_H
#define STIGAMEVERSION_H

#include <string>
class StiGameVersion
{

public:
    static StiGameVersion CurrentVersion(void);

    int getMajor(void);
    int getMinor(void);
    int getRelease(void);
    int getBuild(void);
    std::string getName(void);
    std::string getVersionString(void);

protected:
    StiGameVersion();
    StiGameVersion(int m_major, int m_minor, int m_release, int m_build, std::string m_name);
private:
    int major;
    int minor;
    int release;
    int build;
    std::string name;
};

#endif // STIGAMEVERSION_H
