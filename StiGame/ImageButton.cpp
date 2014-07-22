
#include "ImageButton.h"
#include "PLine.h"

namespace StiGame
{

namespace Gui
{

ImageButton::ImageButton() : Item("ImageButton")
{
	image = 0;
	imageHover = 0;
	offsetWidth = DEFAULT_OFFSET;
	offsetHeight = DEFAULT_OFFSET;
	highlightForeground = style->getHighlightForeground();
	highlightBackground = style->getHighlightBackground();
}

void ImageButton::autosize(void)
{
	if(image != 0)
	{
		width = offsetWidth * 2 + image->getWidth();
		height = offsetHeight * 2 + image->getHeight();
	}
	else
	{
		width = offsetWidth;
		height = offsetHeight;
	}
}

void ImageButton::setImage(Surface *m_image)
{
	image = m_image;
}
void ImageButton::setImageHover(Surface *m_imageHover)
{
	imageHover = m_imageHover;
}

Surface *ImageButton::render(void)
{
	if(width == 0 || height == 0)
	{
		autosize();
	}

	Color *fg;
	Color *bg;

	if(mouseOver)
	{
		fg = highlightForeground;
		bg = highlightBackground;
	}
	else
	{
		fg = foreground;
		bg = background;
	}

	Surface *buffer = new Surface(width, height);
	buffer->fill(bg);

	Surface *img;

	if(mouseOver)
	{
		img = imageHover;
	}
	else
	{
		img = image;
	}

	//blitting image

	SDL_Rect *src = img->getRect();
	SDL_Rect *dst = img->getRect( ( width / 2 ) - ( img->getWidth() / 2 ), ( height / 2 ) - ( img->getHeight() / 2 ) );

	buffer->blit(img, src, dst);

	delete src;
	delete dst;

	//border

	PLine l1 = PLine();
	l1.set1(0, 0);
	l1.set2(width - 1, 0);

	PLine l2 = PLine();
	l2.set1(0, 0);
	l2.set2(0, height - 1);

	PLine l3 = PLine();
	l3.set1(width - 1, 0);
	l3.set2(width - 1, height - 1);

	PLine l4 = PLine();
	l4.set1(0, height - 1);
	l4.set2(width - 1, height - 1);

	buffer->draw(&l1, fg);
	buffer->draw(&l2, fg);
	buffer->draw(&l3, fg);
	buffer->draw(&l4, fg);

	return buffer;
}

void ImageButton::clear(void)
{

}

void ImageButton::onClick(Point *relp)
{
	EventArgs evt = EventArgs();
	publish(this, &evt);
}

ImageButton::~ImageButton(void)
{
	clear();
}

}

}
