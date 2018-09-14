#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
int calcsum(int *a){
	int size = a[0];
	int sum = 0;
	for(int i = 1; i<= size; i++){
		sum += a[i];
	}
	return sum;
}
void *thread_code(void *param){
	int res = calcsum((int*)param);
	return (void *)res;
}
int main(){
	printf("Enter the number of elements\n");
	int size;
	scanf("%d", &size);
	int *a = (int *)malloc(sizeof(int) * size );
	for(int i = 1; i<=size; i++){
		scanf("%d", &a[i]);
	}
	a[0] = size;
	pthread_t thread;
	int res;
	pthread_create(&thread, 0, &thread_code, (void *)a);
	pthread_join(thread, (void *)&res);
	printf("The sum is %d\n", res);
	return 0;
}