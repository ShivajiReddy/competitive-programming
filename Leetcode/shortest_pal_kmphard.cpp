//https://leetcode.com/problems/shortest-palindrome/submissions/

class Solution {
public:
    string shortestPalindrome(string s) {
        //stl reverse works in place so gotta copy first
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end()); 
        string temp = s + "#" + reverse_s;
        
        vector<int> lps = compute_lps(temp, temp.size());
        
        //return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
        return reverse_s.substr(0, s.size() - lps[temp.size()-1]) + s;
    }
    
    //jump table for lps
    vector<int> compute_lps(string needle, int n) {
        int i = 1, len = 0;
        vector<int> lps(n, 0);
        
        //i is the current pointer, len is lenght of the longest prefix
        while(i < n) {
            if(needle[len] == needle[i]) {
                lps[i] = len+1;
                len++;
                i++;
            } 
            else if (len != 0) {
                //mismatch, reduce length of the mathcing suffix to previous
                //longest matching prefix suffix
                len = lps[len-1];
            }
            else {
                lps[i++] = 0;
            }
        }
        
        return lps;
    }
};