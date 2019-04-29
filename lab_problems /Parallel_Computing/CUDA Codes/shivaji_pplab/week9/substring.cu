#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

__global__ void findSubstr(char* A, char* C, int slen, int sublen){
	int idx = threadIdx.x;
	int flag = 1;
	for(int i=0;i<sublen;i++){
		if(A[idx+i] != C[i]){
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		printf("\nSubstring found\n");
	}
	else
		printf("\nSubstring Not found!\n");
}
int main(){
	char A[N];
	char C[N];
	char *pA,*pC;
	scanf("%s", A);
	scanf("%s", C);
	/*cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start, 0);*/

	int slen = strlen(A);
	int sublen = strlen(C);

	cudaMalloc((void**)&pA, slen*sizeof(char));
	cudaMalloc((void**)&pC, sublen*sizeof(char));
	cudaMemcpy(pA, A, slen*sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(pC, C, sublen*sizeof(char), cudaMemcpyHostToDevice);
	cudaError_t error =cudaGetLastError();
	if (error != cudaSuccess){
		printf("CUDA Error1: %s\n", cudaGetErrorString(error));
	}
	findSubstr<<<1,(slen-sublen+1)>>>(pA,pC, slen, sublen);
	error =cudaGetLastError();

	if (error != cudaSuccess){
		printf("CUDA Error2: %s\n", cudaGetErrorString(error));
	}
	/*cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	float elapsedTime;
	cudaEventElapsedTime(&elapsedTime, start, stop);*/

	//printf("Time Taken=%f",elapsedTime);
	cudaFree(pA);
	cudaFree(pC);
	printf("\n");
	return 0;
}
