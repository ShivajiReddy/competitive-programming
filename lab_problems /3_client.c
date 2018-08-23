#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int len,result,sockfd,n=1;
	struct sockaddr_in address;
	char buf[256];
	int server_id;
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("192.168.2.10");
	address.sin_port = htons(11200);
	len = sizeof(address);
	//printf("before conne\n");
	printf("\ntime client\n");
	result = connect(sockfd,(struct sockaddr *)&address,len);
	//printf("afte conne\n");
	if(result == -1)

	{
		perror("\n CLIENT ERROR\n");
		exit(1);
	}

	//printf("\n Enter string \n");
	//gets(ch);
	//ch[0]='a';
	//ch[1]='\0';
	//char ch = 'c';

	//write(sockfd,&ch,sizeof(ch));
	//read(sockfd,&ch,sizeof(ch));
	//printf("%c\n",ch );
	//printf(" process id of server and Current time according to server is \n");
	printf("\nclient ready to read\n");
	while(n)
	{
		n = read(sockfd, &server_id,sizeof(server_id));
		
	
		n = read(sockfd,buf,sizeof(buf));
		
	}
	//buf[strlen(buf)]='/0';
	printf("\n %d <-- process id\n",server_id );
	printf("\n %s <------- current time\n",buf );

		

	
	
	close(sockfd);
}
