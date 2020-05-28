#include "../unpv13e/lib/unp.h"

int main(int argc, char **argv)
{
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;

	if(argc != 2)
		err_sys("usage: a.out <IPaddress>");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_quit("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);	/*daytime server */
	serveraddr.sin_port = htons(9999);
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0)
		err_quit("inet_pton error for %s", argv[1]);

	int on;
        setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	if(connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect_error");

	int count=0;
	while(( n = read(sockfd, recvline, MAXLINE)) > 0){
		++count;
		recvline[n] = 0;
		if(fputs(recvline, stdout) == EOF)
		err_sys("fputs error");
		
}
	/*char buff[64];
	snprintf(buff, sizeof(buff), "%d\r\n", count);
	fputs(buff, stdout);*/
	if( n < 0)
	err_sys("fputs error");

	exit(0);
}
