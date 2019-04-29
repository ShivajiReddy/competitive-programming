#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SOURCE_SIZE (0x100000)

int main(){

	time_t start, end;
	start = clock();
	int i;

	char tempstr[20486];

	for (i = 0; i < 20485; ++i)
	{
		tempstr[i] = 'A';
	}
	tempstr[20485] = '\0';

	int len = strlen(tempstr);
	len++;

	char *str = (char *)malloc(sizeof(char)*len);
	strcpy(str, tempstr);

	FILE *fp;
	char *source_str;
	size_t source_size;

	fp = fopen("q1.cl", "r");

	if(!fp){
		fprintf(stderr, "Failed to load kernel\n");
		getchar();
		exit(1);
	}

	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);

	fclose(fp);

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, CL_QUEUE_BUFFER_PROFILING_ENABLE, &ret);

	cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, num*sizeof(int), NULL, &ret);

	cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, num*sizeof(int), NULL, &ret);

	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, num*sizeof(int), arr, 0, NULL, NULL);

	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, "str_chgcase", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&b_mem_obj);

	size_t global_item_size = num;
	size_t local_item_size = 1;

	cl_event event;

	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);

	

	char *strees = (char *) malloc(sizeof(char)*len);
	ret = clEnqueueReadBuffer(command_queue, b_mem_obj, CL_TRUE, 0, num*sizeof(int), strres, 0, NULL, NULL);
	printf("Done\n");
	strres[len-1] = '\0';
	printf("Resultant string: %s\n", strres);

	for(i=0;i<num;i++)
		printf("%d --> %d\n", arr[i], B[i]);

	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
	ret = clReleaseMemObject(b_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);


	free(arr);
	free(B);
	getchar();

	return 0;
}
