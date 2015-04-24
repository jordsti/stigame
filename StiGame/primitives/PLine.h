#pragma once
#include "Primitive.h"
#include "math.h"
namespace StiGame
{

/// \class PLine
/// \brief Draw a Line
class PLine :
	public Primitive
{
public:
    /// \brief Constructor
	PLine(void);
    /// \brief Destructor
	~PLine(void);
	void fill(SDL_Surface *surface, Color *color);
	void draw(SDL_Surface *surface, Color *color);
	void draw(SDL_Renderer *renderer, Color *color);
    void fill(SDL_Renderer *renderer, Color *color);

    /// \brief Set the Starting Point
    /// \param m_x X (px)
    /// \param m_y Y (px)
    void set1(int m_x, int m_y);
    /// \brief Set the Ending Point
    /// \param m_x X (px)
    /// \param m_y Y (px)
    void set2(int m_x, int m_y);
    /// \brief Get Starting X
    /// \return Start X (px)
	int getX1(void);
    /// \brief Get Starting Y
    /// \return Start Y (px)
	int getY1(void);
    /// \brief Get End X
    /// \return End X (px)
	int getX2(void);
    /// \brief Get End Y
    /// \return End Y (px)
	int getY2(void);
    /// \brief Get Line Weight
    /// \return Line Weight
	int getSize(void);
    /// \brief Set the line weight
    /// \param m_size Line Weight
    void setSize(int m_size);
protected:
	void fillHLine(SDL_Surface*, Color*);
	void fillVLine(SDL_Surface*, Color*);
	void fillTanLine(SDL_Surface*, Color*);
	void switchPoints(void);
    /// \brief X Start
    int x1;
    /// \brief Y Start
    int y1;
    /// \brief X End
    int x2;
    /// \brief Y End
    int y2;
    /// \brief Line Weight
    int size;
};

}

