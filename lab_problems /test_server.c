#include <sys/type.h>
#include <sys/socket.h>
#include <stdio.h>
#include <net/in.h>
#include <arpa.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int sockfd, newsockfd, portno, n = 1;
	int i, value;
	struckt sockaddr_in seraddr, cliaddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(10200) ;
	seraddr.sin_addr.s_addr = inet_addr("172.24.");

	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr);
	listen(sockfd, 5);
	
	while(1){
		char buf[256];
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, sizeof(clilen));
		n = read(newsockfd, buf, sizeof(buf));
		n = write(newsockfd, buf, sizeof(buf))
	}
	
}
