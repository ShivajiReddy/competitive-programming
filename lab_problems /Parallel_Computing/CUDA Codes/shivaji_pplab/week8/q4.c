)
#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include<string.h>

#define MAX_SOURCE_SIZE 0x100000

int main (void) {

	int i;

	int LIST_SIZE;



	// 0. Create and initialize two vectors

	int m,n;
	printf("Enter the dimensions: \n");
	scanf("%d%d",&m,&n);
	int *A = (int *)malloc(sizeof(int) * m*n);
	int *B = (int *)malloc(sizeof(int) * m*n);

	 printf("\n enter A\n");
    for(i=0;i<m*n;i++){
    	scanf("%d",&A[i]);
    }

    LIST_SIZE=m*n;
	// 1. Load the kernel code

	FILE *kernel_code_file = fopen("main.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}

	chars *source_str = (char *)malloc(MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str, 1, MAX_SOURCE_SIZE, kernel_code_file);

	fclose(kernel_code_file);

	// 2. Get platform and device information

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices, ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);


	// 3. Create an OpenCL context

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);


	// 4. Create a command queue

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);


	// 5. Create memory buffers on the device for each vector A and B

	cl_mem mem_obj_a = clCreateBuffer(context, CL_MEM_READ_ONLY, m*n* sizeof(int), NULL, &ret);
//	printf("ret1 %d\n",ret);
	cl_mem mem_obj_b = clCreateBuffer(context, CL_MEM_WRITE_ONLY,m*n*sizeof(int), NULL, &ret);

//	printf("ret2 %d\n",ret);
	// 6. Copy the list A to the respective memory buffers

	ret = clEnqueueWriteBuffer(command_queue, mem_obj_a, CL_TRUE, 0,m*n* sizeof(int), A, 0, NULL, NULL);

//	printf("ret3 %d\n",ret);
	// 7. Create a program from kernel source

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);


	// 8. Build the kernel program

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
//	printf("ret4 %d\n",ret);

	// 9. Create the OpenCL kernel object

	cl_kernel kernel = clCreateKernel(program, "mat", &ret);
//	printf("ret %d\n",ret);

	// 10. Set the arguments of the kernel

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_obj_a);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&mem_obj_b);

//printf("ret %d\n",ret);
	// 11. Execute the kernel on device

	size_t global_item_size[2] = {m,n};
	size_t local_item_size[2] = {1,1};

	// cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);


	// 12. Read the memory buffer C on the device to the local variable C, and display


	ret = clEnqueueReadBuffer(command_queue, mem_obj_b, CL_TRUE, 0,LIST_SIZE * sizeof(int),B, 0, NULL, NULL);

	for (i = 0; i <LIST_SIZE; ++i) {
		printf("%d ", B[i]);
	}
	printf("\n");



	clFlush(command_queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);

	clReleaseMemObject(mem_obj_a);
	clReleaseMemObject(mem_obj_b);

	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	free(A);
	free(B);

	int d;
	scanf(" %d", &d);

	return 0;

}

__kernel void mat(__global int *A, __global int *B)
{
int row = get_global_id(0);
int col=get_global_id(1);
int rsize=get_global_size(0);
int csize=get_global_size(1);
int sum=0;
for(int i=0;i<csize;i++)
sum+=A[row*csize+i];
for(int i=0;i<rsize;i++)
sum+=A[col+i*csize];
B[row*csize+col]=sum;
}

add1)

#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include<string.h>

#define MAX_SOURCE_SIZE 0x100000

int main (void) {

	int i;

	int LIST_SIZE;



	// 0. Create and initialize two vectors

	int m,n;
	printf("Enter the dimensions: \n");
	scanf("%d%d",&m,&n);
	int *A = (int *)malloc(sizeof(int) * m*n);
	int *B = (int *)malloc(sizeof(int) * m*n);

	 printf("\n enter A\n");
    for(i=0;i<m*n;i++){
    	scanf("%d",&A[i]);
    }

    LIST_SIZE=m*n;
	// 1. Load the kernel code

	FILE *kernel_code_file = fopen("main.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}

	char *source_str = (char *)malloc(MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str, 1, MAX_SOURCE_SIZE, kernel_code_file);

	fclose(kernel_code_file);

	// 2. Get platform and device information

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices, ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);


	// 3. Create an OpenCL context

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);


	// 4. Create a command queue

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);


	// 5. Create memory buffers on the device for each vector A and B

	cl_mem mem_obj_a = clCreateBuffer(context, CL_MEM_READ_ONLY, m*n* sizeof(int), NULL, &ret);
