#ifndef GUIFRAMESTATE_H
#define GUIFRAMESTATE_H

#include "GuiState.h"
#include "FrameFile.h"

namespace StiGame
{

namespace Gui
{


class GuiFrameState :
        public GuiState,
        public FrameFile
{
public:
    GuiFrameState(std::string frameFilePath);
    virtual ~GuiFrameState();

    virtual void onStart(void);
protected:
    virtual void initItems(void) = 0;
};

}

}

#endif // GUIFRAMESTATE_H
