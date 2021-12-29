//https://leetcode.com/problems/implement-strstr/
//KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        //longest prefix suffuix jump table to fasten up the jumps at mismatch
        vector<int> lps = compute_lps(needle, n);
        
        if(n == 0) return 0;
        
        int i = 0, j = 0;
        while (i<m) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if(j == n) 
                return i - n;
            if(i<m && haystack[i] != needle[j]) {
                if(j != 0) {
                    j = lps[j-1];
                }
                else 
                    i++;
            }
        }
        
        return -1;
    }
    
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
        //while(i < n)
    }
};

//Naive

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int l = needle.size();
        
        int answer = 0;
        //if(l == 0) return 0;        
        //if(h < l) return -1;
        
        for(int i = 0; i < h-l+1; i++) {
            answer = i;
            int j = 0;
            for(; j < l; j++) {
                if(haystack[i+j] != needle[j])
                {
                    answer = -1;
                    break;
                }
            }
            if(j == l) return answer;
        }
        return -1;
    }
};