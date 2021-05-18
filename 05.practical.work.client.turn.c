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
}
