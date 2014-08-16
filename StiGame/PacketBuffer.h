#ifndef PACKETBUFFER_H
#define PACKETBUFFER_H

namespace StiGame
{

namespace Net
{

class PacketBuffer
{
    public:
        static const int LENGTH = 512;
        PacketBuffer();
        virtual ~PacketBuffer();

        int getDataLength(void);
        int getLength(void);
        int getCurrentPosition(void);

    protected:
        int maxLength;
        int dataLength;
        int currentPosition;
        char data[LENGTH];
    private:
};

}

}

#endif // PACKET_H
