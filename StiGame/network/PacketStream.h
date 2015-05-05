#ifndef PACKETSTREAM_H
#define PACKETSTREAM_H
#include "IPacket.h"
#include <string>

namespace StiGame {

namespace Net
{

class PacketStream
{
public:
    PacketStream(IPacket *m_packet);
    virtual ~PacketStream();

    IPacket* getPacket(void);

    void writeString(std::string m_string);
    void writeInt32(int m_int);
    void writeUInt32(unsigned int m_int);

    std::string readString(void);
    int readInt32(void);
    unsigned int readUInt32(void);
private:
    IPacket *packet;
    int currentIndex;
};

}

}

#endif // PACKETSTREAM_H
