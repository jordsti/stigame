#include "Table.h"
#include "PLine.h"

namespace StiGame
{

namespace Gui
{


const int Table::DEFAULT_COL_WIDTH = 50;
const int Table::DEFAULT_ROW_HEIGHT = 20;

Table::Table() : HighlightItem("Table")
{
	nbColumns = 0;
    rowHeight = DEFAULT_ROW_HEIGHT;
    font = style->getNormalFont();
}

Table::~Table()
{
    auto rit(rows.begin()), rend(rows.end());
    for(;rit!=rend;++rit)
    {
        TableRow *row = (*rit);
        delete row;
    }

    auto cit(columns.begin()), cend(columns.end());
    for(;cit!=cend;++cit)
    {
        delete (*cit);
    }
}

Surface* Table::render(void)
{
	Surface *buffer = new Surface(width, height);
	buffer->fill(background);

	//drawing columns

	std::vector<TableColumn*>::iterator cit(columns.begin()), cend(columns.end());
    SDL_Rect *src = new SDL_Rect();
    SDL_Rect *dst = new SDL_Rect();
	PLine line = PLine();
	int dx = 0;
	int dy = 0;

	int colwidths[nbColumns];

    //mouse hover row
    int m_row = -1;
    if(mouseOver)
    {
        m_row = (mousePosition.getY() / rowHeight) -1;
    }

	//colwidths = new int[nbColumns];

	int ic = 0;
	for(;cit!=cend;++cit)
	{
		TableColumn *col = (*cit);

		Surface *csur = col->surface;
        csur->updateSDLRect(src);

        dst->w = col->width;
        dst->h = csur->getHeight();
        dst->x = dx + ( col->width - csur->getWidth() ) / 2;
        dst->y = dy + ( rowHeight - csur->getHeight() ) / 2;

        buffer->blit(csur, src, dst);

        line.set1(dx + col->width - 1, 0);
        line.set2(dx + col->width - 1, rowHeight - 1);

        line.draw(buffer->getSDLSurface(), foreground);
		colwidths[ic] = col->width;
		dx += col->width;
		ic++;
	}
	dx = 0;
	dy += rowHeight;

	line.set1(0, rowHeight);
	line.set2(width - 1, rowHeight);

    line.draw(buffer->getSDLSurface(), foreground);

	//drawing rows
    int i_r = 0;
	std::vector<TableRow*>::iterator rit(rows.begin()), rend(rows.end());
	for(;rit!=rend;++rit)
	{
		if(dy > height)
		{
			break;
		}

		TableRow *row = (*rit);

        if(i_r == m_row)
        {
            Rectangle rect (0, dy, width, rowHeight);
            buffer->fillRect(&rect, highlightBackground);
        }



        int row_x = 0;

		for(int i=0; i<nbColumns; i++)
		{
            TableCell *cell = row->getCell(i);
            Surface *str_sur = cell->getSurface();

            if(i_r == m_row)
            {
                //render a new String Surface with highlight foreground color
                str_sur = font->renderText(cell->getValue(), highlightForeground);
            }

            str_sur->updateSDLRect(src);
            dst->x = row_x + ((colwidths[i] - str_sur->getWidth()) / 2);
            //dst->x = row_x;
            dst->y = dy + ((rowHeight - str_sur->getHeight()) / 2);
            dst->w = str_sur->getWidth();
            dst->h = str_sur->getHeight();
            buffer->blit(str_sur, src, dst);

            line.set1(row_x + colwidths[i] - 1, dy);
            line.set2(row_x + colwidths[i] - 1, dy + rowHeight - 1);

            line.draw(buffer->getSDLSurface(), foreground);
            //todo

            row_x += colwidths[i];

            if(i_r == m_row)
            {
                delete str_sur;
            }
		}

		line.set1(0, dy + rowHeight - 1);
		line.set2(width - 1, dy + rowHeight - 1);

		line.draw(buffer->getSDLSurface(), foreground);

        dy += rowHeight;

        i_r++;
	}

	//border drawing


    delete src;
    delete dst;

	return buffer;
}

int Table::MinWidth(int w1, int w2)
{
	if(w1 < w2)
	{
		return w1;
	}
	else if(w2 < w1)
	{
		return w2;
	}

	return w1;
}

TableRow* Table::getRow(int index)
{
	return rows[index];
}

void Table::removeRow(int index)
{
    auto rit(rows.begin()), rend(rows.end());
    int id=0;
    for(;rit!=rend;++rit)
    {
        if(index == id)
        {
            TableRow *row = (*rit);
            rows.erase(rit);
            delete row;
            break;
        }
        id++;
    }
}

void Table::removeRow(TableRow *row)
{
    auto rit(rows.begin()), rend(rows.end());
    for(;rit!=rend;++rit)
    {
        TableRow *_row = (*rit);
        if(_row == row)
        {
            delete _row;
            rows.erase(rit);
            break;
        }
    }
}

void Table::setForeground(Color* m_foreground)
{
	foreground = m_foreground;

	std::vector<TableRow*>::iterator rit(rows.begin()), rend(rows.end());

	for(;rit!=rend;++rit)
	{
		for(int i=0; i<nbColumns; i++)
		{
			TableCell *cell = (*rit)->getCell(i);
			cell->getStringRenderer()->setColor(foreground);
		}
	}

}

int Table::countRows(void)
{
	return rows.size();
}

void Table::addColumn(std::string c_name)
{
	addColumn(c_name, DEFAULT_COL_WIDTH);
}

void Table::addColumn(std::string c_name, int width)
{
	TableColumn *col = new TableColumn();
	col->name = c_name;
	col->width = width;
	col->surface = font->renderText(c_name, foreground);
	columns.push_back(col);
	nbColumns++;
}

Font* Table::getFont(void)
{
	return font;
}

void Table::setFont(Font *m_font)
{
	font = m_font;

	std::vector<TableColumn*>::iterator cit(columns.begin()), cend(columns.end());

	for(;cit!=cend;++cit)
	{
		delete (*cit)->surface;
		(*cit)->surface = font->renderText((*cit)->name, foreground);
	}

	std::vector<TableRow*>::iterator rit(rows.begin()), rend(rows.end());

	for(;rit!=rend;++rit)
	{
		for(int i=0; i<nbColumns; i++)
		{
			TableCell *cell = (*rit)->getCell(i);
			cell->getStringRenderer()->setFont(font);
		}
	}
}

int Table::getRowHeight(void)
{
	return rowHeight;
}

void Table::setRowHeight(int m_rowHeight)
{
	rowHeight = m_rowHeight;
}

TableRow* Table::newRow(void)
{
	TableRow *row = new TableRow();

	for(int i=0; i<nbColumns; i++)
	{
		TableCell *cell = new TableCell();
		row->addCell(cell);
	}

	rows.push_back(row);
	return row;
}

void Table::onClick(Point *relp)
{
    int rowIndex = (relp->getY() / rowHeight) - 1;
    int colIndex = -1;
    if(rowIndex < rows.size() || rowIndex == -1)
    {
        auto cit(columns.begin()), cend(columns.end());
        int cur_x = 0;
        int index = 0;
        for(;cit!=cend;++cit)
        {
            TableColumn *col = (*cit);
            if(relp->getX() > cur_x && relp->getX() < cur_x + col->width)
            {
                colIndex = index;
            }

            cur_x += col->width;
            index++;
        }

        if(colIndex >= 0 && rowIndex >= 0)
        {
            TableRow *row = rows[rowIndex];
            TableCell *cell = row->getCell(colIndex);

            TableClickEventArgs args (this, row, cell, rowIndex, colIndex);
            publish(this, &args);
        }
        else if(colIndex >= 0 && rowIndex == -1)
        {
            //header clicked
            TableClickEventArgs args (this, nullptr, nullptr, rowIndex, colIndex);
            publish(this, &args);
        }
    }
}

void Table::onMouseMotion(Point *relp)
{
    mousePosition.setPoint(relp);
}


}

}
