#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    vector<int> h(26);
    for(int h_i = 0; h_i < 26; h_i++)
    {
       cin >> h[h_i];
    }
    string word;
    cin >> word;

    vector <int> height(10);

    for (int i = 0; i < word.length(); i++)
    {
    	int letter = (int)word[i] - 97;
    	height[i] = h[letter];
    	//cout<< height[i];
    }
    
    int max=*max_element(height.begin(), height.end());
    cout<<max*word.length();

    return 0;
}
