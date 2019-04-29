#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#define MAX_SOURCE_SIZE (0X100000)
int main()
{
	printf("Input N:\n");
	int n,size;
	scanf("%d",&n);
	int *A=(int*)malloc(sizeof(int)*n);
	printf("Input A:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int *B=(int*)malloc(sizeof(int)*n);
	size=sizeof(int)*n;
	FILE *fp=fopen("q1.cl","r");
	if(!fp)
	{
		fprintf(stderr, "Failed to open kernel" );
		getchar();
		exit(1);
	}
	char *src_str;
	
	src_str=(char*)malloc(MAX_SOURCE_SIZE);
	
	int src_size=fread(src_str,1,MAX_SOURCE_SIZE,fp);

	fclose(fp);
    cl_uint numPlatforms=0;
    cl_uint numDevices=0;
	cl_platform_id platform_id[2];
	cl_device_id *device_id=NULL;
	cl_int status;

    status=clGetPlatformIDs(2,platform_id,NULL);
    
    status=clGetDeviceIDs(platform_id[0],CL_DEVICE_TYPE_GPU,0,NULL,&numDevices);
  
    device_id=(cl_device_id*)malloc(numDevices*sizeof(cl_device_id));
    status=clGetDeviceIDs(platform_id[0],CL_DEVICE_TYPE_GPU,numDevices,device_id,NULL);
     
    cl_context context=clCreateContext(NULL,1,device_id,NULL,NULL,&status);
    
    cl_command_queue cmdq;
    cmdq=clCreateCommandQueue(context,device_id[0],NULL,&status);
 
    cl_mem bufA,bufB;

    bufA=clCreateBuffer(context,CL_MEM_READ_ONLY,size,NULL,&status);
     
    bufB=clCreateBuffer(context,CL_MEM_WRITE_ONLY,size,NULL,&status);

    status=clEnqueueWriteBuffer(cmdq,bufA,CL_TRUE,0,size,A,0,NULL,NULL);

    cl_program program=clCreateProgramWithSource(context,1,(const char**)&src_str,NULL,&status);
    status=clBuildProgram(program,1,device_id,NULL,NULL,NULL);
    cl_kernel kernel=clCreateKernel(program,"octal",&status);

    status=clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&bufA);

    status=clSetKernelArg(kernel,1,sizeof(cl_mem),(void*)&bufB);

    size_t global_item_size=size;
  

    status=clEnqueueNDRangeKernel(cmdq,kernel,1,NULL,&global_item_size,NULL,0,NULL,NULL);
   
    status=clFinish(cmdq);
    
    status=clEnqueueReadBuffer(cmdq,bufB,CL_TRUE,0,size,B,0,NULL,NULL);
   
     
    for(int i=0;i<n;i++)
      {
      	printf("%d --> %d\n",A[i],B[i]);
      }

    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(cmdq);
     clReleaseMemObject(bufA);
     clReleaseMemObject(bufB);
     clReleaseContext(context);

     free(A);
     free(B);
free(device_id);
     return 0;


    

}