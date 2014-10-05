#ifndef DIMENSIONF_H
#define DIMENSIONF_H

#include "Dimension.h"

namespace StiGame
{

class DimensionF
{
public:
    DimensionF();
    DimensionF(float m_width, float m_height);
    virtual ~DimensionF();

    virtual bool isEmpty(void);
    float getWidth(void);
    float getHeight(void);
    Dimension toDimension(void);

protected:
    float width;
    float height;
};

}
#endif // DIMENSIONF_H
