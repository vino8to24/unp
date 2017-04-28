#include <unp.h>
#include <ctype.h>
void str_echo(int sockfd){
	ssize_t n;
	char buf[MAXLINE];
	size_t i;
again:
	while((n = read(sockfd, buf, MAXLINE)) > 0){
		for(i=0; i<n; ++i){
			buf[i] = tolower(buf[i]);
		}
		Writen(sockfd, buf, n);
	}
	if(n < 0 && errno == EINTR)
		goto again;
	else if(n < 0)
		err_sys("str_echo: read error");
}
