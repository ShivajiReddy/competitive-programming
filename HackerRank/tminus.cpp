#include <bits/stdc++.h>
using namespace std;

double gcd(double a, double b) 
{
    if(a < b) return gcd(b, a);

    if(fabs(b) < 0.001) return a;

    else 
        return (gcd(b, a - floor(a / b) * b));
}

int main()
{
    /* Enter your code here. Read input from STDIN. Prdouble output to STDOUT */ 
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {   
        double a, b, result;
        cin >> a >> b;
        result = gcd(a, b);
        cout << (a*b)/(double)(result) << endl;
        //cout<< result << endl;
    }
    return 0;
}
