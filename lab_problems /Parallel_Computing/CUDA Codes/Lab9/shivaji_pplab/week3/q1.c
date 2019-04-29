#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rank, n, i, size, fact = 1;
	int a[n];
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the array");
		for(i = 0; i < size; i++)
		{
			scanf("%d", &a[i]);
		}
	}
	MPI_Scatter(a, 1, MPI_INT, &n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	for(i = 1; i <= n; i++)
	{
		fact = fact * i;
	}
	printf("Factorial of %d: %d--->[%d]\n", n, fact, rank);
	MPI_Finalize();
	return 0;
}

/*int main(int argc, char *argv[])
{
	int rank, n, i, size, fact = 1, sum;
	int a[n], b[n];
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the array");
		for(i = 0; i < size; i++)
		{
			scanf("%d", &a[i]);
		}
	}
	MPI_Scatter(a, 1, MPI_INT, &n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	for(i = 1; i <= n; i++)
	{
		fact = fact * i;
	}

	MPI_Gather(&fact, 1, MPI_INT, b, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("Factorial of %d: %d--->[%d]\n", n, fact, rank);

	if(rank == 0)
	{
		for(i = 1; i <= n; i++)
		{
			sum = sum + b[i];
		}
		printf("Sum: %d\n", sum);
	}
	MPI_Finalize();
	return 0;
}*/

