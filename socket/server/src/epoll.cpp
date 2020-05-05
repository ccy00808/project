#include "epoll.h"
#include <sys/epoll.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include "util.h"
#include <arpa/inet.h>
#include <poll.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int InitialEpoll(int sockFd)
{
    int epollId = epoll_create(EPOLL_MAXNUM);
    RETURN_IF(-1, epollId < 0);
}