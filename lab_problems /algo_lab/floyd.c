#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int add(int a,int b)
{
	if(a==INT_MAX || b==INT_MAX)
		return INT_MAX;
	return a+b;
}
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{	
	int n;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	int adjMat[n][n];
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			{if(i==j)
				adjMat[i][j]=0;
			else
				adjMat[i][j]=INT_MAX;
			}
	int e,temp;
	printf("Enter the number of edges:\n");
	scanf("%d",&e);
	temp=e;
	printf("Enter %d edges along with weight:\n",e);
	while(temp--)
	{
		int n1,n2,wt;
		scanf("%d %d %d",&n1,&n2,&wt);
		adjMat[n1-1][n2-1]=wt;
	}

	printf("The weighted matrix is\n");
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
		{if(adjMat[i][j]==INT_MAX)
				printf("inf\t\t");
			else
				printf("%d\t\t",adjMat[i][j]);}
		printf("\n");}


	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{

				adjMat[i][j]= min( adjMat[i][j] , add(adjMat[k][j],adjMat[i][k])) ; 
			}

	printf("The final weighted matrix using Floyd's algorithm\n");
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
		{if(adjMat[i][j]==INT_MAX)
				printf("inf\t\t");
			else
				printf("%d\t\t",adjMat[i][j]);}
		printf("\n");}

	return 0;
}