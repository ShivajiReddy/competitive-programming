#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <stdlib.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<time.h>
#include<termios.h>
#define PORTNO 11200

int main()
{
	int s_sockfd,c_sockfd;
	int s_len,c_len;
	struct sockaddr_in s_addr;
	struct sockaddr_in c_addr;
	int result;
	fd_set readfds,testfds,writefds;
	s_sockfd = socket(AF_INET,SOCK_STREAM,0);
	s_addr.sin_family=AF_INET;
	s_addr.sin_addr.s_addr=inet_addr("192.168.2.10");
	s_addr.sin_port=htons(PORTNO);
	s_len=sizeof(s_addr);
	bind(s_sockfd,(struct sockaddr *)&s_addr,s_len);
	listen(s_sockfd,50);
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_SET(s_sockfd,&readfds);
	int n=1;
	time_t t;
	int s_id;
	printf("p id is %d \n",getpid());
	while(1)
	{
		char buf[256];
		int fd,nread;
		testfds=readfds;
		printf("\nserver waiting...\n");
		result=select(FD_SETSIZE,&testfds,&writefds,(fd_set *)0,(struct timeval *)0);
		if(result<1)
		{
			perror("\nserver error\n");
			exit(1);

		}
		for(fd=0;fd<FD_SETSIZE;fd++)
		{
			if(FD_ISSET(fd,&testfds))
			{
				if(fd==s_sockfd)
				{
					c_len=sizeof(c_addr);
					c_sockfd=accept(s_sockfd,(struct sockaddr *)&c_addr,&c_len);
					FD_SET(c_sockfd,&writefds);
					printf("\naccept client on %d\n",c_sockfd);

				}
				else
				{
					
				}
			}
			if(FD_ISSET(fd,&writefds))
			{
				t = time(NULL);
				ioctl(fd,TIOCOUTQ,&nread);
				printf("\nnread is %d\n",nread );
				/*
				if(nread==0)
				{
					//close(fd);
					FD_CLR(fd,&writefds);
					printf("removing client on fd %d\n",fd );
				}
				else
				{*/
				
				
				asctime_r(localtime(&t),buf);
				s_id=getpid();
				n=write(fd,&s_id,sizeof(s_id));
				n=write(fd,buf,sizeof(buf));
				close(fd);
				FD_CLR(fd,&writefds);
				printf("\nremoving client on fd %d \n",fd);
				
				
			}
		}
		
	}

	
	return 0;
}
