/*class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string res = ""
        int longest_count = strs[0].size();
        for(int i = 0; i < strs.size(); i++ )
        {
            for(int k = 1; k < min(longest_count, (int)strs[i].size()); k++)
            {
                if(strs[i][k] != strs[i][k])
                {
                    break;
                }
                longest_count++;
            }
        }
        
        return res;
    }
};*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]) ans = ans + a[i];
            else break;
        }
        return ans; 
    }
};