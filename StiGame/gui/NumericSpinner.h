#ifndef NUMERICSPINNER_H
#define NUMERICSPINNER_H
#include "Item.h"
#include "FontSupport.h"
#include "StringRenderer.h"
#include "EventThrower.h"
#include "ItemValueChangedEventThrower.h"
namespace StiGame {

namespace Gui {

class NumericSpinner :
        public Item,
        public FontSupport,
        public EventThrower,
        public ItemValueChangedEventThrower
{

public:
    static const int DEFAULT_MIN;
    static const int DEFAULT_MAX;
    static const int DEFAULT_WIDTH;
    static const int DEFAULT_HEIGHT;
    static const int DEFAULT_STEP;

    NumericSpinner();
    virtual ~NumericSpinner();

    void setMin(int m_min);
    int getMin(void);

    void setMax(int m_max);
    int getMax(void);

    void setValue(int m_value);
    int getValue(void);

    Surface* render(void);

    void setFont(Font *m_font);

    void onClick(Point *relp);

    Surface* getUpArrow(void);
    Surface* getDownArrow(void);

    void setUpArrow(Surface *m_upArrow);
    void setDownArrow(Surface *m_downArrow);

    int getStep(void);
    void setStep(int m_step);

private:
    Surface *upArrow;
    Surface *downArrow;
    StringRenderer stringBuffer;
    int value;
    int min;
    int max;
    int step;
};

}

}

#endif // NUMERICSPINNER_H
