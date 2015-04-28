#include "ItemDefinition.h"
#include "Label.h"
#include "Button.h"
#include "ImageButton.h"
#include "ComboBox.h"
#include "CheckBox.h"
#include "Image.h"
#include "List.h"
#include "DecoratedButton.h"
#include "ProgressBar.h"
#include "RadioButton.h"
#include "TextBox.h"
#include "SGString.h"
#include <iostream>
namespace StiGame
{

namespace Gui
{

ItemCreatorChain* ItemDefinition::externalCreator = new StartingCreator();

ItemCreatorChain* ItemDefinition::GetExternalCreator(void)
{
    return externalCreator;
}

void ItemDefinition::AppendCreator(ItemCreatorChain *chain)
{
    ItemCreatorChain *current = externalCreator;
    while(current->hasNext())
    {
        current = current->next();
    }

    current->setNext(chain);
}

ItemDefinition::ItemDefinition(std::string m_type)
{
    type = m_type;
    name = "not set";
    colorIndex = nullptr;
}

ItemAttribute* ItemDefinition::findAttribute(std::string m_name)
{
    auto lit(attributes.begin()), lend(attributes.end());
    for(;lit!=lend;++lit)
    {
        ItemAttribute *attr = (*lit);
        if(attr->getName() == m_name)
        {
            return attr;
        }
    }

    return nullptr;
}

void ItemDefinition::setColorIndex(ColorIndex *m_colorIndex)
{
    colorIndex = m_colorIndex;
}

ColorIndex* ItemDefinition::getColorIndex(void)
{
    return colorIndex;
}

void ItemDefinition::applyHighlightColors(HighlightItem *hItem)
{
    ItemAttribute *attr = findAttribute("highlightForeground");
    if(attr != nullptr)
    {
        Color *color = attr->getColor();
        if(color != nullptr)
        {
            if(colorIndex != nullptr)
            {
                colorIndex->add(color);
            }

            hItem->setHighlightForeground(color);
        }
    }

    attr = findAttribute("highlightBackground");
    if(attr != nullptr)
    {
        Color *color = attr->getColor();
        if(color != nullptr)
        {
            if(colorIndex != nullptr)
            {
                colorIndex->add(color);
            }

            hItem->setHighlightBackground(color);
        }
    }
}

Item* ItemDefinition::create(std::map<std::string, int> variables)
{
    if(name != "not set")
    {
        Item *item = nullptr;

        if(type == "Label")
        {
            Label *lbl = new Label();
            // trying to set label attribute, caption here
            ItemAttribute *attr = findAttribute("caption");
            if(attr != nullptr)
            {
                lbl->setCaption(attr->getValue());
            }

            item = lbl;
        }
        else if(type == "Button")
        {
            Button *btn = new Button();
            ItemAttribute *attr = findAttribute("caption");
            if(attr != nullptr)
            {
                btn->setCaption(attr->getValue());
            }

            applyHighlightColors(btn);

            item = btn;
        }
        else if(type == "CheckBox")
        {
            CheckBox *cb = new CheckBox();
            ItemAttribute *attr = findAttribute("caption");
            if(attr != nullptr)
            {
                cb->setCaption(attr->getName());
            }
            attr = findAttribute("checked");
            if(attr != nullptr)
            {
                cb->setChecked(attr->getValue() == "true");
            }

            item = cb;
        }
        else if(type == "ComboBox")
        {
            ComboBox *cb = new ComboBox();

            ItemAttribute *attr = findAttribute("values");
            if(attr != nullptr)
            {
                SGString vals (attr->getValue());
                std::vector<SGString> values = vals.split(',');
                auto lit(values.begin()), lend(values.end());
                for(;lit!=lend;++lit)
                {
                    ValueObject *vo = new ValueObject((*lit).getStdString());
                    cb->add(vo);
                }
            }

            applyHighlightColors(cb);
            item = cb;
        }
        else if(type == "Image")
        {
            Image *img = new Image();
            ItemAttribute *attr = findAttribute("image");
            if(attr != nullptr)
            {
                img->setImage(attr->getValue());
            }
            item = img;
        }
        else if(type == "ImageButton")
        {
            ImageButton *imgBtn = new ImageButton();
            //todo image path
            item = imgBtn;
        }
        else if(type == "List")
        {
            List *list = new List();
            applyHighlightColors(list);

            ItemAttribute *attr = findAttribute("values");
            if(attr != nullptr)
            {
                SGString vals (attr->getValue());
                std::vector<SGString> values = vals.split(',');
                auto lit(values.begin()), lend(values.end());
                for(;lit!=lend;++lit)
                {
                    ValueObject *vo = new ValueObject((*lit).getStdString());
                    list->add(vo);
                }
            }

            item = list;
        }
        else if(type == "DecoratedButton")
        {
            DecoratedButton *dbtn = new DecoratedButton();
            ItemAttribute *attr = findAttribute("caption");
            if(attr != nullptr)
            {
                dbtn->setCaption(attr->getValue());
            }
            item = dbtn;
        }
        else if(type == "ProgressBar")
        {
            ProgressBar *pb = new ProgressBar();

            ItemAttribute *attr = findAttribute("max");
            if(attr != nullptr)
            {
                pb->setMax(attr->getInt());
            }

            attr = findAttribute("current");
            if(attr != nullptr)
            {
                pb->setCurrent(attr->getInt());
            }

            item = pb;
        }
        else if(type == "RadioButton")
        {
            RadioButton *rbtn = new RadioButton();
            ItemAttribute *attr = findAttribute("caption");
            if(attr != nullptr)
            {
                rbtn->setCaption(attr->getValue());
            }

            attr = findAttribute("checked");
            if(attr != nullptr)
            {
                rbtn->setChecked(attr->getValue() == "true");
            }

            item = rbtn;
        }
        else if(type == "TextBox")
        {
            TextBox *tbox = new TextBox();
            ItemAttribute *attr = findAttribute("text");
            if(attr != nullptr)
            {
                tbox->setText(attr->getValue());
            }
            applyHighlightColors(tbox);
            item = tbox;
        }
        else
        {
            //we delay this to this external creator chain
            item = externalCreator->create(type, variables);
        }

        //generic attributes
        if(item != nullptr)
        {
            applyGenericAttributes(item, variables);
        }
        else
        {
            //todo make a better logger
            std::cout << "Error while trying to create a Gui::Item from a FrameFile : " << type << " type not supported" << std::endl;
        }

        return item;
    }
    else
    {
        //todo
        //error message here
        return nullptr;
    }
}

void ItemDefinition::applyGenericAttributes(Item *item, std::map<std::string, int> variables)
{
    auto lit(attributes.begin()), lend(attributes.end());
    for(;lit!=lend;++lit)
    {
        ItemAttribute *attr = (*lit);

        if(attr->getName() == "x")
        {
            item->setX(attr->getInt(variables));
        }
        else if(attr->getName() == "y")
        {
            item->setY(attr->getInt(variables));
        }
        else if(attr->getName() == "width")
        {
            item->setWidth(attr->getInt(variables));
        }
        else if(attr->getName() == "height")
        {
            item->setHeight(attr->getInt(variables));
        }
        else if(attr->getName() == "visible")
        {
            item->setVisible(attr->getValue() == "true");
        }
        else if(attr->getName() == "minimumSize")
        {
            std::string value = attr->getValue();
            //no equation here
            size_t sep_pos = value.find_first_of(',');
            if(sep_pos != std::string::npos)
            {
                int width = atoi(value.substr(0, sep_pos).c_str());
                int height = atoi(value.substr(sep_pos + 1).c_str());

                item->setMinimumSize(width, height);
            }
        }
        else if(attr->getName() == "maximumSize")
        {
            std::string value = attr->getValue();
            //no equation here
            size_t sep_pos = value.find_first_of(',');
            if(sep_pos != std::string::npos)
            {
                int width = atoi(value.substr(0, sep_pos).c_str());
                int height = atoi(value.substr(sep_pos + 1).c_str());

                item->setMaximumSize(width, height);
            }
        }
        else if(attr->getName() == "background")
        {
            Color *color = attr->getColor();
            if(color != nullptr)
            {
                if(colorIndex != nullptr)
                {
                    colorIndex->add(color);
                }

                item->setBackground(color);
            }
        }
        else if(attr->getName() == "foreground")
        {
            Color *color = attr->getColor();
            if(color != nullptr)
            {
                if(colorIndex != nullptr)
                {
                    colorIndex->add(color);
                }

                item->setForeground(color);
            }
        }
    }
}

std::string ItemDefinition::getName(void)
{
    return name;
}

ItemDefinition::~ItemDefinition()
{
    //todo
    //delete attributes
}

std::string ItemDefinition::getType(void)
{
    return type;
}

void ItemDefinition::setAttribute(std::string m_name, std::string m_value)
{
    if(m_name == "name")
    {
        name = m_value;
    }
    else
    {
        ItemAttribute *attr = new ItemAttribute(m_name, m_value);
        attributes.push_back(attr);
    }
}


}

}
