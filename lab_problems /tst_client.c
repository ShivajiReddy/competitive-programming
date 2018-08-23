#include <stdio.h> 
#include <sys/sockets.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
	int sockfd, result, n = 1, len;
	char ch[256], buf[256];
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10200);
	addr.sin_addr.s_addr = inet_addr("172.");
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
	if(result == -1) exit(1);

	printf("ENTER STRING");
	gets(ch);
	ch[strlen(ch)]='\0';
	write(sockfd, ch, strlen(ch));
	while(n)
	{
		n = read(sockfd, buf, sizeof(buf));
		puts(buf);
	}
}
