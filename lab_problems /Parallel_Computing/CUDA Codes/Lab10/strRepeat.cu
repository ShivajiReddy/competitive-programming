#include<stdio.h>
#include <string.h>
__global__ void search(char *inp, char* word, int* lengths, int *occ){
	int i = threadIdx.x;
	int len = lengths[i];
	int start = 0;
	for(int j = 0;j<i;j++){
		start+= lengths[j]; 
		start++;
	}
	printf("Thread %d start: %d\n", i, start);
	for(int j = 0;j<len;j++){
		if(inp[start+j] != word[j]){
			return;
		}
	}	
	printf("Found\n");
	atomicAdd(occ, 1);
}
int main(){
	char *inp, *substr;
	int *lengths;
	int *occ;
	int n = 100;
	int w = 50;
	cudaMallocManaged(&lengths, w*sizeof(int)); 	
	cudaMallocManaged(&occ, 1*sizeof(int)); 	
	cudaMallocManaged(&inp, n*sizeof(char)); 	
	cudaMallocManaged(&substr, n*sizeof(char)); 	

	//Taking input from user
	printf("Enter main string:\n");
	gets( inp);
	printf("Enter substring\n");
	scanf("%s", substr);
	
	char *p = strtok(inp, " ");
	char *words[w];
	occ[0] = 0;
	int i = 0;
	while (p != NULL){
		words[i] = p;
		lengths[i] = strlen(p);
		printf("Length %d is %d \n",i,  lengths[i]);
		i++;
		p = strtok(NULL, " ");
    	}
	//Invoking the kernel
	dim3 blockDim(i);
	search<<<1,blockDim>>>(inp, substr, lengths, occ);
	cudaDeviceSynchronize();

	//Printing the result	
	printf("Occurences found:%d\n", occ[0]);
	cudaFree(lengths);
	cudaFree(inp);
	cudaFree(substr);
	cudaFree(occ);
	return 0;
}
