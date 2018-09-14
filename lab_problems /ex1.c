#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
int fibonacci(int n){
	if(n < 2){
		return 1;
	}else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}
void *thread_code(void *param){
	int res = fibonacci((int)param);
	return (void *)res;
}
int main(int arg, char **argv){
	int num;
	// printf("Enter the number of fibonacci numbers needed\n");
	// scanf("%d", &num);
	num = atoi(argv[1]);
	pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * num);
	for(int i = 0; i<num; i++){
		pthread_create(&threads[i], 0, &thread_code, (void *)i);
	}
	int res;
	for(int i = 0; i<num; i++){
		pthread_join(threads[i], (void *)&res);
		printf("%d\n", res);
	}
	return 0;
}