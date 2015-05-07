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

    void writeInt16(short m_int);
    void writeUInt16(unsigned short m_int);

    void writeBool(bool m_bool);

    void writeInt64(long m_long);
    void writeUInt64(unsigned long m_long);

    std::string readString(void);
    int readInt32(void);
    unsigned int readUInt32(void);

    short readInt16(void);
    unsigned short readUInt16(void);

    long readInt64(void);
    unsigned long readUInt64(void);

    bool readBool(void);
private:
    IPacket *packet;
    int currentIndex;
};

}

}

#endif // PACKETSTREAM_H
