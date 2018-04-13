#include <bits/stdc++.h>

using namespace std;

//Iterative Function to calculate (x^y) in O(log y) 
int power(int x, unsigned int y)
{
    int res = 1;     // Initialize result
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
        {
        	cout<<"y is: "<<y<<endl;
            res = res*x;
            cout<<"res: "<<res<<endl;
  		}

        // n must be even now
        y = y>>1; // y = y/2
        cout<<"y is: "<<y<<endl;

        x = x*x;
        cout<<"x is: "<<x<<endl;  // Change x to x^2
    }
    return res;
}

int main(int argc, char const *argv[])
{
	int x, n;
	cout<<"x n: ";
	cin>>x>>n;

	cout<<power(x, n);
}