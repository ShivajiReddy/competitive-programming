#include <bits/stdc++.h>

using namespace std;

int calculate_max_sum(int a[], int n)
{
    // sorts the array c++ stl
    sort(a, a + n);
    return a[n-1] - a[0];

}

/*int minimumTime(vector <int> x) 
{
    for(int ) 
}*/

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        //vector<int> x(n);
        int x[n];
        for(int x_i = 0; x_i < n; x_i++){
           cin >> x[x_i];
        }
        int result = calculate_max_sum(x, n);
        cout << result << endl;
    }
    return 0;
}
