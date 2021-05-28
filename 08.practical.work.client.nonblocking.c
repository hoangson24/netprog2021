#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define PORT 8784;

int main (int argc, char **argv)

{
    struct hostent *host;
    char str[50];
	    
    int connect(int sockfd,const struct sockaddr *saddr,socklen_t addrlen);
    struct sockaddr_in saddr;
    struct hostent *h;
    int sockfd;
    unsigned short port = 8784;
    
    if ((sockfd=socket(AF_INET, SOCK_STREAM,0)) <0) 
    { 
    printf("Error creating socket\n");
    return -1;
    }
    else
    {
    printf("Socket created successful\n");
    }
    
    if ((h=gethostbyname("google.com\n")) == NULL)
    {
    printf("Unknown host\n");
    return -1;
    }
    else
    {
    struct h_addr_list *address;
    
    int i=0;
    while (host->h_addr_list[i] != NULL);
    {
    printf( "%s\n", inet_ntoa( *(struct in_addr*)(host->h_addr_list[i])));
	i++;
    printf("\n");
    }
    }
    
    memset(&saddr, 0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    memcpy((char*) &saddr.sin_addr.s_addr, host->h_addr_list[0], h->h_length);
    saddr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr *) &saddr,sizeof(saddr)) <0)
    {
    printf("cannot connect\n");
    return -1;
    }
    else
    {
    printf("Connected successful\n");
    }
    int fl = fcntl(sockfd, F_GETFL, 0);
    fl |= SOCK_NONBLOCK;
    fcntl(sockfd, F_SETFL, fl);
    printf("Server connected successful\n");
    
    while (1) 
    {
    char chat[2021];
    memset(chat, 0, 2021);
    if (read(sockfd, chat, 2021) > 0) 
    {
    printf("Server : %s\n", chat);
    }
    struct pollfd input[2021] = {{.fd = 0, .events = POLLIN}};
    if (poll(input, 1, 100) > 0) 
    {
    fgets(chat, 2021, stdin);
    chat[strlen(chat) - 1] = 0;
    write(sockfd, chat, strlen(chat));
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
    return -1;
    }

int shutdown(int sockfd, int how);
    char chat[2021];
    if (strncmp("Disconnect", chat, 2021) == 0);
	{
	printf("Client stopped\n");
	shutdown(sockfd, 2021);
	exit(0);
	}
	return 0;
	
	if (strncmp("Close", chat, 2021) == 0);
	{
	printf("Client closed\n");	
	close(sockfd);
	exit(0);
	}
	return 0;
}
}