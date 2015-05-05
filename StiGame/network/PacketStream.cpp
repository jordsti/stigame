#include "PacketStream.h"
#include <iostream>
namespace StiGame {

namespace Net
{

PacketStream::PacketStream(IPacket *m_packet)
{
    packet = m_packet;
    currentIndex = 0;
}

PacketStream::~PacketStream()
{

}

IPacket* PacketStream::getPacket(void)
{
    return packet;
}

void PacketStream::writeString(std::string m_string)
{
    for(int i=0; i<m_string.length(); i++)
    {
        packet->write(m_string[i], currentIndex);
        currentIndex++;
    }

    //null char (string end)
    packet->write('\0', currentIndex);
    currentIndex++;

    packet->setLen(currentIndex);
}

void PacketStream::writeInt32(int m_int)
{
    unsigned int size = 4;

    char* bytes = reinterpret_cast<char*>(&m_int);
    for(int i=0; i<size; i++)
    {
        packet->write(bytes[i], currentIndex + i);
    }

    currentIndex += size;
    packet->setLen(currentIndex);
}

void PacketStream::writeUInt32(unsigned int m_int)
{
    unsigned int size = 4;
    char* bytes = reinterpret_cast<char*>(&m_int);
    for(int i=0; i<size; i++)
    {
        packet->write(bytes[i], currentIndex + i);
    }

    currentIndex += size;
    packet->setLen(currentIndex);
}

std::string PacketStream::readString(void)
{
    std::string m_string = "";
    while(true)
    {
        char c = packet->read(currentIndex);
        currentIndex++;
        if(c == '\0')
        {
            break;
        }
        else
        {
            m_string += c;
        }
    }

    return m_string;
}

int PacketStream::readInt32(void)
{
    int m_int = 0;
    unsigned int size = 4;
    char bytes[size];

    for(unsigned int i=0; i<size; i++)
    {
        bytes[i] = packet->read(currentIndex);
        currentIndex++;
    }

    m_int += (int)bytes[3];
    m_int <<= 8;
    m_int += (int)bytes[2];
    m_int <<= 8;
    m_int += (int)bytes[1];
    m_int <<= 8;
    m_int += (int)bytes[0];

    return m_int;
}

unsigned int PacketStream::readUInt32(void)
{
    unsigned int m_int = 0;
    unsigned int size = 4;
    char bytes[size];

    for(unsigned int i=0; i<size; i++)
    {
        bytes[i] = packet->read(currentIndex);
        currentIndex++;
    }

    m_int += (unsigned int)bytes[3];
    m_int <<= 8;
    m_int += (unsigned int)bytes[2];
    m_int <<= 8;
    m_int += (unsigned int)bytes[1];
    m_int <<= 8;
    m_int += (unsigned int)bytes[0];

    return m_int;
}

}

}
