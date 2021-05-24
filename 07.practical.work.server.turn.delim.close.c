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
    while (1) 
    {
    char chat[2021];
    memset(chat, 0, 2021);
    fgets(chat, 2021, stdin);
    printf("Client: %s\n", chat);
    write(sockfd, chat, strlen(chat));

    read(sockfd, chat, 2021);
    printf("Server : %s\n", chat);
    }
    while (1)
    {
    char chat[2021];
    char* s;

    printf("message=[%s]\n", chat);

    s = str_split(chat, ',');

    if (s)
    {
    int i;
    for (i = 0; *(s + i); i++)
    printf("Client message=[%s]\n", *(s + i));
    printf("\n");
    }

    return 0;
    }
    
int shutdown(int sockfd, int how);
    char chat[2021];
    if (strncmp("Disconnect", chat, 2021) == 0);
	{
	printf("Server stopped\n");
	shutdown(sockfd, 2021);
	exit(0);
	}
	return 0;
	
	if (strncmp("Close", chat, 2021) == 0);
	{
	printf("Server closed\n");	
	close(sockfd);
	exit(0);
	}
	return 0;
}
