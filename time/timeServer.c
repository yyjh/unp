#include "../unpv13e/lib/unp.h"
#include <time.h>

int main(int argc, char **argv)
{
	int listenfd, connfd;
	struct sockaddr_in serveraddr;
	char buff[MAXLINE];
	time_t ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0)
	{
		err_quit("socket error");
	}

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(13);
	//serveraddr.sin_port = htons(9999);

	int on;
	setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	Bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr));

	Listen(listenfd, LISTENQ);

	for( ; ; ){
		connfd = Accept(listenfd, (SA *) NULL, NULL);

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		/*size_t n = sizeof(buff);
		size_t i = 0;
		for(; i < n; ++i)
		{
			Write(connfd,buff + i, sizeof(char));
		//	Write(connfd,"A", sizeof(char));
		
		}*/
		Write(connfd, buff, strlen(buff));
		Close(connfd);
	}	
}
