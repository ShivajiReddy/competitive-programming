#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 2

void getNextAlphabet (char * alp) {
	char *next = (char *)calloc(2, sizeof(char));
	next[1] = '\0';
	if (*alp == 'Z')
		next[0] = 'a';
	else if (*alp == 'z')
		next[0] = 'A';
	else
		next[0] = *alp + 1;
	*alp = *next;
}

int main (int argc, const char * argv []) {

	int segment_id = shmget(IPC_PRIVATE, SIZE, S_IRUSR | S_IWUSR);

	char *shared_memory = (char *)shmat(segment_id, NULL, 0);
	
	*shared_memory = '\0';

	pid_t pid;

	int i;

	*shared_memory = 'A';

	for (i = 0; i < 52; ++i) {

		pid = fork();

		if (pid == 0) {

			while (*shared_memory == '\0');

			getNextAlphabet(shared_memory);

			exit(0);

		} else {

			printf("%s -> ", shared_memory);
			
			wait(NULL);

			printf("%s\n", shared_memory);

		}

	}

	shmdt(shared_memory);
}
