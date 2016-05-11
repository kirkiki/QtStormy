//
// Created by bluedragonfly on 5/2/16.
//
#ifndef WIN32
#include <cstring>
#ifdef WIN32
#include <winsock2.h>
#else
#include <libnet.h>
#endif
#include <iostream>
#include <bitset>
#include "UDPSocket.hpp"

UDPSocket::UDPSocket() : buffer(65530) {
    pipe = {0};
    pipeSize = sizeof pipe;
}

UDPSocket::~UDPSocket() {
    close(sock);
}


void UDPSocket::unbind() {
    close(sock);
}

bool UDPSocket::bindPort(unsigned int port) {
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    fcntl(sock, F_SETFL, O_NONBLOCK); //Non Blocking Socket Sale !
    if(sock == INVALID_SOCKET){
        perror("socket");
        exit(-1);
    }

    pipe.sin_addr.s_addr = htonl(INADDR_ANY);
    pipe.sin_family = AF_INET;
    pipe.sin_port = htons((uint16_t)port);
    if(bind(sock,(sockaddr*)& pipe, sizeof pipe)){
        perror("bind");
        return false;
    }
    return true;
}

size_t UDPSocket::receive(void * data, size_t size, int flags) {//Vector<char> buf
    int n = recvfrom(sock, data, size,flags, (sockaddr*) &pipe, (socklen_t *)  &pipeSize);
    if(n >=0){
        std::cout<<"ReceivedPacket from "<< remoteAddress()<<":"<<remotePort()<<std::endl;
        std::cout<<"Datagram Size : "<<size<<std::endl;
        std::cout<<"Read "<<n<<" size"<<std::endl;
        return n;
    };

   // perror("recvfrom");

    return 0;
}//4 + 4 + 8  + 18 = 10 + 20 + 4 = 34



size_t UDPSocket::receive(Packet &packet, int flags) {

    size_t n = 0;
    n= receive(&buffer[0], buffer.size(), flags);

    packet.clear();

    if(n >=0){
        packet.onReceive(&buffer[0], n);
    }
    return n;
}


bool UDPSocket::send(const void * data, size_t size, std::string ipAddress, unsigned int port, int flags) {
    inet_pton(AF_INET, ipAddress.c_str(), &(pipe.sin_addr));
    pipe.sin_port = htons((uint16_t )port);
    pipe.sin_family = AF_INET;

    if(sendto(sock, data, size ,flags,(sockaddr*) &pipe, (socklen_t) sizeof pipe)>=0){
        return true;
    }
    std::cout<<"PacketSended to "<<ipAddress<<":"<<port<<std::endl;
    std::cout<<"Datagram Size :"<<sizeof(data);
    perror("sendto");
    return false;
}

bool UDPSocket::send(Packet &packet, std::string ipAddress, unsigned int port, int flags) {
    std::size_t size = 0;
    const void* data = packet.onSend(size);

    // Send it
    return send(data, size, ipAddress, port ,flags);
}

std::string UDPSocket::remoteAddress(){

    char cAdd[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(pipe.sin_addr), cAdd, INET_ADDRSTRLEN);

    std::string addrString(cAdd);

    return addrString;
}

unsigned int UDPSocket::remotePort() {

    unsigned int port = ntohs(pipe.sin_port);

    return port;
}
#endif
