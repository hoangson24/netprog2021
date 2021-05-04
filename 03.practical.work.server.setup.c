#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define PORT 8784;

int main (int argc, char **argv)
{
    int sockfd, clen, clientfd;
    struct sockaddr_in saddr, caddr;
    short port = 8784;

    if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        printf ("Error creating socket\n");
        return -1;
    }
    else
    {
        printf("Socket created successful\n");
    }
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(port);

    if ((bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0)) 
    {
        printf("Error binding\n");
        return -1;
    }
    else
    {
        printf("Binded successful\n");
    }

        printf("Loading on port...%d \n", port);

    if (listen(sockfd, 5) < 0) 
    {
        printf("Error listening\n");
        return -1;
    }
    else
    {
        printf("Listened succcessful\n");
    }

    clen=sizeof(caddr);

    if ((clientfd=accept(sockfd, (struct sockaddr *) &caddr, &clen)) < 0) 
    {
        printf("Error accepting connection\n");
        return -1;
    }
    else
    {
        printf("Connected successful\n");
        return 0;
    }
}

