#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "TCPSocket.h"
#define PORT 23333

/*
 *
 */
int main(int argc, char** argv)
{
    int server = createTCPSocket();
    struct sockaddr_in serverAddress ;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(PORT);
    //specify the quene length
    if (connect(server, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        fprintf(stderr, "Unable to connect to server\n" );
        exit(2);
    }
    char input[1024];
    while(scanf("%s", input) && strcmp(input, "exit")!=0)
        write(server, input, strlen(input)+1);
    close(server);
    exit(0);
    return (EXIT_SUCCESS);
}
