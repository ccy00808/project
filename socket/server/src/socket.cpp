#include "socket.h"
#include "util.h"
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

#define SERVER_IP  "192.168.10.133"
#define SERVER_PORT 12569

void ReciveMsg(int conId)
{
    char buf[128][50] = {0};
    int len = 0;
    int i = 0;
    do {
        len = recv(conId, buf[i], 49, 0);
        RETURN_IF(-1, len < 0);

        if (len == 0) {
            close(conId);
            break;
        }
        
        buf[i][len] = '\0';
        printf("%d %d str = %s\n", i, len, buf[i]);
        ++i;
    } while (len > 0);    
    
    close(conId);
}

int InitialSocket()
{
    int serverFd, connId;
    struct sockaddr_in serverAddr;
    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    RETURN_IF(-1, serverFd < 0);

    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    RETURN_IF(-1, (inet_pton(AF_INET, SERVER_IP, &(serverAddr.sin_addr.s_addr)) <= 0));

    serverAddr.sin_port = htons(SERVER_PORT);
    char buf[1024] = {0};

    RETURN_IF(-1, (bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1));
    RETURN_IF(-1, (listen(serverFd, 100) == -1));

    return serverFd;
}