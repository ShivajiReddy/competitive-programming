#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WA  3
#define HA  3
#define WB  3
#define HB  3
#define WC  3
#define HC  3


__global__ void MatMult_one( int* A,  int* B, int* C)
{
		   int id=threadIdx.x;
		   int sum=0;

		   for(int w=0;w<WB;w++)
		   {
			   for(int z=0;z<HB;z++)

			   {
					sum += A[id*WA+z]*B[z*WB+w];
			   }
			   C[id*WA+w]=sum;

		   }
}

__global__ void MatMult_two( int* A,  int* B, int* C)
{

		   int id=threadIdx.x;
		   int sum=0;

		   for(int w=0;w<HA;w++)
		   {
			   for(int z=0;z<WA;z++)

			   {
					sum+=A[id*WA+z]*B[z*WB+w];
			   }
			   C[id*WA+w]=sum;

		   }


}

__device__ int getGlobalIdx_2D_1D(){
int blockIdYd = blockIdx.x * gridDim.y + blockIdx.y;
int threadIdYd = blockIdYd * blockDim.y + threadIdx.y;
return threadIdYd;
}

__global__ void MatMult_three( int* A,  int* B, int* C){

		   int idy=getGlobalIdx_2D_1D();


		  for(int i=0;i<gridDim.x;i++)
		  {
		   int id=idy*gridDim.x+i;


		   for(int w=0;w<WA;w++)
		   {
			   for(int z=0;z<HB;z++)

			   {
					C[w*WB+id]+= A[w*HB+z] * B[id+z*WB];
			   }

		   }
		  }

       }

int main(){

int A[WA*HA];
int B[WB*HB];
int C[WC*HC]={0};
printf("A: ");
for(int i=0;i<WA*HA;i++)
{
	scanf("%d", &A[i]);
}
printf("B: ");
for(int i=0;i<WB*HB;i++)
{
	scanf("%d", &B[i]);
}
int (*pA), (*pB), (*pC);

cudaMalloc((void**)&pA, (WA*HA)*sizeof(int));
cudaMalloc((void**)&pB, (WB*HB)*sizeof(int));
cudaMalloc((void**)&pC, (WC*HC)*sizeof(int));

cudaMemcpy(pA, A, (WA*HA)*sizeof(int), cudaMemcpyHostToDevice);
cudaMemcpy(pB, B, (WB*HB)*sizeof(int), cudaMemcpyHostToDevice);
cudaMemcpy(pC, C, (WC*HC)*sizeof(int), cudaMemcpyHostToDevice);


MatMult_one<<<1,HA>>>(pA,pB,pC);

int choice = 0;
printf("Enter your choice: 1/2/3");
scanf("%d", &choice);
// Launch kernel onto the device
if(choice == 1)
{
	//rowwise
	MatMult_one<<<1,HA>>>(pA,pB,pC);
}
else if(choice == 2)
{
	//colwise
	MatMult_two<<<1,WB>>>(pA,pB,pC);

}
else
{
	//elementwise
	dim3 numBlocks = (3,3);
	dim3 threadsPerBlock(1,1);
	MatMult_three<<<numBlocks,threadsPerBlock>>>(pA,pB,pC);
}


cudaMemcpy(C, pC, (WC*HC)*sizeof(int), cudaMemcpyDeviceToHost);

int i, j=0;; printf("C = \n");
for(i=0;i<WC*HC;i++){
	if(j%WC==0) printf(" \n");
    printf("%d ", C[i]);
	j++;
    }
    printf("\n");


cudaFree(pA);
cudaFree(pB);
cudaFree(pC);

printf("\n");

return 0;
}



