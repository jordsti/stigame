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
    for(unsigned int i=0; i<m_string.length(); i++)
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
    for(unsigned int i=0; i<size; i++)
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
    for(unsigned int i=0; i<size; i++)
    {
        packet->write(bytes[i], currentIndex + i);
    }

    currentIndex += size;
    packet->setLen(currentIndex);
}

void PacketStream::writeInt16(short m_int)
{
    unsigned int size = 2;
    char * bytes = reinterpret_cast<char*>(&m_int);
    for(unsigned int i=0; i<size; i++)
    {
        packet->write(bytes[i], currentIndex + i);
    }

    currentIndex += size;
    packet->setLen(currentIndex);
}

void PacketStream::writeUInt16(unsigned short m_int)
{
    unsigned int size = 2;
    char * bytes = reinterpret_cast<char*>(&m_int);
    for(unsigned int i=0; i<size; i++)
    {
        packet->write(bytes[i], currentIndex + i);
    }

    currentIndex += size;
    packet->setLen(currentIndex);
}

void PacketStream::writeInt64(long m_long)
{
    unsigned int size = 8;
    char * bytes = reinterpret_cast<char*>(&m_long);
    for(unsigned int i=0; i<size; i++)
    {
        packet->write(bytes[i], currentIndex + i);
    }

    currentIndex += size;
    packet->setLen(currentIndex);
}

void PacketStream::writeUInt64(unsigned long m_long)
{
    unsigned int size = 8;
    char * bytes = reinterpret_cast<char*>(&m_long);
    for(unsigned int i=0; i<size; i++)
    {
        packet->write(bytes[i], currentIndex + i);
    }

    currentIndex += size;
    packet->setLen(currentIndex);
}

void PacketStream::writeBool(bool m_bool)
{
    char value = 0;
    if(m_bool)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    packet->write(value, currentIndex);
    currentIndex++;
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

short PacketStream::readInt16(void)
{
    short m_int = 0;
    unsigned int size = 2;
    char bytes[size];

    for(unsigned int i=0; i<size; i++)
    {
        bytes[i] = packet->read(currentIndex);
        currentIndex++;
    }

    m_int += (short)bytes[1];
    m_int <<= 8;
    m_int += (short)bytes[0];

    return m_int;
}

unsigned short PacketStream::readUInt16(void)
{
    unsigned short m_int = 0;
    unsigned int size = 2;
    char bytes[size];

    for(unsigned int i=0; i<size; i++)
    {
        bytes[i] = packet->read(currentIndex);
        currentIndex++;
    }

    m_int += (unsigned short)bytes[1];
    m_int <<= 8;
    m_int += (unsigned short)bytes[0];

    return m_int;
}

long PacketStream::readInt64(void)
{
    long m_long = 0;
    unsigned int size = 8;
    char bytes[size];

    for(unsigned int i=0; i<size; i++)
    {
        bytes[i] = packet->read(currentIndex);
        currentIndex++;
    }

    m_long += (int)bytes[7];
    m_long <<= 8;
    m_long += (int)bytes[6];
    m_long <<= 8;
    m_long += (int)bytes[5];
    m_long <<= 8;
    m_long += (int)bytes[4];
    m_long <<= 8;
    m_long += (int)bytes[3];
    m_long <<= 8;
    m_long += (int)bytes[2];
    m_long <<= 8;
    m_long += (int)bytes[1];
    m_long <<= 8;
    m_long += (int)bytes[0];

    return m_long;
}

unsigned long PacketStream::readUInt64(void)
{
    unsigned long m_long = 0;
    unsigned int size = 8;
    char bytes[size];

    for(unsigned int i=0; i<size; i++)
    {
        bytes[i] = packet->read(currentIndex);
        currentIndex++;
    }

    m_long += (int)bytes[7];
    m_long <<= 8;
    m_long += (int)bytes[6];
    m_long <<= 8;
    m_long += (int)bytes[5];
    m_long <<= 8;
    m_long += (int)bytes[4];
    m_long <<= 8;
    m_long += (int)bytes[3];
    m_long <<= 8;
    m_long += (int)bytes[2];
    m_long <<= 8;
    m_long += (int)bytes[1];
    m_long <<= 8;
    m_long += (int)bytes[0];

    return m_long;
}

bool PacketStream::readBool()
{
    bool value = false;

    char chr_value = packet->read(currentIndex);
    currentIndex++;

    if(chr_value == 1)
    {
        value = true;
    }

    return value;
}

}

}
