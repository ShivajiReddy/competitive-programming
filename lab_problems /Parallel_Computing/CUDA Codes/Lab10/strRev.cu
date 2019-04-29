#include<stdio.h>

__global__ void search(char *in, char* out){
	int i = threadIdx.x;
	int p = blockDim.x - threadIdx.x -1; 
	out[p] = in[i];
}
int main(){
	char *inp, *out;
	int n = 100;

	cudaMallocManaged(&inp, n*sizeof(char)); 	
	cudaMallocManaged(&out, n*sizeof(char)); 	

	//Taking input from user
	printf("Enter main string:\n");
	scanf("%s", inp);
	//Invoking the kernel
	out[strlen(inp)] = '\0';
	dim3 blockDim(strlen(inp));
	search<<<1,blockDim>>>(inp, out);
	cudaDeviceSynchronize();


	//Printing the result	
	printf("Output string:%s\n", out);
	cudaFree(inp);
	cudaFree(out);
	return 0;
}
