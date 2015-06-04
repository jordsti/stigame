#include "NumericSpinner.h"
#include "PRect.h"
#include "EventArgs.h"
#include "IntegerItemValue.h"

namespace StiGame
{

namespace Gui
{

const int NumericSpinner::DEFAULT_MIN = 0;
const int NumericSpinner::DEFAULT_MAX = 4906;
const int NumericSpinner::DEFAULT_WIDTH = 120;
const int NumericSpinner::DEFAULT_HEIGHT = 22;
const int NumericSpinner::DEFAULT_STEP = 1;

NumericSpinner::NumericSpinner() :
    Item("NumericSpinner"),
    FontSupport(),
    EventThrower()
{
    width = DEFAULT_WIDTH;
    height = DEFAULT_HEIGHT;
    min = DEFAULT_MIN;
    max = DEFAULT_MAX;
    value = min;
    step = DEFAULT_STEP;
    stringBuffer.setFont(font);
    stringBuffer.setText(std::to_string(value));

    upArrow = style->getSpinnerUpArrow();
    downArrow = style->getSpinnerDownArrow();
}

NumericSpinner::~NumericSpinner()
{

}

int NumericSpinner::getStep(void)
{
    return step;
}

void NumericSpinner::setStep(int m_step)
{
    step = m_step;
}

void NumericSpinner::setFont(Font *m_font)
{
    FontSupport::setFont(m_font);
    stringBuffer.setFont(m_font);
}

void NumericSpinner::setMin(int m_min)
{
    min = m_min;
}

int NumericSpinner::getMin(void)
{
    return min;
}

void NumericSpinner::setMax(int m_max)
{
    max = m_max;
}

int NumericSpinner::getMax(void)
{
    return max;
}

void NumericSpinner::setValue(int m_value)
{
    value = m_value;
    stringBuffer.setText(std::to_string(value));
}

int NumericSpinner::getValue(void)
{
    return value;
}

Surface* NumericSpinner::render(void)
{
    Surface *buffer = new Surface(width, height);
    buffer->fill(background);

    Surface *string = stringBuffer.getSurface();

    //middling the Y, X is offset determinied

    Point dstStr (3, (height - string->getHeight())/2);
    buffer->blit(string, &dstStr);

    Point upPt (width - upArrow->getWidth() - 1, 0);
    Point downPt (width - downArrow->getWidth() - 1, height - downArrow->getHeight());

    buffer->blit(upArrow, &upPt);
    buffer->blit(downArrow, &downPt);

    PRect border (0, 0, width-1, height-1);
    buffer->draw(&border, foreground);

    return buffer;
}

void NumericSpinner::onClick(Point *relp)
{
    Rectangle upRect (width - upArrow->getWidth() - 1,
                      0,
                      upArrow->getWidth(),
                      upArrow->getHeight());
    Rectangle downRect (width - downArrow->getWidth() - 1,
                        height - downArrow->getHeight(),
                        downArrow->getWidth(),
                        downArrow->getHeight());

    if(upRect.contains(relp))
    {
        if(value + step <= max)
        {
            EventArgs args;
            EventThrower::publish(this, &args);

            //item value changed events
            ItemValue *oldVal = new IntegerItemValue(this, value);
            ItemValue *newVal = new IntegerItemValue(this, value + step);
            ItemValueChangedEventArgs ivArgs(oldVal, newVal);

            ItemValueChangedEventThrower::publish(this, &ivArgs);

            value += step;
            stringBuffer.setText(std::to_string(value));
        }
    }
    else if(downRect.contains(relp))
    {
        if(value - step >= min)
        {
            EventArgs args;
            EventThrower::publish(this, &args);

            //item value changed events
            ItemValue *oldVal = new IntegerItemValue(this, value);
            ItemValue *newVal = new IntegerItemValue(this, value + step);
            ItemValueChangedEventArgs ivArgs(oldVal, newVal);

            ItemValueChangedEventThrower::publish(this, &ivArgs);

            value -= step;
            stringBuffer.setText(std::to_string(value));
        }
    }
}

Surface* NumericSpinner::getUpArrow(void)
{
    return upArrow;
}

Surface* NumericSpinner::getDownArrow(void)
{
    return downArrow;
}

void NumericSpinner::setUpArrow(Surface *m_upArrow)
{
    upArrow = m_upArrow;
}

void NumericSpinner::setDownArrow(Surface *m_downArrow)
{
    downArrow = m_downArrow;
}

}

}
