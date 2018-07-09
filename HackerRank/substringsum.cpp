#include <bits/stdc++.h>
using namespace std;
#define modmax 1000000007


//sumofdigit[i] = (i+1)*num[i] + 10*sumofdigit[i-1]
int solve(string s)
{
	int n = s.length();
    long long A[n];
    A[0] = s[0] - '0';
    int ans = A[0];

    for(int i = 1; i < n; ++i) {
        int y = s[i] - '0';
        A[i] = A[i-1]*10 + (i+1)*y;
        A[i] = A[i] % modmax;
        ans += A[i];
        ans = ans % modmax;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	cout << solve(num);
	return 0;
}