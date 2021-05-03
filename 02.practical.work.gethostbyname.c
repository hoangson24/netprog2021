#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    struct hostent *host;
	char str[50];

    if (argc < 2) {
    	printf("Domain name: ");
    	scanf("%s", str);
    	host = gethostbyname(str);
    	printf("IP :\n");

	}
    struct in_addr_list *address;
    
    int i=0;
    while (host->h_addr_list[i] != NULL) {
		printf( "%s\n", inet_ntoa( *(struct in_addr*)(host->h_addr_list[i])));
		i++;
	}
	printf("\n");
	
	}

