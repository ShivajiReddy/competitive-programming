#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	int graph[10][10];
	int n;
	printf("Number of vertices:\n");
	scanf("%d", &n);

	printf("Enter the adjacency matrix\n");

	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}


	return 0;
}