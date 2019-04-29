#include<stdio.h>

__global__ void toBin(char *in, int* out){
	int id = threadIdx.x;
	int binaryNum[1000]; 
	int n = in[id];
	int i = 0; 
	while (n > 0) { 
		// storing remainder in binary array 
		binaryNum[i] = n % 2; 
		n = n / 2; 
		i++; 
	} 
        // printing binary array in reverse order 
	int mult = 1;
	for(int j = i-1; j>0;j--){
		mult *= 10;
	}
	int output = 0;
	for (int j = i - 1; j >= 0; j--){
		output+= mult*binaryNum[j];
		mult/=10;
	}
	out[id] = output;
}

int main(){
	char *inp;
	int *out;
	int n = 100;

	cudaMallocManaged(&inp, n*sizeof(char)); 	

	//Taking input from user
	printf("Enter string:\n");
	scanf("%s", inp);
	cudaMallocManaged(&out, strlen(inp)*sizeof(int)); 	
	//Invoking the kernel
	dim3 blockDim(strlen(inp));
	toBin<<<1,blockDim>>>(inp, out);
	cudaDeviceSynchronize();
	printf("%d\n", out[0]);
	//Printing the result	
	for(int i=0;i<strlen(inp);i++){
		printf("Char:%c(%d) --> %d\n", inp[i],inp[i],out[i]);
	}
	printf("\n");
	cudaFree(inp);
	cudaFree(out);
	return 0;
}
