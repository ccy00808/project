#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>

#define SERVER_IP  "192.168.223.134"
#define SERVER_PORT 3498

#define RETURN_IF(result, returnVal)  \
if(returnVal) {                       \
    perror("error:");                 \
    exit(result);                     \
}

int main()
{
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        std::cout << "error exit\n";
        return -1;
    }

    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(SERVER_PORT);
    char buf[1024] = {0};

    RETURN_IF(-1, (bind(fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1));
    RETURN_IF(-1, (listen(fd, 100) == -1));

    unsigned int i = 0;

    while (1) {
        sleep(5);
        std::cout << ((++i)*5) << std::endl;
        if (i > 1000) break;
    }
    close(fd);
    return 0;
}