//	printf("ret1 %d\n",ret);
	cl_mem mem_obj_b = clCreateBuffer(context, CL_MEM_WRITE_ONLY,m*n*sizeof(int), NULL, &ret);

//	printf("ret2 %d\n",ret);
	// 6. Copy the list A to the respective memory buffers

	ret = clEnqueueWriteBuffer(command_queue, mem_obj_a, CL_TRUE, 0,m*n* sizeof(int), A, 0, NULL, NULL);

//	printf("ret3 %d\n",ret);
	// 7. Create a program from kernel source

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);


	// 8. Build the kernel program

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
//	printf("ret4 %d\n",ret);

	// 9. Create the OpenCL kernel object

	cl_kernel kernel = clCreateKernel(program, "mat", &ret);
//	printf("ret %d\n",ret);

	// 10. Set the arguments of the kernel

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_obj_a);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&mem_obj_b);

//printf("ret %d\n",ret);
	// 11. Execute the kernel on device

	size_t global_item_size[2] = {m,n};
	size_t local_item_size[2] = {1,1};

	// cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);


	// 12. Read the memory buffer C on the device to the local variable C, and display


	ret = clEnqueueReadBuffer(command_queue, mem_obj_b, CL_TRUE, 0,LIST_SIZE * sizeof(int),B, 0, NULL, NULL);

	for (i = 0; i <LIST_SIZE; ++i) {
		printf("%d ", B[i]);
	}
	printf("\n");



	clFlush(command_queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);

	clReleaseMemObject(mem_obj_a);
	clReleaseMemObject(mem_obj_b);

	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	free(A);
	free(B);

	int d;
	scanf(" %d", &d);

	return 0;

}

__kernel void mat(__global int *A, __global int *B)
{
int row = get_global_id(0);
int col=get_global_id(1);
int rsize=get_global_size(0);
int csize=get_global_size(1);
int sum=0;
if((row*csize+col)%2 ==0){
for(int i=0;i<csize;i++)
sum+=A[row*csize+i];
}
else{
for(int i=0;i<rsize;i++)
sum+=A[col+i*csize];
}
B[row*csize+col]=sum;
}

add2)

#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include<string.h>

#define MAX_SOURCE_SIZE 0x100000

int main (void) {

	int i;

	int LIST_SIZE;



	// 0. Create and initialize two vectors

	int m,n;
	printf("Enter the dimensions: \n");
	scanf("%d%d",&m,&n);
	int *A = (int *)malloc(sizeof(int) * m*n);
	int *B = (int *)malloc(sizeof(int) * m*n);

	 printf("\n enter A\n");
    for(i=0;i<m*n;i++){
    	scanf("%d",&A[i]);
    }

    LIST_SIZE=m*n;
	// 1. Load the kernel code

	FILE *kernel_code_file = fopen("main.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}

	char *source_str = (char *)malloc(MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str, 1, MAX_SOURCE_SIZE, kernel_code_file);

	fclose(kernel_code_file);

	// 2. Get platform and device information

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices, ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);


	// 3. Create an OpenCL context

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);


	// 4. Create a command queue

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);


	// 5. Create memory buffers on the device for each vector A and B

	cl_mem mem_obj_a = clCreateBuffer(context, CL_MEM_READ_ONLY, m*n* sizeof(int), NULL, &ret);
//	printf("ret1 %d\n",ret);
	cl_mem mem_obj_b = clCreateBuffer(context, CL_MEM_WRITE_ONLY,m*n*sizeof(int), NULL, &ret);

//	printf("ret2 %d\n",ret);
	// 6. Copy the list A to the respective memory buffers

	ret = clEnqueueWriteBuffer(command_queue, mem_obj_a, CL_TRUE, 0,m*n* sizeof(int), A, 0, NULL, NULL);

//	printf("ret3 %d\n",ret);
	// 7. Create a program from kernel source

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);


	// 8. Build the kernel program

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
//	printf("ret4 %d\n",ret);

	// 9. Create the OpenCL kernel object

	cl_kernel kernel = clCreateKernel(program, "mat", &ret);
//	printf("ret %d\n",ret);

	// 10. Set the arguments of the kernel

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_obj_a);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&mem_obj_b);

