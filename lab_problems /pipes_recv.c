#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct my_message
{
	long int msg_type;
	char text[10];
};

int main(int argc, char const *argv[])
{
	struct my_message data;
	int msgid;

	if(msgid = msgget(1234, 0666 | IPC_CREAT))
	{
		fprintf(stderr, "msgget failed with error\n");
		exit(1);
	}

	if(msgrcv(msgid, &data, 10, 0, 0) == -1)
	{
		fprintf(stderr, "msgsnd failed");
	}

	printf("Data received:\n%s", data.text);


	return 0;
}