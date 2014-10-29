#include <iostream>
#include "ScriptReader.h"

int main(int argc, char ** argv)
{
    std::vector< std::string > scripts;
    std::vector< sgrc::ScriptReader* > readers;

    int i=1;
    while(argc > i)
    {
        //debug
        std::cout << i << ": " << argv[i] << std::endl;

        std::string script (argv[i]);
        scripts.push_back(script);

        i++;
    }


    auto vit(scripts.begin()), vend(scripts.end());
    for(;vit!=vend;++vit)
    {
        sgrc::ScriptReader *reader = new sgrc::ScriptReader((*vit));
        reader->read();

        readers.push_back(reader);
    }

    auto rit(readers.begin()), rend(readers.end());
    for(;rit!=rend;++rit)
    {
        int length = (*rit)->getSize();
        for(int i=0; i<length; i++)
        {
            sgrc::ScriptContext *context = (*rit)->getContext(i);
            context->execute();
        }
    }


    return 0;
}