//printf("ret %d\n",ret);
	// 11. Execute the kernel on device

	size_t global_item_size[2] = {m,n};
	size_t local_item_size[2] = {1,1};

	// cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);


	// 12. Read the memory buffer C on the device to the local variable C, and display


	ret = clEnqueueReadBuffer(command_queue, mem_obj_b, CL_TRUE, 0,LIST_SIZE * sizeof(int),B, 0, NULL, NULL);

	for (i = 0; i <LIST_SIZE; ++i) {
		printf("%d ", B[i]);
	}
	printf("\n");



	clFlush(command_queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);

	clReleaseMemObject(mem_obj_a);
	clReleaseMemObject(mem_obj_b);

	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	free(A);
	free(B);

	int d;
	scanf(" %d", &d);

	return 0;

}

__kernel void mat(__global int *A, __global int *B)
{
int row = get_global_id(0);
int col=get_global_id(1);
int rsize=get_global_size(0);
int csize=get_global_size(1);
int sum=0;
if(row==col){
B[row*csize+col]=0;
}
if(row<col){
int prod=1;
int n=A[row*csize+col];
while(n>0){
 prod*=n;
 n--;
}
B[row*csize+col]=prod;
}
if(col<row){
int sum=0;
int n=A[row*csize+col];
while(n>0){
sum+=(n%10);
n/=10;
}
B[row*csize+col]=sum;
}

}



add3)

#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include<string.h>

#define MAX_SOURCE_SIZE 0x100000

int main (void) {

	int i;

	int LIST_SIZE;



	// 0. Create and initialize two vectors

	int m,n;
	printf("Enter the dimensions: \n");
	scanf("%d%d",&m,&n);
	int *A = (int *)malloc(sizeof(int) * m*n);
	int *B = (int *)malloc(sizeof(int) * m*n);

	 printf("\n enter A\n");
    for(i=0;i<m*n;i++){
    	scanf("%d",&A[i]);
    }

    LIST_SIZE=m*n;
	// 1. Load the kernel code

	FILE *kernel_code_file = fopen("main.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}

	char *source_str = (char *)malloc(MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str, 1, MAX_SOURCE_SIZE, kernel_code_file);

	fclose(kernel_code_file);

	// 2. Get platform and device information

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices, ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);


	// 3. Create an OpenCL context

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);


	// 4. Create a command queue

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);


	// 5. Create memory buffers on the device for each vector A and B

	cl_mem mem_obj_a = clCreateBuffer(context, CL_MEM_READ_ONLY, m*n* sizeof(int), NULL, &ret);
//	printf("ret1 %d\n",ret);
	cl_mem mem_obj_b = clCreateBuffer(context, CL_MEM_WRITE_ONLY,m*n*sizeof(int), NULL, &ret);

//	printf("ret2 %d\n",ret);
	// 6. Copy the list A to the respective memory buffers

	ret = clEnqueueWriteBuffer(command_queue, mem_obj_a, CL_TRUE, 0,m*n* sizeof(int), A, 0, NULL, NULL);

//	printf("ret3 %d\n",ret);
	// 7. Create a program from kernel source

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);


	// 8. Build the kernel program

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
//	printf("ret4 %d\n",ret);

	// 9. Create the OpenCL kernel object

	cl_kernel kernel = clCreateKernel(program, "mat", &ret);
//	printf("ret %d\n",ret);

	// 10. Set the arguments of the kernel

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_obj_a);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&mem_obj_b);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_int), (void *)&m);
//printf("ret %d\n",ret);
	// 11. Execute the kernel on device

	size_t global_item_size[2] = {4,4};
	size_t local_item_size[2] = {1,1};

	// cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);


	// 12. Read the memory buffer C on the device to the local variable C, and display


	ret = clEnqueueReadBuffer(command_queue, mem_obj_b, CL_TRUE, 0,LIST_SIZE * sizeof(int),B, 0, NULL, NULL);

	for (i = 0; i <LIST_SIZE; ++i) {
		printf("%d ", B[i]);
	}
	printf("\n");



	clFlush(command_queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);

	clReleaseMemObject(mem_obj_a);
	clReleaseMemObject(mem_obj_b);

	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	free(A);
	free(B);

	int d;
	scanf(" %d", &d);

	return 0;

}

__kernel void mat(__global int *A, __global int *B,int n)
{
int row = get_global_id(0);
int col=get_global_id(1);
for(int i=0;i<n/2;i++){
B[row*(2*n)+col*(n/2)+i]=A[row*(2*n)+(col*(n/2))+i]+(row*2)+col+1;
B[n+row*(2*n)+col*(n/2)+i]=A[n+row*(2*n)+col*(n/2)+i]+(row*2)+col+1;
}



}