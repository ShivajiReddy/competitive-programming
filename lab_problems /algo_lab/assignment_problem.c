#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int getSum(int a[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum;
}
void fillMatrix(int powerSetMat[][n],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++) //mth row
	{	
		int temp=i;
		for(j=0;j<n;j++) //nth col
		{
			powerSetMat[i][j]=temp%2;
			temp/=2;
		}
	}
}
int main()
{
	printf("Enter the no.of ele:");
	scanf("%d",&n);
	int a[n];
	int i,j;
	//opcount=0;
	printf("Enter the array elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int m=pow(2,n);

	int powerSetMat[m][n];

	int sum=getSum(a,n);
	fillMatrix(powerSetMat,m,n);


	//printf("\n");   //to print the power set matrix
	//for(i=0;i<m;i++)
	//	{for(j=0;j<n;j++)
	//		{printf("%d\t",powerSetMat[i][j]);}
	//		printf("\n");
	//	}
	
	for(i=0;i<m;i++)
		{
			int rowsum=0;
			for(j=0;j<n;j++)
				{
					if(powerSetMat[i][j])
						rowsum+=a[j];
				}
				if(rowsum==sum/2)
				{
					printf("Disjoint set found!\n");
					printf("\nSet 1 is: \n");
					for(j=0;j<n;j++)
					{
						if(powerSetMat[i][j])
							printf("%d\t",a[j]);
					}
					printf("\nSet 2 is: \n");
					for(j=0;j<n;j++)
					{
						if(!powerSetMat[i][j])
							printf("%d\t",a[j]);
					}
					break;
				}
		}


	return 0;
}
