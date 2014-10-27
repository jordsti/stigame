#ifndef MDIMENSION_H
#define MDIMENSION_H
#include "Dimension.h"
namespace StiGame
{

class MDimension :
    public Dimension
{
    public:
        MDimension();
        MDimension(int m_width, int m_height);
        MDimension(DimensionStruct *dim);
        virtual void setWidth(int m_width);
        virtual void setHeight(int m_height);

        virtual void setDimension(int m_width, int m_height);

        virtual ~MDimension();
    protected:
    private:
};

}

#endif // MDIMENSION_H
