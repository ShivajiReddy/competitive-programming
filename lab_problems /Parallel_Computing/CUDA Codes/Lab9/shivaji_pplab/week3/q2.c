#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]){

	MPI_Init(&argc, &argv);

	int rank, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int i, num, arr[size], fact_arr[size];

	if(rank == 0){
		printf("Enter %d numbers:", size);
		for(i=0;i<size;i++)
			scanf("%d", &arr[i]);
	}

	MPI_Scatter(arr, 1, MPI_INT, &num, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("Process %d has received %d\n", rank, num);

	int facto = 1;
	for(i=num;i>1;i--)
		facto *= i;

	//printf("Factorial of %d = %d --> %d\n", num, facto, rank);

	MPI_Gather(&facto, 1, MPI_INT, fact_arr, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0){
		int total_fact = 0;
		printf("The values gathered in the root are: ");
		for(i=0;i<size;i++){
			printf("%d  ", fact_arr[i]);
			total_fact += fact_arr[i];
		}

		printf("\nSum of factorial = %d -->%d\n", total_fact, rank);
	}

	MPI_Finalize();

	return 0;
}
