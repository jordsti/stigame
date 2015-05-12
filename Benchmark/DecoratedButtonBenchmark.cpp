#include "DecoratedButtonBenchmark.h"
#include <Texture.h>
#include <iostream>
#include "LabelBenchmark.h"
#include <Viewport.h>
DecoratedButtonBenchmark::DecoratedButtonBenchmark()
{
    max_frame_time = 35;
}

DecoratedButtonBenchmark::~DecoratedButtonBenchmark()
{
    auto lit(buttons.begin()), lend(buttons.end());
    for(;lit!=lend;++lit)
    {
        delete (*lit);
    }
}

void DecoratedButtonBenchmark::onStart(void)
{
    running = true;
}

void DecoratedButtonBenchmark::onPaint(SDL_Renderer *renderer)
{
    //one new label at each frame
    // + randomize all caption

    StiGame::Gui::DecoratedButton *btn = new StiGame::Gui::DecoratedButton();
    btn->setDimension(100, 22);

    int i = rand() % 10000000;
    std::string str = std::to_string(i);

    btn->setCaption(str);
    btn->setPoint(rand() % width, rand() % height);



    auto lit(buttons.begin()), lend(buttons.end());
    for(;lit!=lend;++lit)
    {
        StiGame::Gui::DecoratedButton *item = (*lit);

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

void DecoratedButtonBenchmark::frameRenderTime(long long frame_time)
{
    if(frame_time > max_frame_time)
    {
        std::cout << "Stopping Decorated Button benchmark" << std::endl;
        std::cout << "Last frame was rendered with " << buttons.size() << " buttons" << std::endl;

        LabelBenchmark *benchmark = new LabelBenchmark();
        viewport->clearProfilers();
        viewport->addProfiler(benchmark);
        viewport->push(benchmark);
    }
}
