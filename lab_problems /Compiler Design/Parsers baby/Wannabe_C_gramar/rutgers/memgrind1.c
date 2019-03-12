#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void testA();
//void testB();
//void testC();
//void testD();
//void testE();
//void testF();

int range(int l,int h)
{
	int g =(l+rand()%(h+1-l));
	return g;
}
int main(int argc, char*argv[])
{
    int k;
    clock_t start,end;
	double time_taken;
	start=clock();
	for(k=0;k<100;++k)
	{
		testA();
	}
	//	end = clock()-start;
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	printf(" time took for this test %lf\n",time_taken);
	double averageTime= time_taken/100.0;
	printf("TEST CASE A AVG TIME %lf in seconds\n",averageTime);
  
// END OF THE TEST A 
/*
	// starting the test B
	clock_t start1, end1;
	double time_taken1;
	start1=clock();
	int b;
	for(b=0;b<100;++b)
	{
		testB();
	}
	end1=clock();
	time_taken1=((double)(end1-start1*10000))/CLOCKS_PER_SEC;
	double averageTime1=time_taken/100.0;
	printf("TEST CASE B %lf AVG TIME FOR TEST CASE B %lf in seconds\n",averageTime1);
*/
	/*	
	// STARTING THE TEST CASE C
	clock_t start2, end2;
	double time_taken2;
	start2=clock();
	
	for(k=0;k<100;++k)
	{
		testC();
	}	
	 end2=clock();
	time_taken2=((double)(end2-start2))/CLOCKS_PER_SEC;
	double averageTime2=time_taken2/100.0;
	printf("TEST CASE C %lf AVG TIME for test CASE C %lf in seconds\n",averageTime2);
	*/	 
return 0;
}

void testA()
{
	int k;
	do
	{
		char *OneByte=(char*)malloc(sizeof(char));
		free(OneByte);
		++k;
	}while(k<150);
}
/*
void testB()
{
  
// array of 50 bytes
 char *TestB[50]
   int i, j;
	for(j=0;j<3;j++)
	{
		for(i=0;i<50;i++)
		{
			TestB[i]=(char *)malloc(sizeof(char));
		}
		
		for(i=0;i<50;i++)
		{
			free(TestB[i]);
		}
	}
}
*/
/*
void testC()
{
 	char *TestC[50]
	  int write_index=0, last_index= -1, num_operations=0, num_mallocs=0;
	
	while(num_mallocs<50)
	{
	int op=range(0,1);
	
		if(op==0)
			{
			char *h=(char*)malloc(sizeof(char));
			if(h!=NULL)
				{
				TestC[write_index]=h;
				last_index=write_index;
				++write_index;
				++num_mallocs;
				}
				else
				{
	
				}
			}
		if(op==1)
		{
			if(write_index==0 && last_index<0)
				{
				continue;
				}

			free(TestC[last_index]);
			--write_index;
			--last_index;
		}
		++num_operations;
	}
		int w;
		for(w=0;w<write_index;w++)
			free(TestC[w]);
			
}
*/