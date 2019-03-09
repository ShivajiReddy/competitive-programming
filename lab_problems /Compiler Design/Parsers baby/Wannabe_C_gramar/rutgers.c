#include "mymalloc.h"

void test_a()
{
	int i;
	for (i = 0; i < 150; i++)
	{
		char *a = (char *)malloc(sizeof(char));
		free(a);
	}
}

void test_b()
{
	char *arr[50];

	int i, j;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 50; i++)
		{
			arr[i] = (char *)malloc(sizeof(char));
		}

		for (i = 0; i < 50; i++)
		{
			free(arr[i]);
		}
	}
}

void test_c()
{
	char *arr[50];

	int write_index = 0, last_index = -1, num_operations = 0, num_mallocs = 0;

	while (num_mallocs < 50)
	{
		int op = get_random_range(0, 1);

		// Allocate
		if (op == 0)
		{
			char *a = (char *)malloc(sizeof(char));
			if (a != NULL)
			{
				arr[write_index] = a;
				last_index = write_index;
				++write_index;
				++num_mallocs;
			}

			else
			{
				// Could not malloc
			}

		}

		// Free
		if (op == 1)
		{
			if (last_index < 0 && write_index == 0)
				continue;

			free(arr[last_index]);
			--write_index;
			--last_index;
		}

		++num_operations;
	}

	// Free the rest of the heap
	int i;
	for (i = 0; i < write_index; i++)
		free(arr[i]);

//	printf("Test C results:\n");
//	printf("Number of operations: %d\n", num_operations);
//	print_heap();	
//	printf("-----------------------------------\n\n");
}

void test_d()
{
	int num_operations = 0, write_index = 0, last_index = -1, num_mallocs = 0;

	char *arr[50];
	while (num_mallocs < 50)
	{
		int op = get_random_range(0, 1);
		int size = get_random_range(1, 64);

		if (size <= 0)
			continue;

		// Malloc
		if (op == 0)
		{
			char *a = (char *)malloc(sizeof(char) * size);
			if (a != NULL)
			{
				arr[write_index] = a;
				last_index = write_index;
				++write_index;
				++num_mallocs;
			}

			else
			{
				// Couldn't malloc
			}
		}

		// Free
		if (op == 1)
		{
			if (last_index < 0 && write_index == 0)
				continue;

			free(arr[last_index]);
			--write_index;
			--last_index;
		}

		++num_operations;
	}

	// Free the rest of the heap
	int i;
	for (i = 0; i < write_index; i++)
		free(arr[i]);

//	printf("Test D results:\n");
//	printf("Number of operations: %d\n", num_operations);
//	print_heap();
//	printf("-----------------------------------\n\n");
}

void test_e()
{
	int x = 10;
	free(&x);
	char *p = (char*)malloc(sizeof(char) * 13);
	free(p);
	free(p);
	short * q = (short*)malloc(-1);
	int *z = (int*)malloc(sizeof(int) * 25);
	free(z);
	z = (int*)malloc(200);
	free(z);
	long *kk = (long*)malloc(sizeof(long)*16);
	free(kk);

//	printf("Test E results:\n");
//	print_heap();
//	printf("-----------------------------------\n\n");
}

void test_f()
{
	int *a = (int*)malloc(sizeof(int));
	int *b = (int*)malloc(sizeof(int));
	free(a+12);
	free(b);
	free(a);
	free(b);
	free(a);
	char *p = (char*)malloc(sizeof(char) * 4090);
	free(p);
	p = (char*)malloc(sizeof(char) * 4090);
	free(p);

//	printf("Test F results:\n");
//	print_heap();
//	printf("-----------------------------------\n\n");
}


int get_random_range(int low, int high)
{
	return (low + rand() % (high + 1 - low));
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	int i;
	struct timeval t0, t1;
	gettimeofday(&t0, NULL);
	for(i = 0; i<100; ++i)
	{
		test_a();
	}
	gettimeofday(&t1, NULL);
	double time1 = (t1.tv_sec - t0.tv_sec) + ((t1.tv_usec - t0.tv_usec)/1000000.0);
	double avgtime1 = time1/100.0;

	struct timeval t2, t3;
	gettimeofday(&t2, NULL);
	for(i = 0; i<100; ++i)
	{
		test_b();
	}
	gettimeofday(&t3, NULL);
	double time2 = (t3.tv_sec - t2.tv_sec) + ((t3.tv_usec - t2.tv_usec)/1000000.0);
	double avgtime2 = time2/100.0;

	struct timeval t4, t5;
	gettimeofday(&t4, NULL);
	for(i = 0; i<100; ++i)
	{
		test_c();
	}
	gettimeofday(&t5, NULL);
	double time3 = (t5.tv_sec - t4.tv_sec) + ((t5.tv_usec - t4.tv_usec)/1000000.0);
	double avgtime3 = time3/100.0;

	struct timeval t6, t7;
	gettimeofday(&t6, NULL);
	for(i = 0; i<100; ++i)
	{
		test_d();
	}
	gettimeofday(&t7, NULL);
	double time4 = (t7.tv_sec - t6.tv_sec) + ((t7.tv_usec - t6.tv_usec)/1000000.0);
	double avgtime4 = time4/100.0;

	struct timeval t8, t9;
	gettimeofday(&t8, NULL);
	for(i = 0; i<100; ++i)
	{
		test_e();
	}
	gettimeofday(&t9, NULL);
	double time5 = (t9.tv_sec - t8.tv_sec) + ((t9.tv_usec - t8.tv_usec)/1000000.0);
	double avgtime5 = time5/100.0;

	struct timeval t10, t11;
	gettimeofday(&t10, NULL);
	for(i = 0; i<100; ++i)
	{
		test_f();
	}
	gettimeofday(&t11, NULL);
	double time6 = (t11.tv_sec - t10.tv_sec) + ((t11.tv_usec - t10.tv_usec)/1000000.0);
	double avgtime6 = time6/100.0;

	printf("Workload 1 Time: %lf seconds and the average time to run once is %lf seconds\n", time1, avgtime1);
	printf("Workload 2 Time: %lf seconds and the average time to run once is %lf seconds\n", time2, avgtime2);
	printf("Workload 3 Time: %lf seconds and the average time to run once is %lf seconds\n", time3, avgtime3);
	printf("Workload 4 Time: %lf seconds and the average time to run once is %lf seconds\n", time4, avgtime4);
	printf("Workload 5 Time: %lf seconds and the average time to run once is %lf seconds\n", time5, avgtime5);
	printf("Workload 6 Time: %lf seconds and the average time to run once is %lf seconds\n", time6, avgtime6);

	return 0;
}