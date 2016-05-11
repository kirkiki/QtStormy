//
// Created by bluedragonfly on 5/2/16.
//

#ifndef IOTOBSERVER_UDPSOCKET_HPP
#define IOTOBSERVER_UDPSOCKET_HPP

#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#endif
#include <string>
#include <cstdlib>
#ifdef WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif
#include <cstdio>
#include "Packet.hpp"

typedef int SOCKET;
const int INVALID_SOCKET =  -1;
const int SOCKET_ERROR =  -1;
struct sockaddr_in;
struct sockaddr;
struct in_addr;

class UDPSocket{
public:
    UDPSocket();
    ~UDPSocket();


    void unbind();

    bool bindPort(unsigned int port);

    size_t receive(void * data, size_t size, int flags =0);

    size_t receive(Packet & packet, int flags=0);

    bool send(const void * data, size_t size, std::string ipAddress, unsigned int port, int flags = 0);

    bool send(Packet & packet, std::string ipAddress, unsigned int port, int flags=0);

    std::string remoteAddress();
    unsigned  int remotePort();

private:

    SOCKET sock;
    sockaddr_in pipe;

    std::vector<char> buffer;
    int pipeSize;
};

#endif //IOTOBSERVER_UDPSOCKET_HPP
