#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#define SERVICE_IP "192.168.223.135"
#define SERVICE_PORT 2348

int main()
{
    struct sockaddr_in serviceAddr;
    int socketFd;
    int ret;

    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        std::cout << socketFd << "error: " << errno << std::endl;
        return -1;
    }

    serviceAddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, SERVICE_IP, &(serviceAddr.sin_addr.s_addr));
    if (ret < 0) {
        std::cout << "inet pton trans fail\n";
        return -1;
    }

    serviceAddr.sin_port = htons(SERVICE_PORT);

    ret = bind(socketFd, (struct sockaddr*)&serviceAddr, sizeof(serviceAddr));
    if (ret < 0) {
        std::cout << "bind fail\n";
        return -1;
    }

    ret = listen(socketFd, 1000);
    if (ret < 0) {
        std::cout << "listen fail\n";
        return -1;
    }

    int i = 0;
    while(1) {
        sleep(5);
        std::cout << "sleep time " << ((++i) * 5) << std::endl;
        if (i >= 1000) {
            break;
        }
    }
    return 0;
}