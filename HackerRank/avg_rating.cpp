#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>

using namespace std;

float answer(float val)
{
	if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	float sum = 0, count = 0;
	while(n--)
	{
		float x; 
		cin >> x;
		if(x >= 90) 
		{
			count++;
			sum += x;
		}	
	}

	sum = sum/count + (0.001);
	printf("%.2f", sum);


	//cout << answer(sum * 100.0)/100.0 << endl;

	return 0;
}