#include "LabelBenchmark.h"
#include <iostream>
#include <Texture.h>
#include "ButtonBenchmark.h"
#include <Viewport.h>

LabelBenchmark::LabelBenchmark()
{
    //we are stopping when we are under 30 fps ~28
    max_frame_time = 35;
}

LabelBenchmark::~LabelBenchmark()
{
    auto lit(labels.begin()), lend(labels.end());
    for(;lit!=lend;++lit)
    {
        delete (*lit);
    }
}

void LabelBenchmark::onStart(void)
{
    running = true;
}

void LabelBenchmark::onPaint(SDL_Renderer *renderer)
{
    //one new label at each frame
    // + randomize all caption

    StiGame::Gui::Label *lbl = new StiGame::Gui::Label();

    int i = rand() % 10000000;
    std::string str = std::to_string(i);

    lbl->setCaption(str);
    lbl->setPoint(rand() % width, rand() % height);

    StiGame::Color *randColor = new StiGame::Color(rand() % 255, rand() % 255, rand() % 255);
    lbl->setForeground(randColor);

    auto lit(labels.begin()), lend(labels.end());
    for(;lit!=lend;++lit)
    {
        StiGame::Gui::Label *item = (*lit);

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

    labels.push_back(lbl);
}

void LabelBenchmark::frameRenderTime(long long frame_time)
{
    if(frame_time > max_frame_time)
    {
        std::cout << "Stopping label benchmark" << std::endl;
        std::cout << "Last frame was rendered with " << labels.size() << " labels" << std::endl;


        viewport->clearProfilers();

        ButtonBenchmark *benchmark = new ButtonBenchmark();

        viewport->addProfiler(benchmark);
        viewport->push(benchmark);
    }
}
