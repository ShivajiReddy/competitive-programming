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
    string s;
    cin >> s;
    int i = 0, count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if((int) s[i] >= 65 && (int)s[i] <=92) count++;
        //i++;
    }
    
    cout<< count+1;
    
    return 0;
}
