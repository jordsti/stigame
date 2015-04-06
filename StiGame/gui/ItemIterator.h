#ifndef ITEMITERATOR_H
#define ITEMITERATOR_H
#include "ItemNode.h"
namespace StiGame {

namespace Gui {

/// \class ItemIterator
/// \brief Iterator to go through a starting node until the end is hit
class ItemIterator {
public:
    /// \brief Constructor, with the starting node
    /// \param m_firstNode First Node
    ItemIterator(ItemNode *m_firstNode);
    /// \brief Destructor
    virtual ~ItemIterator();
    /// \brief Get the current item
    /// \return Current Item Pointer
    Item *item(void);
    /// \brief Try to advance to the next node
    /// \return Success or the end is hitted
    bool next(void);
    /// \brief Try to advance to the next node and freeing the previous node
    /// \return Success or the end is hitted
    bool nextWithClear(void);
    /// \brief Get the current Node Pointer
    /// \return Node Pointer
    ItemNode *node(void);
    //publish event methods
    /// \brief Publish Mouse Motion Event through the nodes
    /// \param mouse_x Mouse X (px)
    /// \param mouse_y Mouse Y (px)
    void publishOnMouseMotion(int mouse_x, int mouse_y);
    /// \brief Publish Mouse Motion Event through the nodes
    /// \param pt Mouse Position (px)
    void publishOnMouseMotion(Point *pt);
    /// \brief Publish On Click Event through the nodes
    /// \param mouse_x Mouse X (px)
    /// \param mouse_y Mouse Y (px)
    void publishOnClick(Point *pt);
    /// \brief Publish On Click Event through the nodes
    /// \param pt Click Position (px)
    void publishOnClick(int mouse_x, int mouse_y);
    /// \brief Publish Text Input Event through the nodes
    /// \param text Character(s)
    void publishTextInput(char *text);
    /// \brief Publish On Key Up Event through the nodes
    /// \param evt Keyboard Event
    void publishOnKeyUp(SDL_KeyboardEvent *evt);
    /// \brief Return to the beginning of the iterator
    void reset(void);
private:
    /// \brief Starting node of the iterator
    ItemNode *_start;
    /// \brief Current position of the iterator
    ItemNode *_current;
};

}
}

#endif // ITEMITERATOR_H
