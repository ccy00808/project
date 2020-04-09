#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <vector>
#include <error.h>

std::vector<std::thread> threads;

void JoinableThread()
{
    for (auto iter = threads.begin(); iter != threads.end(); ++iter) {
        if (iter->joinable()) {
            iter->join();
        }
    }
}

void ReciveMsg(int conId)
{
    char buf[128][50] = {0};
    int len = 0;
    int i = 0;
    do {
        len = recv(conId, buf[i], 49, 0);

        if (len < 0) {
            printf("error %d\n", (*__errno_location ()));
            break;
        }
        if (len == 0) {
            printf("close connect!\n");
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
    if ((serverFd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return 0;
    }

    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    if (inet_pton(AF_INET,"192.168.10.133",&(serverAddr.sin_addr.s_addr)) <= 0)
    {
        fprintf(stderr, "inet_pton error!!!\n");
        exit(1);
    }

    serverAddr.sin_port = htons(12569);
    char buf[1024] = {0};

    if (bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        return 0;
    }

    if (listen(serverFd, 100) == -1) {
        return 0;
    }

    return serverFd;
}

int main()
{
    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int serverFd = InitialSocket();

    while (1) {
        int connId = 0;
        if ((connId = accept(serverFd, (struct sockaddr *)&clientAddr, &clientLen)) == -1) {
            continue;
        }
        std::thread th(ReciveMsg, connId);
        threads.push_back(std::move(th));
    }

    JoinableThread();

    close(serverFd);

    return 0;
}