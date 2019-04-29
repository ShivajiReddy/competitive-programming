#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rank, n, i;
	MPI_Status status;
	MPI_Init(&argc, &argv);


	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0)
	{
		printf("Enter the number to be sent: ");
		scanf("%d", n);

		for(i = 0; i < 5; i++)
		{
			MPI_Send(&n, 1, MPI_INT, i, i, MPI_COMM_WORLD);
		}
	}

	else
	{
		MPI_Recv(&n, 1, MPI_INT, 1, rank, MPI_COMM_WORLD, &status);
		printf("n: %d -> %d\n", n, rank);
	}

	MPI_Finalize();
	return 0;


}
