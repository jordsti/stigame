#ifndef OVERLAYMENU_H
#define OVERLAYMENU_H

#include "Item.h"
#include "KeyEventListener.h"
#include <list>

namespace StiGame
{

namespace Gui
{

enum OverlayPosition { OP_MIDDLE,
					OP_TOP_LEFT_CORNER,
					OP_TOP_RIGHT_CORNER,
					OP_BOTTOM_LEFT_CORNER,
					OP_BOTTOM_RIGHT_CORNER,
					OP_CUSTOM };

class OverlayMenu :
    public Item/*,
    public KeyEventListener*/
{
    public:
        static const int DEFAULT_TIME_VISIBILITY;
		static const int DEFAULT_OFFSET;
        OverlayMenu();
        virtual ~OverlayMenu();
        virtual void onMouseMotion(Point *relp);
        virtual void onClick(Point *relp);
        virtual Surface* render(void);
        bool isVisible(void);
        void setVisible(bool m_visible);
		OverlayPosition getPosition(void);
		void setPosition(OverlayPosition m_position);
		void fixPosition(int m_width, int m_height);
		void add(Item *item);
        /*virtual void handleEvent(KeyEventThrower *src, KeyEventArgs *args);*/
    protected:
		Item* getLastItem(void);
		OverlayPosition position;
        std::list<Item*> items;
        bool visible;
		bool autosize;
		int _tick;
    private:
};

}

}

#endif // OVERLAY_H
