#ifndef COMPACTIONMAP_H
#define COMPACTIONMAP_H

#include "ActionMap.h"
#include <list>

namespace StiGame
{
/// \class CompActionMap
/// \brief Composite Action Map, act as one Action Map, can contains many
class CompActionMap :
    public ActionMap
{
    public:
        /// \brief Constructor
        CompActionMap();
        /// \brief Constructor with the specified Action name
        CompActionMap(std::string m_name);
        /// \brief Destructor
        virtual ~CompActionMap();

        bool isInput(InputType it);
        bool inputEquals(InputType it, int input); //need a rework on this
		InputType getInputType(void);


        std::string toString(void);

        /// \brief Add a new ActionMap
        /// \param p_map Action Map to add
        void push(ActionMap *p_map);
        /// \brief Remove an ActionMap
        /// \param r_map Action Map to remove
        void remove(ActionMap *r_map);

        int getIntValue(void);
        /// \brief Get Count of the Action Map
        /// \return Count of Action Map
		int getCount(void);
        /// \brief Get the Action Map at the specified index
        /// \param index Index
        /// \return ActionMap
		ActionMap* getMap(int index);
		
    protected:
        /// \brief Contained Action Maps
        std::list<ActionMap*> actions;
    private:
};

}
#endif // COMPACTIONMAP_H
