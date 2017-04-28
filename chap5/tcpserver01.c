#include <unp.h>

int main(int argc, char ** argv){
	int listenfd, connfd;
	struct sockaddr_in cliaddr, servaddr;
	socklen_t clilen;
	pid_t child_pid;
	char str[INET_ADDRSTRLEN];

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);
	
	while(1){
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
		if((child_pid = Fork()) == 0){
			Close(listenfd);
			printf("Receive Connection, ip: %s, port: %d\n",
				Inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
				ntohs(cliaddr.sin_port)	
			);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
}
