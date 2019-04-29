__kernel void onecomp(__global int *A,__global int *B)
{
	int i = get_global_id(0);
	
	int temp = A[i];
	
	if(temp == 0){
		B[i] = 1;
		return;
	}
	int count = 0;
	while(temp>0){
		int rem = temp%10;
		if(rem == 0)
			rem = 1;
		else
			rem = 0;
		
		int j = count;
		while(j>0){
			rem = rem*10;
			j--;
		}
		
		count++;
		temp /= 10;
		B[i] += rem;
	}
}