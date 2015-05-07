#include "UdpPacket.h"
#include <iostream>
#include "UdpSocket.h"
namespace StiGame
{

namespace Net
{

UdpPacket::UdpPacket()
{
    size = UdpSocket::DEFAULT_PACKET_SIZE;
    _packet = SDLNet_AllocPacket(size);
    _packet->maxlen = size;
}

UdpPacket::UdpPacket(UDPpacket *m_packet)
{
    _packet = m_packet;
    size = m_packet->len;
}

UdpPacket::UdpPacket(int m_size)
{
    size = m_size;
    _packet = SDLNet_AllocPacket(size);
    _packet->maxlen = size;
}

UdpPacket::~UdpPacket()
{
    SDLNet_FreePacket(_packet);
}

int UdpPacket::len(void)
{
    return _packet->len;
}

Uint8* UdpPacket::data(void)
{
    return _packet->data;
}

int UdpPacket::channel(void)
{
    return _packet->len;
}

IPaddress* UdpPacket::ipAddress(void)
{
    return &(_packet->address);
}

int UdpPacket::maxlen(void)
{
    return _packet->maxlen;
}

int UdpPacket::status(void)
{
    return _packet->status;
}

void UdpPacket::write(char byte, int index)
{
    if(index < maxlen())
    {
        _packet->data[index] = static_cast<Uint8>(byte);
    }
    else
    {
        std::cout << "[ERROR] Packet index out of range [write(byte,index)]" << std::endl;
    }
}

void UdpPacket::write(char *bytes, int index, int length)
{
    if(index + length < maxlen())
    {
        for(int i=0; i<length; i++)
        {
            _packet->data[i+index] = static_cast<Uint8>(bytes[i]);
        }
    }
    else
    {
        std::cout << "[ERROR] Packet index out of range (write(bytes,index,length))" << std::endl;
    }
}

char UdpPacket::read(int index)
{
    if(index < len())
    {
        return static_cast<char>(_packet->data[index]);
    }
    else
    {
        std::cout << "[ERROR] Packet index out of range [read(index)]" << std::endl;
        return '\0';
    }
}

char* UdpPacket::read(int index, int length)
{

    if(index + length < len())
    {
        char *bytes = new char[length];

        for(int i=0; i<length; i++)
        {
            bytes[i] = static_cast<char>(_packet->data[i+index]);
        }

        return bytes;
    }
    else
    {
        std::cout << "[ERROR] Packet index out of range [read(index,length)]" << std::endl;
        return nullptr;
    }
}

UDPpacket* UdpPacket::packet(void)
{
    return _packet;
}

void UdpPacket::resize(int m_size)
{
    size = m_size;
    int rs = SDLNet_ResizePacket(_packet, m_size);

    if(rs < m_size)
    {
        std::cout << "[ERROR] resizing packet to " << m_size << " fail : " << SDL_GetError() << std::endl;
    }
}

int UdpPacket::getSize(void)
{
    return size;
}


void UdpPacket::setString(std::string message)
{
    //set the entire data as a string
    int len = message.length() + 1;
    for(int i=0; i<message.length(); i++)
    {
        _packet->data[i] = static_cast<Uint8>(message[i]);
    }

    _packet->data[message.length()] = '\0';
    _packet->len = len;
}

std::string UdpPacket::getString(void)
{
    return std::string((char*)_packet->data);
}

void UdpPacket::setLen(int m_len)
{
    _packet->len = m_len;
}

void UdpPacket::copyAddress(IPaddress *dst)
{
    dst->host = _packet->address.host;
    dst->port = _packet->address.port;
}

void UdpPacket::applyAddress(IPaddress *address)
{
    _packet->address.host = address->host;
    _packet->address.port = address->port;
}

PacketType UdpPacket::type(void)
{
    return PT_Udp;
}

}

}
