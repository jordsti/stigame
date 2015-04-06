#ifndef STIGAMEVERSION_H
#define STIGAMEVERSION_H

#include <string>
class StiGameVersion
{

public:
    /// \brief Return the Current Version Identification
    /// \return Current Version
    static StiGameVersion CurrentVersion(void);
    /// \brief Get Major Version number
    int getMajor(void);
    /// \brief Get Minor Version number
    int getMinor(void);
    /// \brief Get Release Number
    int getRelease(void);
    /// \brief Get Build Number
    int getBuild(void);
    /// \brief Get Version Name
    std::string getName(void);
    /// \brief Get the version string as Major.Minor.Release.Build-name
    std::string getVersionString(void);

protected:
    /// \brief Empty Constructor
    StiGameVersion();
    /// \brief Version Constructor
    StiGameVersion(int m_major, int m_minor, int m_release, int m_build, std::string m_name);
private:
    /// \brief Major
    int major;
    /// \brief Minor
    int minor;
    /// \brief Release
    int release;
    /// \brief Build Number
    int build;
    /// \brief Version Name
    std::string name;
};

#endif // STIGAMEVERSION_H