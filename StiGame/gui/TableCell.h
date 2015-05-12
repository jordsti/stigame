#ifndef TABLECELL_H
#define TABLECELL_H

#include <string>
#include "StringRenderer.h"
#include "CellValueChangedEventThrower.h"
namespace StiGame
{

namespace Gui
{

/// \class TableCell
/// \brief A Cell in the table
class TableCell :
        public CellValueChangedEventThrower
{
public:
	/// \brief Constructor
	TableCell();
	/// \brief Destructor
	virtual ~TableCell();
	/// \brief Get the current Text value
	/// \return Text Value
	std::string getValue(void);
	/// \brief Set the Text value
	/// \param m_value Text value
	void setValue(std::string m_value);
	
	/// \brief Get the String getStringRenderer
	/// \return String renderer
	StringRenderer* getStringRenderer(void);
	/// \brief Get the rendered Surface
	/// \return Surface Pointer
	Surface* getSurface(void);

    Color* getForeground(void);
    void setForeground(Color *m_foreground);

    Font* getFont(void);
    void setFont(Font *m_font);

    int getWidth(void);

    int getHeight(void);

protected:
	/// \brief Text value
	std::string value;
	/// \brief String Renderer
	StringRenderer str_renderer;
};


}


}

#endif
