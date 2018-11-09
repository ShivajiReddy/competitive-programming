#include <stdio.h>
#include <stdlib.h>

int ispresent(int a,int s,int st[])
{
	int i;
	for(i=0;i<s;i++)
	{
		if(a==st[i])
			return i;
	}

	return -1;
}

int getindex(int sz,int f[],int n,int p[],int pos)
{
	int rep = 0, max = pos, i ,j;

	for (i = 0; i < sz; ++i)
	{
		for (j = pos; j < n; ++j)
		{
			if(f[i]==p[j])
			{
				if(j>max)
				{
					max=j;
					rep=i;
				}
				break;
			}
		}
		if(j == n) return i;
	}

	return rep;

	//return occ[0]>occ[1]?(occ[0]>occ[2]?occ[0]:occ[2]):(occ[1]>occ[2]?occ[1]:occ[2]);	
}

/*
20
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1*/

void op(int n,int sz,int p[])
{
	int f[sz];
	int pg = sz;
	for(int i=0;i<sz;i++)
	{
		f[i]=p[i];
	}
	
	for(int i=sz;i<n;i++)
	{
		if(ispresent(p[i],sz,f)==-1)
		{

			int ptr = getindex(sz,f,n,p,i);
			for(int j=0;j<sz;j++)
				printf("%d ",f[j]);

			printf(" %d replacing with %d ", f[ptr], p[i]);
			printf("\n");
			//printf("%d is not present. It's ptr is %d\n", p[i], ptr);			
			f[ptr] = p[i];
			pg++;			
		}

	}
	for (int i = 0; i < sz; ++i)
	{
		printf("%d ", f[i]);
	}
	printf("\nPage faults: %d\n",pg );
}

int main()
{
	int sz,n;
	scanf("%d",&n);
	scanf("%d",&sz);
	int p[n];
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	op(n,sz,p);
}