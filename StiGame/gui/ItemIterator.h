#ifndef ITEMITERATOR_H
#define ITEMITERATOR_H
#include "ItemNode.h"
namespace StiGame {

namespace Gui {

namespace _future {

class ItemIterator {
public:
    ItemIterator(ItemNode *m_firstItem);
    virtual ~ItemIterator();

    Item *item(void);
    bool next(void);
    bool nextWithClear(void);
    ItemNode *node(void);
    //publish event methods
    void publishOnMouseMotion(int mouse_x, int mouse_y);
    void publishOnClick(int mouse_x, int mouse_y);
    void publishTextInput(char *text);
    void publishOnKeyUp(SDL_KeyboardEvent *evt);

private:
    ItemNode *_start;
    ItemNode *_current;
};

}
}
}

#endif // ITEMITERATOR_H
