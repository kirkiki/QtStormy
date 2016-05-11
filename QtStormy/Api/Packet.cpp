//
// Created by bluedragonfly on 5/3/16.
//
#include "Packet.hpp"
#include <cstring>
#ifdef WIN32
#include <winsock2.h>
#elif __linux__
#include <netinet/in.h>
#endif
#include <iostream>



Packet::Packet() : readPos(0), isValid(true){

}

Packet::~Packet() {

}

void Packet::append(const void *data, std::size_t sizeInBytes) {
    if (data && (sizeInBytes > 0))
    {
        std::size_t start = this->data.size();
        this->data.resize(start + sizeInBytes); // Resize tab length
        std::memcpy(&this->data[start], data, sizeInBytes); // copy memory data in the arrray
    }
}

void Packet::clear()
{
    data.clear();
    readPos = 0;
    isValid = true;
}

const void* Packet::getData() const
{
    return !data.empty() ? &data[0] : NULL; //Envoi un pointeur sur la premiere case du tableau ou un NULL si le tableau est vide
}

std::size_t Packet::getDataSize() const
{
    return data.size();
}

bool Packet::endOfPacket() const
{
    return readPos >= data.size();
}

const void* Packet::onSend(std::size_t& size)
{
    size = getDataSize();
    return getData();
}

void Packet::onReceive(const void* data, std::size_t size)
{
    append(data, size);
}

bool Packet::checkSize(std::size_t size)
{
    isValid = isValid && (readPos + size <= data.size());
    return isValid;
}

Packet &Packet::operator<<(float data) {
    append(&data, sizeof(data));
    return *this;
}

Packet &Packet::operator<<(double data) {
    append(&data, sizeof(data));
    return *this;
}

Packet &Packet::operator<<(std::uint32_t & data) {
    std::uint32_t toWrite = htonl(data);
    append(&toWrite, sizeof(toWrite));

    return *this;
}

Packet &Packet::operator<<(std::uint64_t & data) {
    // Since htonll is not available everywhere, we have to convert
    // to network byte order (big endian) manually
    uint8_t toWrite[] =
            {
                    static_cast<uint8_t >((data >> 56) & 0xFF),
                    static_cast<uint8_t>((data >> 48) & 0xFF),
                    static_cast<uint8_t>((data >> 40) & 0xFF),
                    static_cast<uint8_t>((data >> 32) & 0xFF),
                    static_cast<uint8_t>((data >> 24) & 0xFF),
                    static_cast<uint8_t>((data >> 16) & 0xFF),
                    static_cast<uint8_t>((data >>  8) & 0xFF),
                    static_cast<uint8_t>((data      ) & 0xFF)
            };
    append(&toWrite, sizeof(toWrite));
    return *this;
}

Packet &Packet::operator<<(std::string & data) {
    // First insert string length
    std::uint32_t length = static_cast<std::uint32_t>(data.size());
    *this << length;
    // Then insert characters
    if (length > 0)
        append(data.c_str(), length * sizeof(std::string::value_type));
    return *this;
}

Packet &Packet::operator>>(std::string &data) {
    // First extract string length
    std::uint32_t length = 0;
    *this >> length;

    data.clear();
    if ((length > 0) && checkSize(length))
    {
        // Then extract characters
        data.assign(&this->data[readPos], length);
        //Test string value
        /*for(int i=0; i < length; i++){
            std::bitset<8> x (this->data[readPos +i]);
            std::cout<<"Binary : "<<x<<" Char : "<<this->data[readPos+i]<<std::endl;
        }*/
        // Update reading position
        readPos += length;
    }

    return *this;
}

Packet &Packet::operator>>(std::uint32_t &data) {
    if (checkSize(sizeof(data)))
    {
        data = ntohl(*reinterpret_cast<const std::uint32_t *>(&this->data[readPos]));
        readPos += sizeof(data);
    }
    return *this;
}

Packet &Packet::operator>>(std::uint64_t &data) {
    if (checkSize(sizeof(data)))
    {
        // Since ntohll is not available everywhere, we have to convert
        // to network byte order (big endian) manually
        const uint8_t * bytes = reinterpret_cast<const uint8_t *>(&this->data[readPos]);
        data = (static_cast<uint64_t >(bytes[0]) << 56) |
               (static_cast<uint64_t>(bytes[1]) << 48) |
               (static_cast<uint64_t>(bytes[2]) << 40) |
               (static_cast<uint64_t>(bytes[3]) << 32) |
               (static_cast<uint64_t>(bytes[4]) << 24) |
               (static_cast<uint64_t>(bytes[5]) << 16) |
               (static_cast<uint64_t>(bytes[6]) <<  8) |
               (static_cast<uint64_t>(bytes[7])      );
        readPos += sizeof(data);
    }

    return *this;
}

Packet &Packet::operator>>(float &data) {
    if (checkSize(sizeof(data)))
    {
        data = *reinterpret_cast<const float*>(&this->data[readPos]);
        readPos += sizeof(data);
    }

    return *this;
}

Packet &Packet::operator>>(double &data) {
    if (checkSize(sizeof(data)))
    {
        data = *reinterpret_cast<const double*>(&this->data[readPos]);
        readPos += sizeof(data);
    }

    return *this;
}
