#include<stdio.h>
#define ind(i, j, n) (i*n +j)
__global__ void add(int *a, int *b, int *c){
	int n = gridDim.x;
	int p = gridDim.y;
	int i = blockIdx.x;
	int j = blockIdx.y;
	c[ind(i, j, p)] = a[ind(i, j, p)]+b[ind(i, j, p)];
}

int main(){
	int *a, *b, *c;
	int n, p;
	printf("Enter N and P\n");
	scanf("%d %d", &n, &p);
	cudaMallocManaged(&a, n*p*sizeof(int)); 	
	cudaMallocManaged(&b, n*p*sizeof(int)); 	
	cudaMallocManaged(&c, n*p*sizeof(int)); 	
	printf("Enter A\n");
	for(int i = 0;i<n;i++){
		for(int j = 0;j<p;j++){
			scanf("%d", &a[ind(i, j, p)]);
		}
	}
	printf("Enter B\n");
	for(int i = 0;i<n;i++){
		for(int j = 0;j<p;j++){
			scanf("%d", &b[ind(i, j, p)]);
		}
	}
	dim3 gridDim(n,p); 
	add<<<gridDim,1 >>>(a, b, c, n, p);
	cudaDeviceSynchronize();
	printf(" Result \n");
	for(int i = 0;i<n;i++){
		for(int j = 0;j<p;j++){
			printf("%d ", c[ind(i, j, p)]);
		}
		printf("\n");
	}
	printf("\n");
	cudaFree(a);
	cudaFree(b);
	cudaFree(c);
	return 0;
}
