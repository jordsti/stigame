#ifndef ITEMEFFECT_H
#define ITEMEFFECT_H
#include "Item.h"
#include "BaseGameState.h"
#include "EffectEventThrower.h"
namespace StiGame {

namespace Gui {

namespace Effects {


class ItemEffect :
        public Item,
        public EffectEventThrower
{
public:
    ItemEffect(Item *m_item, BaseGameState *m_state);
    virtual ~ItemEffect();

    virtual Surface* render(void);

    bool isTerminated(void);

    virtual void onClick(Point *relp);
    virtual void onKeyUp(SDL_KeyboardEvent *evt);
    virtual void setMouseOver(bool m_mouseOver);
    virtual void onMouseMotion(Point *relp);
    virtual void onTextInput(char* text);
    virtual bool isHandleKey(void);

    Item* getItem(void);
    BaseGameState* getState(void);

protected:
    void setTerminated(bool m_terminated);

    bool eventDuringEffect;
    bool redrawAtEachFrame;

    virtual Surface *renderWithEffect(void) = 0;

    virtual void tickEffect(void) = 0;

    Item *item;
    BaseGameState *state;
    Surface *effectBuffer;
private:
    bool terminated;
};

}

}

}

#endif // ITEMEFFECT_H
