#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n, size, rank, i;
	MPI_Status status;
	MPI_Init(&argc, &argv);


	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		n = 0;
		MPI_Ssend(&n, 1, MPI_INT, 1, rank, MPI_COMM_WORLD);
		MPI_Recv(&n, 1, MPI_INT, size-1, size, MPI_COMM_WORLD, &status);
		printf("n received: %d\n", n);
	}

	else if(rank < size-1)
	{
		MPI_Recv(&n, 1, MPI_INT, 0, rank-1, MPI_COMM_WORLD, &status);
		printf("n received: %d\n", n);
		n++;
		MPI_Ssend(&n, 1, MPI_INT, rank+1, rank, MPI_COMM_WORLD);
		printf("n: %d -> %d\n", n, rank);
	}
	else if(rank == size)
	{
		MPI_Recv(&n, 1, MPI_INT, 0, rank-1, MPI_COMM_WORLD, &status);
		printf("n received: %d\n", n);
		MPI_Ssend(&n, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
		n++;
	}

	MPI_Finalize();
	return 0;


}


https://github.com/mitcse/CSE-Labs/blob/master/PCAP%20Lab/Message%20Passing%20Interface/Collective%20Communications/average.cpp