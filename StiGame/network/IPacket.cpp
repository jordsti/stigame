#include "IPacket.h"
#include "PacketStream.h"
namespace StiGame
{

namespace Net
{

IPacket::IPacket()
{

}

IPacket::~IPacket()
{

}

PacketStream IPacket::stream(void)
{
    PacketStream stream(this);
    return stream;
}

}
}
