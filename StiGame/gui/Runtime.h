#pragma once
#include "Style.h"
namespace StiGame
{

namespace Gui
{

/// \class Runtime
/// \brief Singleton class that hold Gui Object that are created at RunTime
class Runtime
{
private:
	/// \brief Instance
	static Runtime *_instance;
	/// \brief Gui Style
	Style *style;

protected:
	/// \brief Create the GuiRuntime
	Runtime(void);
	/// \brief Destructor
	~Runtime(void);
public:
	/// \brief Get GuiRuntime Instance
	/// \return Instance
	static Runtime *getInstance(void)
	{
			if(_instance == NULL)
			{
				_instance = new Runtime();
			}

		return _instance;
	}
	/// \brief Get Gui Style
	/// \return Gui Style
	Style *getStyle(void);
    
    /// \brief Force the applying of a style
    /// \param m_style Style to apply
    void ForceStyle(Style *m_style)
    {
        Style *oldstyle = style;
        style = m_style;
        delete oldstyle;
    }
    
    /// \brief Is this a Debug version ?
    /// \return Debug or not
    bool isDebug(void)
    {
        #if DEBUG
        return true;
        #endif // DEBUG

        #if RELEASE
        return false;
        #endif // RELEASE
    }
};

}
}
