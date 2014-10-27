#ifndef MDIMENSIONF_H
#define MDIMENSIONF_H

#include "DimensionF.h"

namespace StiGame
{

class MDimensionF :
        public DimensionF
{
public:
    MDimensionF();
    MDimensionF(float m_width, float m_height);

    virtual ~MDimensionF();

    virtual void setWidth(float m_width);
    virtual void setHeight(float m_height);
    virtual void setDimension(float m_width, float m_height);
};

}
#endif // MDIMENSIONF_H
