#include<stdio.h>
#include <CL/cl.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//Max source size of the kernel string
#define MAX_SOURCE_SIZE (0x100000)
int main(void)
{

    int i,l,n;
    char str[400],opstr[400];
    //char B[l+1];
    printf("input no of words\n");
    scanf("%d",&n);

    //char *str =(char *)malloc(sizeof(char)*256);
    printf("Enter string ");
    //for(i=0;i<10;i++)
    scanf("%s",str);

    l=strlen(str);
    str[l]='\0';


    FILE *fp;
    char *source_str;
    size_t source_size;
    fp = fopen("1.cl", "r");
    if (!fp)
    {
        fprintf(stderr, "Failed to load kernel.\n");
        getchar();
        exit(1);
    }
    source_str = (char*)malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose( fp );
    //char *B = (char*)malloc(sizeof(char)*(l*n+1));

    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_CPU, 1,&device_id,&ret_num_devices);

    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL,&ret);

    cl_command_queue command_queue = clCreateCommandQueue(context,device_id,NULL, &ret);

    cl_mem a_mem_obj = clCreateBuffer(context,CL_MEM_READ_ONLY,l* sizeof(char), NULL, &ret);
    cl_mem b_mem_obj = clCreateBuffer(context,CL_MEM_WRITE_ONLY,l* sizeof(char), NULL, &ret);

    ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE,0,l* sizeof(char), str, 0, NULL, NULL);

    cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t *)&source_size, &ret);

    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    //printf("%d",ret);

    cl_kernel kernel = clCreateKernel(program, "ssort", &ret);


    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&a_mem_obj);

    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_int),(void *)&l);

    size_t global_item_size = l;
    size_t local_item_size = 1;

    cl_event event;
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,&global_item_size, &local_item_size, 0, NULL, NULL);
    ret = clFinish(command_queue);


    ret = clEnqueueReadBuffer(command_queue, b_mem_obj, CL_TRUE, 0,l* sizeof(char), opstr, 0, NULL, NULL);

    //for(i = 0; i < l; i++)
        printf("%s",opstr);

    ret = clFlush(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(a_mem_obj);
//ret = clReleaseMemObject(b_mem_obj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    ///free(str);
    //free(B);
    getchar();
    return 0;
}

