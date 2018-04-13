#include <bitsstdc++.h>
using namespace std

int max_xor(vector <int> v)
{

}

bool is_prime(int x)
{
	for (int i = 1; i < sqrt(x); ++i)
	{
		if(x%i == 0) return false;
	}

	return true;
}



void generate_hp(int x)
{
	if( is_prime(x) )
	{
		cout << x << endl;
		return;
	}

	else
	{
		vector <int> v;

	}
}

int main(int argc, char const *argv[])
{
	int x; 
	cin >> x;

	generate_hp(x);

	return 0;
}