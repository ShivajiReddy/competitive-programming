#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
int sum(int *arr){
	int size = arr[0];
	int sum = 0;
	for(int i = 1; i <= size; i++){
		sum += arr[i];
	}
	return sum;
}
void *thread_code(void *param){
	int res = sum((int *)param);
	return (void *)res;
}
int main(int arg, char **argv){
	int size;
	printf("Enter the size of array\n");
	scanf("%d", &size);
	int *arr = (int *)malloc(sizeof(int)*size);
	int *odd = (int *)calloc(1, sizeof(int));
	odd[0] = 1; 
	int *even = (int *)calloc(1, sizeof(int));
	even[0] = 1; 
	for(int i = 0; i<size; i++){
		scanf("%d", &arr[i]);
		if(arr[i] % 2 == 0){
			even[0]++;
			even = (int *)realloc(even, even[0]*sizeof(int));
			even[even[0]] = arr[i];
		}else{
			odd[0]++;
			odd = (int *)realloc(odd, odd[0]*sizeof(int));
			odd[odd[0]] = arr[i];
		}
	}
	pthread_t odd_thread;
	pthread_t even_thread;
	pthread_create(&odd_thread, 0, &thread_code, (void *)odd);
	pthread_create(&even_thread, 0, &thread_code, (void *)even);
	int odd_sum , even_sum;
	pthread_join(odd_thread, (void **)&odd_sum);
	pthread_join(even_thread, (void **)&even_sum);
	printf("The odd sums are %d\n", odd_sum);
	printf("The even sums are %d\n", even_sum);
	return 0;
}