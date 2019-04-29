#include<stdio.h>
#define ind(i, j, n) (i*n +j)
__global__ void add(int *a, int *b, int *c, int n, int p, int q){
	int i = blockIdx.x;
	int j = blockIdx.y;
	int k = 0;
	c[ind(i, j, q)] = 0;
	for(k=0;k<p;k++){
		c[ind(i,j,q)] += a[ind(i,k,p)] * b[ind(k,j,q)];	
	}
}

int main(){
	int *a, *b, *c;
	int n, p, q;
	printf("Enter N, P and Q\n");
	scanf("%d %d %d", &n, &p, &q);
	cudaMallocManaged(&a, n*p*sizeof(int)); 	
	cudaMallocManaged(&b, p*q*sizeof(int)); 	
	cudaMallocManaged(&c, n*q*sizeof(int)); 	
	printf("Enter A\n");
	for(int i = 0;i<n;i++){
		for(int j = 0;j<p;j++){
			scanf("%d", &a[ind(i, j, p)]);
		}
	}
	printf("Enter B\n");
	for(int i = 0;i<p;i++){
		for(int j = 0;j<q;j++){
			scanf("%d", &b[ind(i, j, q)]);
		}
	}
	dim3 gridDim(n,q);
	add<<<gridDim,1>>>(a, b, c, n, p, q);
	cudaDeviceSynchronize();
	printf(" Result \n");
	for(int i = 0;i<n;i++){
		for(int j = 0;j<q;j++){
			printf("%d ", c[ind(i, j, q)]);
		}
		printf("\n");
	}
	printf("\n");
	cudaFree(a);
	cudaFree(b);
	cudaFree(c);
	return 0;
}
