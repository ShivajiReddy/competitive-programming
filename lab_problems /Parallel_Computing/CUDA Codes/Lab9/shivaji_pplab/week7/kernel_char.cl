__kernel void ssort(__global char *A,__global char *B,int l)
{
int id = get_global_id(0);
char data = A[id];
//B[id]=A[id];


int i,pos=0;

for(i=0;i<l;i++)
{
	//if(A[i]==' ')
	//{pos=-1;}
	if((A[i]<data)||(A[i]==data && i<id))
		pos++;
		
}
B[pos]=data;
}

