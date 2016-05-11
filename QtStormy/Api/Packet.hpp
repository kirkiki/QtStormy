//
// Created by bluedragonfly on 5/3/16.
//

#ifndef IOTOBSERVER_PACKET_HPP
#define IOTOBSERVER_PACKET_HPP

#include <vector>
#include <string>

class Packet {
public:

    ///default ctor
    Packet();
    ///dtor
    ~Packet();
    ///called when the packet is sended through an Udp datagramm
    const void * onSend(size_t &size);
    ///called when and udp datagram is received and need to be store in the packet
    void onReceive(const void *data, size_t size);
    ///Clear the packet
    void clear();
    ///get size of the packet
    size_t getDataSize() const;
    ///Determines end of packet
    bool endOfPacket() const;
    ///Packet In operators
    Packet &operator <<(float data);
    Packet &operator <<(double data);
    Packet &operator <<(std::uint32_t & data);
    Packet &operator <<(std::uint64_t & data);
    Packet &operator <<(std::string & data);
    ///Packet Out operators
    Packet &operator >>(std::string & data);
    Packet &operator >>(std::uint32_t & data);
    Packet &operator >>(std::uint64_t & data);
    Packet &operator >>(float & data);
    Packet &operator >>(double & data);

    const void *getData() const;

private:

    bool checkSize(std::size_t size);
    void append(const void * data, std::size_t sizeInByte);

    std::size_t readPos;
    bool isValid;
    std::vector<char> data; //byte Array char =1byte
};


#endif //IOTOBSERVER_PACKET_HPP
