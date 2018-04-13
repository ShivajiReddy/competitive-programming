#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m, k, photos = 0;
	cin >> n >> m >> k;
	int boxes = (n)*(m);

	for (int iter = 0; iter < k; iter++)
	{
		int i, j1, j2;
		cin >> i >> j1 >> j2;
		photos = photos + (j2+1) - j1;
	}

	cout << boxes-photos << endl;
	return 0;
}