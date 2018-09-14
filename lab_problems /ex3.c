#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
bool isprime(int a){
	for(int i = 2; i<=a/2; i++){
		if(a % i == 0){
			return false;
		}
	}
	return true;
}
int *primenum(int *points){
	int *ans = (int *)calloc(1, sizeof(int));
	ans[0] = 1;
	for(int i = points[0]; i<points[1]; i++){
		if(isprime(i)){
			ans[0]++;
			ans = (int *)realloc(ans, ans[0]*sizeof(int));
			ans[ans[0]-1] = i;
		}
	}
	return ans;
}
void *thread_code(void *param){
	int *res = primenum((int *)param);
	return (void *)res;
}
int main(){
	int points[2];
	printf("Enter the starting number\n");
	scanf("%d", &points[0]);
	printf("Enter the ending number\n");
	scanf("%d", &points[1]);
	pthread_t thread;
	int *res;
	pthread_create(&thread, 0, &thread_code, (void *)points);
	pthread_join(thread, (void *)&res);
	for(int i = 1; i<res[0]; i++){
		printf("%d\n", res[i]);
	}
	return 0;
}