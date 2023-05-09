#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_client
{
	int id;
	char msg[1024];
}				t_client;

t_client		clients[1024];
fd_set			writeFds, readFds, active;
int 			fdMax = 0; idNext = 0;
char			bufferWrite[1024], bufferRead[1024];

void	ft_error(char *str)
{
	if (str)
		write(2, str, strlen(str));
	else
		write(2, "Fatal error", strlen("Fatal error"));
	write(2, "\n", 1);
	exit(1);
}

void	send_all(int fd)
{
	for (int i = 0; i <= fdMax; i++)
		if (FD_ISSET(i, &writeFds) && i != fd)
			send(i, bufferWrite, strlen(bufferWrite), 0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("error");
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		ft_error(NULL);
	
	FD_ZERO(&active);
	bzero(&clients, sizeof(clients));
	fdMax = sockfd;
	FD_SET(sockfd, &active);

	struct sockaddr_in		serveraddr;
	socklen_t				len;
	bzero(&serveraddr, sizeof(serveraddr));
	
}