#pragma once
#include "Item.h"
namespace StiGame
{

namespace Gui
{

/// \class Image
/// \brief Class that permit user to draw an image on a GuiState
class Image :
	public Item
{
public:
    /// \brief Constructor
    Image(void);
    /// \brief Destructor
    ~Image(void);
    Surface *render(void);
    /// \brief Set the image with the file path
    /// \param m_imagePath Image path
    void setImage(std::string m_imagePath);
    /// \brief Draw border
    /// \param m_drawBorder draw it or not
    void setDrawBorder(bool m_drawBorder);
    /// \brief Set the alpha blending
    /// \param n_alpha Alpha value (0-255)
    void setAlpha(int n_alpha);
protected:
    /// \brief Load the image
    void loadImage(void);
    /// \brief Image Buffer
    Surface *imageBuffer;
    /// \brief Image Path
    std::string imagePath;
    /// \brief Draw the border
    bool drawBorder;
};

}

}
