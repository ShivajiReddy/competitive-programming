__kernel void octal(__global int *A,__global int *B)
{
	int tid=get_global_id(0);

	int num=A[tid];

	int res=0,p=1;
	while(num!=0)
	{
	  int d=num%8;
	  res=res+d*p;
	  num/=8;
	  p*=10;

	}

	B[tid]=res;
}