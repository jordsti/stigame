#include "ButtonBenchmark.h"
#include <Texture.h>
#include <iostream>
#include <Viewport.h>

ButtonBenchmark::ButtonBenchmark()
{
    max_frame_time = 35;
}

ButtonBenchmark::~ButtonBenchmark()
{
    auto lit(buttons.begin()), lend(buttons.end());
    for(;lit!=lend;++lit)
    {
        delete (*lit);
    }
}

void ButtonBenchmark::onStart(void)
{
    running = true;
}

void ButtonBenchmark::onPaint(SDL_Renderer *renderer)
{
    //one new label at each frame
    // + randomize all caption

    StiGame::Gui::Button *btn = new StiGame::Gui::Button();
    btn->setDimension(100, 22);

    int i = rand() % 10000000;
    std::string str = std::to_string(i);

    btn->setCaption(str);
    btn->setPoint(rand() % width, rand() % height);

    StiGame::Color *bg = new StiGame::Color(rand() % 255, rand() % 255, rand() % 255);
    StiGame::Color *fg = new StiGame::Color(rand() % 255, rand() % 255, rand() % 255);

    btn->setBackground(bg);
    btn->setForeground(fg);

    auto lit(buttons.begin()), lend(buttons.end());
    for(;lit!=lend;++lit)
    {
        StiGame::Gui::Button *item = (*lit);

        i = rand() % 10000000;
        str = std::to_string(i);

        item->setCaption(str);

        //moving the sprite

        item->setPoint(item->getX() + (rand() % 2) - 1, item->getY() + (rand() % 2) - 1);

        if(item->getX() > width || item->getX() < 0)
        {
            item->setPoint(rand() % width, item->getY());
        }

        if(item->getY() > height || item->getY() < 0)
        {
            item->setPoint(item->getX(), rand() % height);
        }

        StiGame::Surface *buffer = item->render();
        StiGame::Texture tex (renderer, buffer);
        tex.renderCopy(item);
    }

    buttons.push_back(btn);
}

void ButtonBenchmark::frameRenderTime(long long frame_time)
{
    if(frame_time > max_frame_time)
    {
        std::cout << "Stopping Button benchmark" << std::endl;
        std::cout << "Last frame was rendered with " << buttons.size() << " buttons" << std::endl;
        running = false;
    }
}
