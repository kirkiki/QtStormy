//
// Created by bluedragonfly on 5/2/16.
//

#ifndef IOTOBSERVER_UDPSOCKET_HPP
#define IOTOBSERVER_UDPSOCKET_HPP


#include <string>
#include <cstdlib>
#include <cstdio>

#include "Packet.hpp"

#ifdef WIN32 /* si vous êtes sous Windows */

#include <winsock2.h>

#elif __linux__ /* si vous êtes sous Linux */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

const int INVALID_SOCKET =  -1;
const int SOCKET_ERROR  = -1;
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else /* sinon vous êtes sur une plateforme non supportée */

#error not defined for this platform

#endif

class UDPSocket{
public:

    //static bool isInit = false;
    static void init();
    static void end();

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
    SOCKADDR_IN pipe;

    std::vector<char> buffer;
    int pipeSize;
};

#endif //IOTOBSERVER_UDPSOCKET_HPP
