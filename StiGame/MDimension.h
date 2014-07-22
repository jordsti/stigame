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
        void setWidth(int m_width);
        void setHeight(int m_height);
        virtual ~MDimension();
    protected:
    private:
};

}

#endif // MDIMENSION_H
