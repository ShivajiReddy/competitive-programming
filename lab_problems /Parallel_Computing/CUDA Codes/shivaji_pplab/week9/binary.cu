#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

__global__ void binVal(char* A){

	int idx = threadIdx.x;
	int count = 0;
	int val = A[idx];
	int bin = 0;
	while(val>0){
		int rem = val%2;
		int c = count;
		while(c>0){
			rem *= 10;
			c--;
		}
		bin += rem;
		count++;
		val /= 2;
	}

	printf("%c - %d\n", A[idx], bin);
}

int main(){
	char A[N];
	char *pA;

	scanf("%s", A);
	int len = strlen(A);

	cudaMalloc((void**)&pA, len*sizeof(char));
	cudaMemcpy(pA, A, len*sizeof(char), cudaMemcpyHostToDevice);
	cudaError_t error =cudaGetLastError();
	if (error != cudaSuccess){
		printf("CUDA Error1: %s\n", cudaGetErrorString(error));
	}
	binVal<<<1,len>>>(pA);
	error =cudaGetLastError();

	if (error != cudaSuccess){
		printf("CUDA Error2: %s\n", cudaGetErrorString(error));
	}
	cudaFree(pA);
	printf("\n");
	return 0;
}
