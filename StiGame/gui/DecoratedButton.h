#ifndef DECORATEDBUTTON_H
#define DECORATEDBUTTON_H
#include "Item.h"
#include "EventThrower.h"
#include "CaptionSupport.h"
namespace StiGame
{
namespace Gui
{
/// \class DecoratedButton
/// \brief Button with custom graphics
class DecoratedButton :
    public Item,
    public EventThrower,
    public CaptionSupport
{
    public:
	/// \brief Constructor
    DecoratedButton();
	/// \brief Destructor
    virtual ~DecoratedButton();
    
    Surface* render(void);
	
	/// \brief Get Current Caption value
    std::string getCaption(void);
	/// \brief Set Caption Value
    void setCaption(std::string m_caption);
	/// \brief On Click event Handling
	/// \param relp Relative position
    void onClick(Point *relp);
    void setForeground(Color* m_foreground);
    protected:
    void resized(void);
	/// \brief Left Graphics
	Surface *buttonLeft;
	/// \brief Right Graphics
    Surface *buttonRight;
	/// \brief Background graphics (Repeated)
    Surface *buttonBackground;
	
	/// \brief Left Highlight Graphics
    Surface *buttonHighlightLeft;
	/// \brief Right Highlight Graphics
    Surface *buttonHighlightRight;
	/// \brief Background Highlight Graphics (Repeated)
    Surface *buttonHighlightBackground;
	
	/// \brief Button Surface Buffer
    Surface *surfaceBackground;
	/// \brief Highlight Button Surface Buffer
    Surface *surfaceHighlightBackground;

	/// \brief Draw the Button Surface Buffer
    void drawBackground(void);

};

}
}

#endif // DECORATEDBUTTON_H
