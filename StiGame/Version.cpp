#include "Version.h"
#include "VersionConfig.h"

namespace StiGame
{

Version::Version()
{
    major = VERSION_MAJOR;
    minor = VERSION_MINOR;
    release = VERSION_RELEASE;
    build = VERSION_BUILD;
}

int Version::getMajor(void)
{
    return major;
}

int Version::getMinor(void)
{
    return minor;
}

int Version::getRelease(void)
{
    return release;
}

int Version::getBuild(void)
{
    return build;
}

std::string Version::getVersion(void)
{
    std::string version = std::to_string(major) + ".";
    version += std::to_string(minor) + ".";
    version += std::to_string(release) + ".";
    version += std::to_string(build);

    return version;
}

Version::~Version()
{

}

}
