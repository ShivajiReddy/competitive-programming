__kernel void swap(__global int *A,__global int *n)
{
	int tid=get_global_id(0);


    if(tid%4==0)
    {
    	if(tid+2<*n)
    	{int temp=A[tid];
    	A[tid]=A[tid+2];
    	A[tid+2]=temp;
    }
         if(tid+1 <*n && tid+3 <*n)
    	{int temp=A[tid+1];
    	A[tid+1]=A[tid+3];
    	A[tid+3]=temp;
    }
}
}


__kernel void swap(__global int *A)
{
    int i=get_global_id(0);

    int temp = A[2*i];
    A[(2*i)] = A[(2*i)+1];
    A[(2*i)+1] = temp;
}

