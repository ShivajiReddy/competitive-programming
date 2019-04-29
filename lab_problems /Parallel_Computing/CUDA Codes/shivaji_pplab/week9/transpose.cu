#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

//M x N
#define HA 2
#define WA 2
#define HB 2
#define WB 2

//rowwise
__global__ void transpose (int *A, int *B) {
    // Get the 1D Array index of the matrix
  int id=threadIdx.x;

  for(int i=0;i<HA;i++)
  {

	  B[i*WA+id] = A[id*HA+i];
  }
}

int main ()
{
    // Host copies of the variables
    int A[HA*WA], B[HA*WA];

    int i, j;
    for (i = 0; i < HA*WA; ++i) {
        A[i] = i + 1;
    }

    // Device copies of the variables
    int *d_a, *d_b;

    int size = sizeof(int)*HA*WA;

    // Allocate memories to device copies of the objects
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);

    // Copy inputs to device
    cudaMemcpy(d_a, &A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &B, size, cudaMemcpyHostToDevice);

    for (i = 0; i < HA; ++i) {
            for (j = 0; j < WA; ++j) {
                printf("%d\t", A[i * WA + j]);
            }
            printf("\n");
        }
    transpose<<<1, HA>>>(d_a, d_b);
    cudaMemcpy(&B, d_b, size, cudaMemcpyDeviceToHost);


    printf("\n");

    printf("B:\n");
    for (i = 0; i < HA; ++i) {
        for (j = 0; j < WA; ++j) {
            printf("%d\t", B[i * WA + j]);
        }
        printf("\n");
    }
    printf("\n");

    cudaFree(d_a);
    cudaFree(d_b);

    getchar();

    return 0;
}
