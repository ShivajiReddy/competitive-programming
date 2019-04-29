#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <CL/cl.h>


#define DATA_SIZE (1024)

int main (int argc, char** argv) {

	int ret;                            

	cl_platform_id platform_id;			
	cl_device_id device_id;				
	cl_context context;					
	cl_command_queue command_queue;		
	cl_program program;					
	cl_kernel kernel;					

	cl_mem mem_a;						
	cl_mem mem_b;						
	cl_mem mem_c;						

	int ma, na, mb, nb;					

	int i = 0;

	ma = 3;
	na = 3;

	mb = 3;
	nb = 3;

	int A[9] = {1, -3, 4, 2, 0, 7, -5, -6, 9};
	//int A[9] = {1, -3, 4, 2, 0, 7};
	int B[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	//int B[9] = {1, 0, 0, 0, 1, 0};

	int *C = (int *)calloc(ma * nb, sizeof(int));

	

	FILE *kernel_code_file = fopen("kernel.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}

	char *source_str = (char *)malloc(DATA_SIZE);
	size_t source_size = fread(source_str, 1, DATA_SIZE, kernel_code_file);
	source_str[source_size] = '\0'; 

	fclose(kernel_code_file);

	ret = clGetPlatformIDs(1, &platform_id, NULL);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, NULL);

	if (ret != CL_SUCCESS) {
		printf("Error: Failed to create a device group!\n");
		return EXIT_FAILURE;
	}

	context = clCreateContext(0, 1, &device_id, NULL, NULL, &ret);

	if (!context) {
		printf("Error: Failed to create a compute context!\n");
		return EXIT_FAILURE;
	}

	command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);

	if (!command_queue) {
		printf("Error: Failed to create a command commands!\n");
		return EXIT_FAILURE;
	}

	mem_a = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * ma * na, NULL, NULL);
	mem_b = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * mb * nb, NULL, NULL);
	mem_c = clCreateBuffer(context,  CL_MEM_WRITE_ONLY,  sizeof(int) * na * mb, NULL, NULL);

	if (!mem_a || !mem_b || !mem_c) {
		printf("Error: Failed to allocate device memory!\n");
		exit(1);
	}

	ret  = 0;
	ret  = clEnqueueWriteBuffer(command_queue, mem_a, CL_TRUE, 0, sizeof(int) * ma * na, A, 0, NULL, NULL);
	ret |= clEnqueueWriteBuffer(command_queue, mem_b, CL_TRUE, 0, sizeof(int) * mb * nb, B, 0, NULL, NULL);

	if (ret != CL_SUCCESS) {
		printf("Error: Failed to write to source array!\n");
		exit(1);
	}

	program = clCreateProgramWithSource(context, 1, (const char **)&source_str, NULL, &ret);

	if (!program) {
		printf("Error: Failed to create compute program!\n");
		return EXIT_FAILURE;
	}



	

	ret = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

	if (ret != CL_SUCCESS) {
		size_t len;
		char buffer[2048];
		printf("Error: Failed to build program executable!\n");
		clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
		printf("%s\n", buffer);
		exit(1);
	}



	

	kernel = clCreateKernel(program, "multiply", &ret);

	if (!kernel || ret != CL_SUCCESS) {
		printf("Error: Failed to create compute kernel!\n");
		exit(1);
	}



	

	ret  = 0;
	ret  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &mem_a);
	ret |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &mem_b);
	ret |= clSetKernelArg(kernel, 2, sizeof(int), &na);
	ret |= clSetKernelArg(kernel, 3, sizeof(int), &mb);
	ret |= clSetKernelArg(kernel, 4, sizeof(cl_mem), &mem_c);

	if (ret != CL_SUCCESS) {
		printf("Error: Failed to set kernel arguments! %d\n", ret);
		exit(1);
	}



	

	size_t global_work_size[2] = {na, mb}; 
	size_t local_work_size[2] = {1, 1};

	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_work_size, local_work_size, 0, NULL, NULL);

	if (ret) {
		printf("Error: Failed to execute kernel!\n");
		return EXIT_FAILURE;
	}

 	clFinish(command_queue); 



	

	ret = clEnqueueReadBuffer(command_queue, mem_c, CL_TRUE, 0, sizeof(int) * na * mb, C, 0, NULL, NULL );

	if (ret != CL_SUCCESS) {
		printf("Error: Failed to read output array! %d\n", ret);
		exit(1);
	}


	printf("\nA:\n");
	for (i = 0; i < ma * na; ++i) {
		printf("\t%d", A[i]);
		if (i % ma == ma - 1)
			printf("\n");
	}

	printf("\nB:\n");
	for (i = 0; i < mb * nb; ++i) {
		printf("\t%d", B[i]);
		if (i % mb == mb - 1)
			printf("\n");
	}

	printf("\nA x B:\n");
	for (i = 0; i < na * mb; ++i) {
		printf("\t%d", C[i]);
		if (i % na == na - 1)
			printf("\n");
	}
	printf("\n\n");

	clReleaseMemObject(mem_a);
	clReleaseMemObject(mem_b);
	clReleaseMemObject(mem_c);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	return 0;

}
