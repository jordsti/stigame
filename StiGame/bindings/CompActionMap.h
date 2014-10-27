#ifndef COMPACTIONMAP_H
#define COMPACTIONMAP_H

#include "ActionMap.h"
#include <list>

namespace StiGame
{

class CompActionMap :
    public ActionMap
{
    public:
        CompActionMap();
        CompActionMap(std::string m_name);
        virtual ~CompActionMap();
        bool isInput(InputType it);
        bool inputEquals(InputType it, int input); //need a rework on this
		InputType getInputType(void);
        std::string toString(void);
        void push(ActionMap *p_map);
        void remove(ActionMap *r_map);

        int getIntValue(void);
		
		int getCount(void);
		ActionMap* getMap(int index);
		
    protected:
        std::list<ActionMap*> actions;
    private:
};

}
#endif // COMPACTIONMAP_H
