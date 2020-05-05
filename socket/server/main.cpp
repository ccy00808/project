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
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/wait.h>
#include "util.h"
#include "socket.h"

std::vector<std::thread> threads;

void JoinableThread()
{
    for (auto iter = threads.begin(); iter != threads.end(); ++iter) {
        if (iter->joinable()) {
            iter->join();
        }
    }
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