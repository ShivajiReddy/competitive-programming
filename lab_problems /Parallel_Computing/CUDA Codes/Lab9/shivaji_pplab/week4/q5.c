#include<stdio.h>
#include<mpi.h>
int main(int argc,char* argv[])
{

	int rank,j,i,size,a[4][4],b[4];
	int c[4];


	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0)
	{

		printf("enter matrix elements\n");
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&a[i][j]);

	}

	MPI_Scatter(a,4,MPI_INT,b,4,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scan(b,c,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD);

	for(i=0;i<4;i++)
	{
		printf("%d\t",c[i]);
	}
	printf("\n");


	MPI_Finalize();


	return 0;
}


