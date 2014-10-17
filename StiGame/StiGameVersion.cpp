#include "StiGameVersion.h"

StiGameVersion StiGameVersion::CurrentVersion(void)
{
    StiGameVersion v (0, 0, 1, 0, "");
    return v;
}

int StiGameVersion::getMajor(void)
{
    return major;
}

int StiGameVersion::getMinor(void)
{
    return minor;
}

int StiGameVersion::getRelease(void)
{
    return release;
}

int StiGameVersion::getBuild(void)
{
    return build;
}

std::string StiGameVersion::getName(void)
{
    return name;
}

std::string StiGameVersion::getVersionString(void)
{
    std::string _major = std::to_string(major);
    std::string _minor = std::to_string(minor);
    std::string _release = std::to_string(release);
    std::string _build = std::to_string(build);

    std::string vstr = _major+"."+_minor+"."+_release+"."+_build;
    if(name.size() > 0)
    {
        vstr += "-"+name;
    }

    return vstr;
}

StiGameVersion::StiGameVersion()
{
    minor = 0;
    major = 0;
    build = 0;
    release = 0;
    name = "";
}

StiGameVersion::StiGameVersion(int m_major, int m_minor, int m_release, int m_build, std::string m_name)
{
    major = m_major;
    minor = m_minor;
    release = m_release;
    build = m_build;
    name = m_name;
}
