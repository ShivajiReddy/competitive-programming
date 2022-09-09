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

int error1And2(string s, vector<vector<int>>&dup) {
    int u, v, n = s.length();
    if(n%6 != 5) return 1;
    for(int i = 0; i < n; i+= 6) {
        u = s[i+1]-'A';
        v = s[i+3]-'A';
        //Check if input pattern is correct
        if(s[i] != '(' || (!(u>-1 && u < 26)) || s[i+2] != ',' ||
          (!(v>-1 && v < 26)) || s[i+4] != ')' || 
          ((i+5)!=n && s[i+5] !=' '))
            return 1;
    }
    //Check if there are duplicates
    for(int i = 0; i < n; i+= 6) {
        u = s[i+1]-'A';
        v = s[i+3]-'A';
        if(dup[u][v] == 1)
            return 2;
        else if(dup[u][v] == 0)
            dup[u][v] = 1;
    }
    return 0;
}

int error3And4(vector<vector<int>>&dup, vector<int>adj[], int &root) {
    //Create adjacency matrix
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(dup[i][j] == 1)
                adj[i].push_back(j);
        }
    }
    
    //if number of children greater than 2, not a binary tree
    for(int i = 0; i < 26; i++)
    {
        if(adj[i].size() > 2)
            return 3;
    }
    //visited array
    int vis[26] = {0};
    for(int i = 0; i < 26; i++) {
        if(adj[i].size() > 0) {
            vis[i] = 1;
        }
    }
    
    //mark children as zero
    for(int i = 0; i < 26; i++) {
        for(auto it: adj[i]) vis[it] = 0;
    }
    
    //if there are two roots return error code, else root
    for(int i = 0; i < 26; i++)
    {
        if(vis[i] == 1)
        {
            if(root == -1)
                root = i;
            else
                return 4;
        }
    }
    
    return 0;
}

//Error5 - Detect cycle
bool isCyclic(vector<int> adj[])
{
    //BFS detect cycle
    int vis[26] = {0};
    queue<pair<int,int>> q;
    for(int i = 0; i < 26; i++) {
        if(adj[i].size() > 0 && vis[i] == 0) {
            q.push({i, -1});
            vis[i]= 1;
            while(!q.empty()) {
                int x1 = q.front().first;
                int x2 = q.front().second;
                q.pop();
                
                for(auto it : adj[x1]) {
                    if(vis[it] == 0) {
                        q.push({it, x1});
                        vis[it] = 1;
                    }
                    else if(vis[it] == 1 && it != x2) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

//S-Expression respresentation
string solve(int root, vector<int>adj[]) {
    //Lexicographic order
    if(adj[root].size() == 2) {
        if(adj[root][0] > adj[root][1])
            swap(adj[root][0], adj[root][1]);
    }
    string s = "(";
    s.push_back(root + 'A');
    //Repeat recrusively
    if(adj[root].size() > 0)
        s += solve(adj[root][0], adj);
    if(adj[root].size() > 1)
        s += solve(adj[root][1], adj);
        
    s += ")";
        
    return s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    getline(cin, s);
    
    int error, root = -1;
    vector<vector<int>> dup(26, vector<int>(26, 0));
    error = error1And2(s, dup);
    if(error > 0)
    {
        cout << "E" << error << endl;
        return 0;
    }
    
    vector<int> adj[26];
    error = error3And4(dup, adj, root);
    if(error > 0)
    {
        cout << "E" << error << endl;
        return 0;
    }
    int vis[26] = {0};
    if(isCyclic(adj))
    {
        cout << "E5" << endl;
        return 0;
    }
    
    cout << solve(root, adj);
}