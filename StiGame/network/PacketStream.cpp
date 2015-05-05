#include "PacketStream.h"

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
    packet->write(static_cast<char*>(static_cast<void*>(&m_int)), currentIndex, sizeof(m_int));
    currentIndex += sizeof(m_int);

    packet->setLen(currentIndex);
}

std::string PacketStream::readString(void)
{
    std::string m_string = "";
    while(true)
    {
        char c = packet->read(currentIndex);

        if(c == '\0')
        {
            break;
        }
        else
        {
            m_string += c;
        }

        currentIndex++;
    }

    return m_string;
}

int PacketStream::readInt32(void)
{
    unsigned int size = 4;
    char bytes[size];

    for(unsigned int i=0; i<size; i++)
    {
        bytes[i] = packet->read(currentIndex);
        currentIndex++;
    }

    int m_int = (bytes[3] << 24) |
            (bytes[2] << 16) |
            (bytes[1] << 8) |
            (bytes[0]);

    return m_int;
}

}

}
