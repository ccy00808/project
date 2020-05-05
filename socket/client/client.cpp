#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <error.h>
#include <unistd.h>
int main()
{
    int communacation_socket,ret;
    struct sockaddr_in saddr;
    communacation_socket = socket(AF_INET,SOCK_STREAM,0);
    if(communacation_socket < 0)
    {
        perror("socket create error:");
        return -1;
    }

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(12569);
    inet_pton(AF_INET,"192.168.10.133",&(saddr.sin_addr.s_addr));



    ret = connect(communacation_socket,(struct sockaddr*)(&saddr),sizeof(saddr));
    if(ret < 0)
    {
        perror("connect error:");
        close(communacation_socket);
        return -1;
    }
    printf("connect success!\n");

    char str[1024] = {0};
    for (int i = 0; i < 100; ++i) {
        sprintf(str, "hello world %d!\n", i);
        ret = send(communacation_socket,str,strlen(str), 0);
        if(ret < 0)
        {  
            perror("wtite error:");
            close(communacation_socket);
            return -1;
        }
        sleep(1);
    }
    printf("close socket\n");
    close(communacation_socket);
    return 0;
}
