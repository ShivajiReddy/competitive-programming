#include<stdio.h>
#include<mpi.h>
int main(int argc,char* argv[])
{

	int rank,i,size,n;
	double psum=0,tsum=0,h,x,sum=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);



	if(rank==0)
	{

		printf("enter the interval\n");
		scanf("%d",&n);
	}
	MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
	h=1/(double)n;
	//printf("%lf",h);
	for(i=rank+1;i<=n;i=i+size)
	{
		x=h*(i-0.5);
		sum+= 4/(1+(x*x));
	}
	psum=h*sum;
	//printf("%lf",psum);
	MPI_Reduce(&psum,&tsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		printf("res %lf",tsum);
	}

	MPI_Finalize();


	return 0;
}
