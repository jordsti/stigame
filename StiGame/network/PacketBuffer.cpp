#include "PacketBuffer.h"

namespace StiGame
{

namespace Net
{

PacketBuffer::PacketBuffer()
{
    //ctor
    maxLength = LENGTH;
    currentPosition = 0;
    dataLength = 0;

    for(int i=0; i<maxLength; i++)
    {
        data[i] = 0;
    }
}

int PacketBuffer::getDataLength()
{
    return dataLength;
}

int PacketBuffer::getLength()
{
    return maxLength;
}

int PacketBuffer::getCurrentPosition()
{
    return currentPosition;
}

PacketBuffer::~PacketBuffer()
{
    //dtor
}

}

}
