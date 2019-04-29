__kernel void onecomp(__global char *A,__global char *B)
{
	int tid=get_global_id(0);
  B[tid]=A[tid]=='0'?'1':'0';
}

