#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isPresent(int p,int lrustack[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(lrustack[i]==p)
			return i;
	}
	return -1;
}

void lru_secondchance(int p[],int n,int fm_sz)
{
	printf("Entering Second Chance Algo\n");
	int f[fm_sz];
	int ptr=0;
	int i,j,k,page_fault=0;
	for(i=0;i<fm_sz;i++)
		f[i]=-1;
	int ref_bit[fm_sz];
	for(i=0;i<fm_sz;i++)
		ref_bit[i]=0;


	for(i=0;i<n;i++)
	{
		if(isPresent(p[i],f,fm_sz)==-1)
		{
			while(ref_bit[ptr]==1)
	1		{
				ref_bit[ptr]=0;
				ptr=(ptr+1)%fm_sz;
			}
			f[ptr]=p[i];
			ref_bit[ptr]=1;
			ptr=(ptr+1)%fm_sz;
			page_fault++;
			printf("Page fault occurred for page: %d\n",p[i]);
		}
		else
		{
			int loc = isPresent(p[i],f,fm_sz);
			ref_bit[loc]=1;
		}
		printf("FRAME CONTENTS & REF BITS:\n");
		for(k=0;k<fm_sz;k++)
			printf("%d\t%d\n",f[k],ref_bit[k]);
	}
	printf("PAGE FAULTS: %d\n",page_fault );
}



int main()
{
	int n,i,j,k,fm_sz;
	printf("Enter the no.of entries:\n");
	scanf("%d",&n);
	int p[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter the frame size:\n");
	scanf("%d",&fm_sz);
	lru_secondchance(p,n,fm_sz);
	return 0;
}