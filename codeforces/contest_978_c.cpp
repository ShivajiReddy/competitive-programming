#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) { cin >> a[i]; }
	for (int i = 0; i < m; ++i) { cin >> b[i]; }

	vector<int> cummul_a(n);
	cummul_a = a;
	for (int i = 1; i < n; ++i) 
	{
		cummul_a[i] = cummul_a[i]+ cummul_a[i-1];
		cout << cummul_a[i] << " ";
	}

	int dorm_no = 0, previous = 0;
	for (int i = 0; i < m; ++i)
	{
		if(b[i] <= cummul_a[dorm_no]) 
			printf("%d %d\n", dorm_no+1, b[i]-previous);
		else
		{
			previous = cummul_a[dorm_no];
			dorm_no++;
			printf("%d %d\n", dorm_no+1, b[i]-previous);
		}
	}

	return 0;
}