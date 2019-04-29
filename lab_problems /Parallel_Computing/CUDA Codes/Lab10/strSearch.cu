#include<stdio.h>

__global__ void search(char *in, char* subs, int* found, int substrLen){
	int i = threadIdx.x;
	int start = i;
	for(int j = 0;j<substrLen;j++){
		if(in[start+j] != subs[j]){
			return;
		}
	}	
	found[0] = start;
}
int main(){
	char *inp, *substr;
	int *found;
	int n = 100;

	cudaMallocManaged(&found, 1*sizeof(int)); 	
	cudaMallocManaged(&inp, n*sizeof(char)); 	
	cudaMallocManaged(&substr, n*sizeof(char)); 	

	//Taking input from user
	printf("Enter main string:\n");
	scanf("%s", inp);
	printf("Enter substring\n");
	scanf("%s", substr);
	found[0] = -1;

	//Invoking the kernel
	dim3 blockDim(strlen(inp) - strlen(substr) + 1);
	search<<<1,blockDim>>>(inp, substr, found, strlen(substr));
	cudaDeviceSynchronize();

	//Printing the result	
	printf("Substring found at %d\n", found[0]);
	printf("\n");
	cudaFree(found);
	cudaFree(inp);
	cudaFree(substr);
	return 0;
}
